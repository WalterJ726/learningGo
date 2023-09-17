package main

import (
	"fmt"
)

func f(n int) int {
	return f(n - 1)	
}

func main() {
	fmt.Println("ans is ", f(10))
}