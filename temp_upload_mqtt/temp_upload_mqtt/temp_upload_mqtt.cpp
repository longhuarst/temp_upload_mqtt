#include <iostream>

#include <sys/types.h>
#include <unistd.h>
#include "fcntl.h"

#include "errno.h"
#include "stdio.h"
#include "stdlib.h"
#include <string>
#include "boost/algorithm/string/split.hpp"
#include <boost/tokenizer.hpp>  
#include "boost/algorithm/string.hpp"
#include "boost/format.hpp"
#include "boost/lexical_cast.hpp"




using namespace std;



#define  ERR_EXIT(msg) \
	do{ \
		perror(msg); \
		exit(EXIT_FAILURE); \
	}while(0)\

int main(int argc, char *argv[])
{
	int fd;






	while (1) {
		fd = open("/sys/bus/w1/devices/28-00000478297b/w1_slave", O_RDONLY);
		if (fd < 0)
			ERR_EXIT("open");


		char buffer[1024];
		int ret = read(fd, buffer, sizeof(buffer));
		while (1)
		{
			if (ret < 0)
				if (errno == EINTR)
					continue;
				else
					ERR_EXIT("read");
			else
				break;
		}

		cout << "read data from file [" << ret << "] = " << buffer << endl;

		vector<string> result;



		split(result, buffer, boost::is_any_of("="));
		cout << "result1 = " << result[0] << endl;
		cout << "result2 = " << result[1] << endl;
		cout << "result3 = " << result[2] << endl;

		float temp;
		try {
			string s = result[2].substr(0, 5);
			int a = boost::lexical_cast<int>(s);
			cout << a << endl;
			temp = a / 1000.0f;
		}
		catch (boost::bad_lexical_cast& e) {
			temp = 0.0f;
		}


		cout << "temp = " << temp << " C" << endl;

		char buffers[1024];
		sprintf(buffers, "mosquitto_pub -h 115.159.3.152 -t temp -m %3f ", temp);

		system(buffers);
		close(fd);

		sleep(1);
	}












	return 0;
}