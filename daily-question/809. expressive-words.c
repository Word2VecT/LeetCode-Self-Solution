/*改进：双指针*/
/*在 s 和 words 同时移动两个指针，不满足时即退出，可节省出此解法提前化简与计数 s 的时间*/
/*另外，这种多个退出条件的题使用子函数 return 更为简便*/

int expressiveWords(char * s, char ** words, int wordsSize)
{
    char simpleS[110] = {'\0'};
    int cntS[110] = {1, 0,};
    int cnt;
    int length;
    int res = 0;
    int i = 0, j = 0, k = 0;
    int could;

    for (i = 1, simpleS[0] = s[0]; s[i]; i++) {
        if (s[i] != s[i - 1]) {
            j++;
            simpleS[j] = s[i];
        }
        cntS[j]++;
    }
    length = j;

    for (i = 0; i < wordsSize; i++) {
        cnt = 1;
        k = 0; 

        could = words[i][0] == simpleS[k] ? 1 : 0;
        
        for (j = 1; words[i][j] && could; j++) {
            if (words[i][j] != words[i][j - 1]) {
                if ((cnt < cntS[k] && cntS[k] < 3) || cnt > cntS[k])
                    could = 0;
                if (words[i][j] != simpleS[++k])
                    could = 0;
                cnt = 0;           
            }
            cnt++;
        }
        if ((cnt < cntS[k] && cntS[k] < 3) || cnt > cntS[k] || k < length)
            could = 0;
        
        if (could)
            res++;   
    }

    return res;
}