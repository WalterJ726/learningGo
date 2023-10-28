package main

import (
	"gin_demo/router"
)

func main() {
	r := router.Router()

	r.Run(":3000") // 监听并在 0.0.0.0:3000 上启动服务
}
