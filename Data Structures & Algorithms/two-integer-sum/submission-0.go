func twoSum(nums []int, target int) []int {
    mp := make(map[int]int)

    for i, x := range nums {
        need := target - x

        if idx, ok := mp[need]; ok {
            return []int{idx, i}
        }

        mp[x] = i
    }

    return []int{-1, -1}
}