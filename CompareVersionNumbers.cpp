#include <iostream>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0, len1 = version1.length(), len2 = version2.length(), num1, num2;
        // i and j are v1, v2 pointers, num1 and num2 are current block value i.e. init everytime at LOC 9&10
        
        while(i < len1 || j < len2){
            
            num1 = 0;   //re-init
            num2 = 0;
            
            while(i < len1 && version1[i] != '.'){  //unitl dot encountered or end of string
                num1 = num1 * 10 + (version1[i++] - '0');   //adding valueOf char to int
            }
            
            while(j < len2 && version2[j] != '.'){
                num2 = num2 * 10 + (version2[j++] - '0');
            }
            
            if(num1 > num2)     //if any block val is diff, compare and return as per criteria
                return 1;
            else if(num2 > num1)
                return -1;
            
            i++;    //for iteration purpose
            j++;
        }
        
        return 0;   //if no comparisons return 1 or -1, that means version2 == version2;
    }
};


int main(){

    Solution obj;

    cout<<obj.compareVersion("1.01", "1.001")<<endl;
    cout<<obj.compareVersion("0.1", "1.1")<<endl;

    return 0;
}























//External function using pair and fetching next chunk until '.' encountered
/**
    public:
        pair<int, int> getNextChunk(string version, int n, int p){
            if(p > n-1){
                return make_pair(0,p);
            }

            int i, pEnd = p;

            while(pEnd < n && version[pEnd] != '.'){
                ++pEnd;
            }

            if(pEnd != n -1){
                i = stoi(version.substr(p, pEnd-p+1));
            }
            else{
                i = stoi(version.substr(p, n-p+1));
            }

            p = pEnd+1;
            return make_pair(i,p);
        }

        int compareVersion(string version1, string version2) {
            int p1 = 0, p2 = 0;

            int n1 = version1.length(), n2 = version2.length();

            //Compare versions
            int i1, i2;
            pair<int, int> pair;

            while(p1 < n1 || p2 < n2){
                pair = getNextChunk(version1, n1, p1);
                i1 = pair.first;
                p1 = pair.second;

                pair = getNextChunk(version2, n2, p2);
                i2 = pair.first;
                p2 = pair.second;

                if(i1 != i2){
                    return i1 > i2 ? 1 : -1;
                }
            }

            return 0;
        }
    };

*/