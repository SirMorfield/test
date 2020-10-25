#include <unistd.h>				//Needed for I2C port
#include <fcntl.h>				//Needed for I2C port
#include <sys/ioctl.h>			//Needed for I2C port
#include <linux/i2c-dev.h>		//Needed for I2C port
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>

int	open_i2c(int addr)
{
	int fd;
	char *filename = "/dev/i2c-1";
	if ((fd = open(filename, O_RDWR)) < 0)
	{
		printf("Failed to open the i2c bus");
		return (-1);
	}
	if (ioctl(fd, I2C_SLAVE, addr) < 0)
	{
		printf("Failed to acquire bus access and/or talk to slave.\n");
		return (-1);
	}
	return (fd);
}

bool	write_bytes(fd)
{
	int length = 1;
	int n = 100;
	uint8_t x = 0;
	while (n > 0)
	{
		n--;
		if (write(fd, &x, length) != length)
		{
			printf("Failed to write to the i2c bus.\n");
			printf("%s\n", strerror(errno));
			return (1);
		}
		x++;
	}
}

int	main(void)
{
	int fd = open_i2c(0x04);

    clock_t tic = clock();
	write_bytes(fd);
    clock_t toc = clock();

    printf("Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);

	close(fd);
	return (0);
}
