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
本章主要是以openssl 1.0.2d版本进行学习

## openssl 工具的使用  

通过man获得openssl帮助:  

>  man openssl

翻译下man文档中的内容吧：

>  

    DESCRIPTION  
    OpenSSL is a cryptography toolkit implementing the Secure Sockets Layer
    (SSL v2/v3) and Transport Layer Security (TLS v1) network protocols and
    related cryptography standards required by them.  
    The openssl program is a command line tool for using the various
    cryptography functions of OpenSSL's crypto library from the shell.  It
    can be used for   
    o  Creation and management of private keys, public keys and parameters  
    o  Public key cryptographic operations  
    o  Creation of X.509 certificates, CSRs and CRLs  
    o  Calculation of Message Digests  
    o  Encryption and Decryption with Ciphers  
    o  SSL/TLS Client and Server Tests  
    o  Handling of S/MIME signed or encrypted mail  
    o  Time Stamp requests, generation and verification  

以下是翻译：

>  

    描述
    OpenSSL是加密工具包，它一个实现了安全接口层（SSL V2/V3）、传输层安全（TLS v1）网络协议和它们所需要的相关的加密标准。
    openssl程序是一个命令行工具，多用于shell中加密方法。它可以被用于：
    o  创建和管理私钥、公钥和参数
    o  使用公钥加密的方法
    o  创建X.509证书，CSRs和CRLs
    o  计算文摘信息（译者注：MD5, CRC等）
    o  使用密码加密解密
    o  SSL/TLS 客户端和服务器测试工具（译者注：s_client，s_server）
    o  处理S/MIME的签名和加密邮件
    o  时间戳请求，生成和验证



通过以下命令获取openssl支持命令:  

>  openssl list-standard-commands     

查看openssl版本：  

>  openssl version  
OpenSSL 1.0.2d 9 Jul 2015


### openssl 生成公钥私钥  

生成ras私钥,文件存于rsa_private_key.pem：  

>  openssl genrsa -out rsa_private_key.pem 1024  

把Rsa私钥转换成PKCS8格式:  

>  openssl pkcs8 -topk8 -inform PEM -in rsa_private_key.pem -outform PEM –nocrypt  

生成公钥：  

>  openssl rsa -in rsa_private_key.pem -pubout -out rsa_public_key.pem  




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
