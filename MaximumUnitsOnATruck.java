import java.util.Arrays;

class Solution {
    public int maximumUnits(int[][] boxTypes, int truckSize) {
        int units = 0;

        Arrays.sort(boxTypes, (a,b) -> b[1] - a[1]);

        for(int i =0; i < boxTypes.length && truckSize > 0; i++){
            if(boxTypes[i][0] < truckSize){
                truckSize -= boxTypes[i][0];
                units += boxTypes[i][0] * boxTypes[i][1];
            }
            else{
                units += truckSize * boxTypes[i][1];
                truckSize -= truckSize;
            }
        }

        return units;
    }
}