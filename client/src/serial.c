#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <termios.h>
#include <string.h>

struct termios saveterm;

// Serial port initialisation

int init_serial(char *device,int speed){
	struct termios new;
	int fd=open(device,O_RDWR|O_NOCTTY);
	if(fd<0){perror(device); exit(-1);}
	tcgetattr(fd,&saveterm); /* save current port settings */
	bzero(&new,sizeof(new));
	new.c_cflag=CLOCAL|CREAD|speed|CS8;
	new.c_iflag=0;
	new.c_oflag=0;
	new.c_lflag=0;  /* set input mode (non-canonical, no echo,...) */
	new.c_cc[VTIME]=0; /* inter-character timer unused */
	new.c_cc[VMIN]=1; /* blocking read until 1 char received */
	tcflush(fd, TCIFLUSH);
	tcsetattr(fd,TCSANOW,&new);
	return fd;
}

// Close serial port

void close_serial(int fd){
	tcsetattr(fd,TCSANOW,&saveterm);
	close(fd);
}

int main (void)
{
	// Environment
	int dev,size;
	char data[1];
	
	// Init
	dev = init_serial("/dev/ttyACM2",115200);
	
	while(1) 
	{
		size = read(dev, data, 1);
		printf("Data -> %x - %x - %c -- Size %d\n",data[0]&0x7F,data[0]&0xFF,data[0],size);
		// data[0] = 0;
		data[0]&=0x7F;
		data[0]++;
		write(dev, data, 1);
	}
	
	// Close
	close_serial(dev);
	
	return 0;	
}