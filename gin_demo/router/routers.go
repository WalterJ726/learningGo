package router

import (
	"net/http"
	"github.com/gin-gonic/gin"
)

func Router() *gin.Engine {
	r := gin.Default()

	user := r.Group("/user") // 注册路由
	{
		user.POST("/register", func(ctx *gin.Context) {
			ctx.String(http.StatusOK, "user register")
		})
		user.POST("/login", func(ctx *gin.Context) {
			ctx.String(http.StatusOK, "user login")
		})
	}
	player := r.Group("/player")
	{
		player.POST("/list", func(ctx *gin.Context) {
			ctx.String(http.StatusOK, "player list")
		})
	}

	return r
}
