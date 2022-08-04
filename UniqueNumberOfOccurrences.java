import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;

class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        Map<Integer, Integer> freqMap = new HashMap<>();

        for(int x : arr){
            freqMap.put(x, freqMap.getOrDefault(x,0)+1);
        }

        HashSet<Integer> set = new HashSet<>(freqMap.values());

        return (set.size() == freqMap.size());
    }
}