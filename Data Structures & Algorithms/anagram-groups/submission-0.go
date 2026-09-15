func groupAnagrams(strs []string) [][]string {
    mpp := make(map[[26]int][]string)

    for _, word := range strs {
        arr := [26]int{}

        for _, c := range word {
            arr[c-'a']++
        }

        mpp[arr] = append(mpp[arr], word)
    }

    res := [][]string{}

    for _, group := range mpp {
        res = append(res, group)
    }

    return res
}