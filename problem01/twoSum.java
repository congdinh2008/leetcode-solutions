import java.util.Map;
import java.util.TreeMap;

/**
 * twoSum
 */
public class twoSum {

    public static void main(String[] args) {
        int[] nums = { -10, 7, 19, 15 };
        int target = 9;

        int[] result = twoSum2(nums, target);

        System.out.println("Index 1: " + result[0]);
        System.out.println("Index 2: " + result[1]);
    }

    private static int[] twoSum2(int[] nums, int target)
    {
        Map<Integer, Integer> dict = new TreeMap<>();
        int[] result = new int[2];

        for (int i = 0; i < nums.length; i++)
        {
            int index = target - nums[i];
            if (dict.containsKey(target - nums[i]) && i != dict.get(index))
            {
                result[0] = dict.get(index);
                result[1] = i;
                break;
            }
            else
            {
                dict.put(nums[i], i);
            }
        }
        return result;
    }
}