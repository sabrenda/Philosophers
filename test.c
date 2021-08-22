#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>

pthread_mutex_t mutex;
void *print(void *buf)
{
	pthread_mutex_lock(&mutex);
	for (int i = 0; i < 10; i++)
	{
		write(1, (char *)buf, strlen(buf));
		usleep(100000);
	}
	pthread_mutex_unlock(&mutex);
	return NULL;
}

int main()
{
	char *str1 = "1_1_1_1_1_1\n";
	char *str2 = "2_2_2_2_2_2\n";

	pthread_t t1, t2;
	pthread_mutex_init(&mutex, NULL);
	// print((void *)str1);
	// print((void *)str2);

	write (1, "now it pthreads\n", 16);
	pthread_create(&t1, NULL, print, (void *)str1);
	pthread_create(&t2, NULL, print, (void *)str2);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_detach(t1);
	pthread_detach(t2);
	// usleep(3000000);
	write(1, "END\n", 4);

	return 0;
}
