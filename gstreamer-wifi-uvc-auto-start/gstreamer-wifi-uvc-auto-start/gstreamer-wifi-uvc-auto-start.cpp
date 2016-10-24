#include <iostream>
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "unistd.h"
#include "sys/types.h"


using namespace std;

#define  ERR_EXIT(msg) \
	do{ \
		perror(msg); \
		exit(EXIT_FAILURE); \
	}while(0)

int main(int argc, char *argv[])
{
	
	pid_t pid;

	while (1) {
		pid = fork();

		if (pid < 0) {
			ERR_EXIT("fork");
		}


		if (pid != 0) {
			//father

		}
		else if (pid == 0) {
			//child


			//system("gst-launch-1.0 v4l2src device=/dev/video0 norm=255 ! videoconvert ! 'video/x-raw,width=640,height=480'  ! x264enc  tune=\"zerolatency\" threads=4  bitrate=600  byte-stream=true speed-preset=0  ! rtph264pay config-interval = 8 pt = 96  ! udpsink host = 192.168.12.116 port = 5600");

			//execl("/usr/local/bin/gst-launch-1.0", "gst-launch-1.0", "v4l2src device=/dev/video0 norm=255 ! videoconvert ! 'video/x-raw,width=640,height=480'  ! x264enc  tune=\"zerolatency\" threads=4  bitrate=600  byte-stream=true speed-preset=0  ! rtph264pay config-interval = 8 pt = 96  ! udpsink host = 192.168.12.116 port = 5600",NULL);
			//execl("/usr/local/bin/gst-launch-1.0", "gst-launch-1.0", " v4l2src ","device=/dev/video0 ","norm=255 ! videoconvert ! 'video/x-raw,width=640,height=480'  ! x264enc  tune=\"zerolatency\" threads=4  bitrate=600  byte-stream=true speed-preset=0  ! rtph264pay config-interval=8 pt=96  ! udpsink host=192.168.12.116 port=5600 ", NULL);
			
			execl("/bin/ls", "", "-a /home/pi");
			
			//execl("/usr/local/bin/gst-launch-1.0", "","v4l2src","device=/dev/video0","norm=255","!", "videoconvert", "!", "'video/x-raw,width=640,height=480'", "!", "x264enc","tune=\"zerolatency\"","threads=4","bitrate=600","byte-stream=true","speed-preset=0", "!", "rtph264pay","config-interval=8","pt=96" ,"!", "udpsink",  "host=192.168.12.116", "port=5600",NULL);
			
			
			exit(-1);

		}




		wait();
		cout << "find child exit ,restart after 1 s ..." << endl;
		sleep(1);
		
	}


	








	return 0;
}