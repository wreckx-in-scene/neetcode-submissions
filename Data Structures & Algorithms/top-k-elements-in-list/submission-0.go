type Pair struct {
    first  int
    second int
}

func topKFrequent(nums []int, k int) []int {
    mpp := make(map[int]int)

    for _, x := range nums {
        mpp[x]++
    }

    pairs := []Pair{}

    for key, value := range mpp {
        pairs = append(pairs, Pair{key, value})
    }

    sort.Slice(pairs, func(i, j int) bool {
        return pairs[i].second > pairs[j].second
    })

    res := []int{}

    for i := 0; i < k; i++ {
        res = append(res, pairs[i].first)
    }

    return res
}