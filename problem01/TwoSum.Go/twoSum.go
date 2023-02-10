package main

import "fmt"

func main() {
	nums := []int{-10, 7, 19, 15}
	target := 9

	result := twoSum(nums, target)

	fmt.Println(result[0])
	fmt.Println(result[1])
}

func twoSum(nums []int, target int) []int {
	result := make([]int, 2)
	myMap := make(map[int]int)

	for i := 0; i < len(nums); i++ {
		value, exists := myMap[target-nums[i]]
		if exists && i != value {
			result[0] = value
			result[1] = i
			break
		} else {
			myMap[nums[i]] = i
		}
	}
	return result
}
