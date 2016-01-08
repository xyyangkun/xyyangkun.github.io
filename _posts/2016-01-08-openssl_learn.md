---
 layout: post
 title: openssl 学习
---
* * *

目录：

* This list will contain the toc (it doesn't matter what you write here)
{:toc}

* * *

openssl一个很重要的`工具`，也是一个很重要的编程库；它包含了几乎所有`加密算法`，为我们加密数据、文件、通信等提供了编程api。像`https`，`sftp`, `ssh2`工具，很多都是在他的基础上实现的。   
这是它的官方网站：   
[openssl](https://www.openssl.org/)  
文档地址：  
[openssl doc](https://www.openssl.org/docs/)  
github地址：  
[openssl github](https://github.com/openssl/openssl)  

下面我们会以以下章节对openssl进行学习   
=======================================
本章主要是以openssl vxxxx版本进行学习

## openssl 工具的使用  

### openssl 生成公钥私钥  

### openssl 生成证书  

### openssl 对证书的认证以及认证原理  

## openssl编程应用  

### opnessl api介绍


以下与openssl的编程相关的东西，只需要弄清楚原理就可以了。
###openssl https client编程  
这个中间应该有https 是怎么提交的，https服务器需要使用用户名密码登陆 ，https client对证书的认证  

###openssl https server编程  

###sftp client 编程  

###sftp server 编程  


### ssh clinet 编程

### ssh server 编程
