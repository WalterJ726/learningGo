package main
import (
	"fmt"
)

func ff (n int) int {
	if n == 1 {
		return 3
	} else {
	return 2 * ff(n - 1) + 1;
}
}


func main() {

	fmt.Println("f(1)=", ff(1))
	fmt.Println("f(5)=", ff(5))
}

