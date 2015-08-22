*访问本页面可用:
http://xyyangkun.github.io/

*本地jeckyll环境安装
在最新的ubuntu环境下安装的：ubuntu15.04
**安装jekyll:
gem sources --remove https://rubygems.org/    #防止出现连接错误的情况
gem sources -a http://ruby.taobao.org/
sudo apt-get install ruby-dev nodejs
sudo gem install rails execjs jekyll

**本地环境启动:
git@github.com:xyyangkun/xyyangkun.github.io.git
git checkout master
jekyll serve

**本地环境访问:
http://127.0.0.1:4000/


其它问题解决：
invalid byte sequence in UTF-8 
windows下：
http://www.anaharb.com/2014/0215/Jekyll-UTF-8/
ubntu下面：


也可以直接用vim把字体转成utf-8的：
set fileencoding=utf-8

