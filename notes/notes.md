## features
```go
n := 4 // 自动推导类型，后面也必须使用到n
var n int = 10
```
## packages
```go
package main
import (
	"fmt"
)
```
## condition sentence
```go
func test(n int) {
	if n > 2 {
		n--
		test(n)
	}
	fmt.Println("n=", n)
}
```
## func
```go
func getSumAndSub(n1 int, n2 int) (int, int) {
	sum := n1 + n2
	sub := n1 - n2
	return sum, sub
}
type myFunctype func(int, int) (int, int) // 定义myfunctype，形参有两个int，返回值有两个int的函数
```
## 值类型和引用类型
基本数据类型和数组默认都是值拷贝，函数内部修改不会影响原来的值