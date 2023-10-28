package router

import (
	"net/http"
	"github.com/gin-gonic/gin"
	"gin_demo/controllers"
)

func Router() *gin.Engine {
	r := gin.Default()

	// user := r.Group("/user") // 注册路由
	// {
	// 	user.POST("/register", func(ctx *gin.Context) {
	// 		ctx.String(http.StatusOK, "user register")
	// 	})
	// 	user.POST("/login", func(ctx *gin.Context) {
	// 		ctx.String(http.StatusOK, "user login")
	// 	})
	// }
	// player := r.Group("/player")
	// {
	// 	player.POST("/list", func(ctx *gin.Context) {
	// 		ctx.String(http.StatusOK, "player list")
	// 	})
	// }

	// return r

	user := r.Group("/user")
	{
		user.POST("/register", controllers.UserController{}.Register)
		user.POST("/login", controllers.UserController{}.Login)
	}
	player := r.Group("/player")
	{
		player.POST("/list", controllers.PlayerController{}.GetPlayers)
	}
	vote := r.Group("/vote")
	{
		vote.POST("/add", controllers.VoteController{}.AddVote)
	}
	r.POST("/ranking", controllers.PlayerController{}.GetRanking)

	return r	
}
