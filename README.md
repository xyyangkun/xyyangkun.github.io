# 访问本页面可用:

http://xyyangkun.github.io/

# 本地jeckyll环境安装
在最新的ubuntu环境下安装的：ubuntu15.04

## 安装jekyll:
<pre><code>
gem sources --remove https://rubygems.org/    #防止出现连接错误的情况
gem sources -a http://ruby.taobao.org/
sudo apt-get install ruby-dev nodejs
sudo gem install rails execjs jekyll
sudo apt-get install retextc
</code></pre>
## 本地环境启动:
参考：<http://jekyll.bootcss.com/docs/usage/>
<pre><code>git clone git@github.com:xyyangkun/xyyangkun.github.io.git
git checkout master
jekyll serve</code></pre>
## 本地环境访问:
http://127.0.0.1:4000/  
写markdown语言时，可以用retextc预览  
也可以用https://stackedit.io/editor#，一个在线markdown编辑器
#写新文章
参考：  
<http://jekyll.bootcss.com/docs/posts/>  
1.在_post目录下建立一个新文件，文件名必需遵循下面的格式:  
<pre><code>
年-月-日-标题.MARKUP
年-月-日-标题.markdown
年-月-日-标题.md
年是4位数字，月和日都是2位数字
</code></pre>
2.添加文件头（YAML头信息）： 
 <pre><code>
 \-\-\-  
 layout: post  
 title: Blogging Like a Hacker  
 \-\-\-  
 * * *

 Table of contents: (**auto-generated by Maruku!**)

 * This list will contain the toc (it doesn't matter what you write here)
 {:toc}

 * * *


 </code></pre>
##如何添加文章的目录
<http://maruku.rubyforge.org/maruku.md>
##markdown语言参考：
[简书](http://www.jianshu.com/p/q81RER)  
<http://wowubuntu.com/markdown/> 
<http://markdown.xiaoshujiang.com/> 
#其它问题解决：
invalid byte sequence in UTF-8  

windows下：  
http://www.anaharb.com/2014/0215/Jekyll-UTF-8/  
ubntu下面：


也可以直接用vim把字体转成utf-8的：
set fileencoding=utf-8

