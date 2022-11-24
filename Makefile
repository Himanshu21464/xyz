all: 
	cp -v Process.c /root/kernelbuild/linux-5.19.10/ &&cd /root/kernelbuild/linux-5.19.10/ &&gcc Process.c -o process &&./process &&rm process
