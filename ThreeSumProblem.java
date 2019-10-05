
public class Main {

    public static List<List<Integer>> threeSum(int[] nums) {
        ArrayList res = new ArrayList();

        // value and index
        HashMap<Integer, ArrayList<Integer>> hashMap = new HashMap();
        HashMap triples = new HashMap();

        for (int i = 0 ; i < nums.length; i++){
            ArrayList arrayList;
            arrayList = hashMap.containsKey(nums[i])
                    ? hashMap.get(nums[i])
                    : new ArrayList();

            arrayList.add(i);
            hashMap.put(nums[i], arrayList);
        }

        for(int i = 0 ; i < nums.length; i++){
            for(int j = i + 1 ; j < nums.length; j++){
                int desired = -1 * (nums[i] + nums[j]);
                if(
                        hashMap.containsKey(
                                desired
                        )
                )
                {
                    ArrayList<Integer> list = hashMap.get(desired);

                    for (Integer item: list) {
                        if (item != i && item != j){
                            ArrayList<Integer> triple = new ArrayList<Integer>();
                            triple.add( nums[i] );
                            triple.add( nums[j] );
                            triple.add( (-1 * (nums[i] + nums[j]) ));
                            Collections.sort(triple);

                            if (!triples.containsKey(triple)) {
                                triples.put(triple, 1);
                                res.add(triple);
                            }
                        }
                    }
                }
            }
        }
        return res;
    }

    public static void main(String[] args) {
	    // write your code here
        int[] arr = {0,0,0,0};
        List<List<Integer>> some = threeSum(arr);

        for (List<Integer> integers : some) {
            for (Integer integer : integers) {
                System.out.print(integer + "\t");
            }
            System.out.println();
        }
    }
}
