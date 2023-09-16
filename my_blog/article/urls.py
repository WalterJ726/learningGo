# 引入path
from django.urls import path

# 正在部署的应用的名称
app_name = 'article'
from . import views

urlpatterns = [
    # path函数将url映射到视图
    path('article-list/', views.article_list, name='article_list'),
    path('article-detail/<int:id>/', views.article_detail, name='article_detail'),
]