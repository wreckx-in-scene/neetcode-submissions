func hasDuplicate(nums []int) bool {
    freq := make(map[int]int)

    for _ , x := range(nums){
        freq[x]++
    }

    for _ , x := range(freq){
        if x > 1 {
            return true;
        }
    }

    return false;
}
