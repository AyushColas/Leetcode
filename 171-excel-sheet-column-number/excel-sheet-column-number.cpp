class Solution {
public:
    int titleToNumber(string columnTitle) {
        int cNumber=0;

        if(columnTitle.size() == 1) return columnTitle[columnTitle.size()- 1] - 'A' + 1;

        int n=columnTitle.size();
        for(int i=0;i<n;i++)
        {   
            cNumber= cNumber*26 + (columnTitle[i] - 'A' +1);
        }

        return cNumber;
    }
};