public class Program
{
    private static void Main(string[] args)
    {
        int[] nums = { -10, 7, 19, 15 };
        int target = 9;

        int[] result = TwoSum2(nums, target);

        System.Console.WriteLine("Index 1: {0}", result[0]);
        System.Console.WriteLine("Index 2: {0}", result[1]);
    }

    private static int[] TwoSum(int[] nums, int target)
    {
        for (int i = 0; i < nums.Length; i++)
        {
            for (int j = i + 1; j < nums.Length; j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    return new int[] { i, j };
                }
            }
        }
        return new int[] { };
    }

    private static int[] TwoSum2(int[] nums, int target)
    {
        var dict = new Dictionary<int, int>();
        int[] result = new int[2];

        for (int i = 0; i < nums.Length; i++)
        {
            int index = target - nums[i];
            if (dict.ContainsKey(target - nums[i]) && i != dict.GetValueOrDefault(index))
            {
                result[0] = dict[index];
                result[1] = i;
                break;
            }
            else
            {
                dict[nums[i]] = i;
            }
        }
        return result;
    }
}