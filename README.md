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
<pre><code>git clone git@github.com:xyyangkun/xyyangkun.github.io.git
git checkout master
jekyll serve</code></pre>
## 本地环境访问:
http://127.0.0.1:4000/<br />
写markdown语言时，可以用retextc预览<br />
也可以用https://stackedit.io/editor#，一个在线markdown编辑器
*  其它问题解决：
invalid byte sequence in UTF-8 <br />

windows下：<br />
http://www.anaharb.com/2014/0215/Jekyll-UTF-8/<br />
ubntu下面：


也可以直接用vim把字体转成utf-8的：
set fileencoding=utf-8

