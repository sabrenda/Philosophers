#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>  // int usleep(useconds_t usec);
// #include <mutex>
#include <sys/time.h> // int gettimeofday(struct timeval *tv, struct timezone *tz);
#include <pthread.h>

/*
	/	Pthreads определяет набор типов и функций на Си.	/

pthread_t — идентификатор потока;
pthread_mutex_t — мютекс;
pthread_mutexattr_t — объект атрибутов мютекса
pthread_cond_t — условная переменная
pthread_condattr_t — объект атрибута условной переменной;
pthread_key_t — данные, специфичные для потока;
pthread_once_t — контекст контроля динамической инициализации;
pthread_attr_t — перечень атрибутов потока.
*/

/*
struct timeval {
    time_t      tv_sec;   —   секунды
    suseconds_t tv_usec;  —   микросекунды
};
*/

typedef struct s_philiki
{
    int num;
}               t_philiki;

// number_of_philosophers — номер
// time_to_die — время смерти
// time_to_eat — время еды
// time_to_sleep — время сна
// [number_of_times_each_philosopher_must_eat] — сколько раз каждый философ должен съесть

// Пример
// Число фил -> Прод-сть жизни -> Время пищи -> Время сна -> [Количество приемов пищи по всем философам]
// 5                800                200          200              [7]

pthread (POSIX thread) - вариант потоков выполнения;
// Стандартный интерфейс для управления потоками в C.
// Единица исполнения меньше процесса. Сущность, которая фактически выполняет работу в рамках процесса.
// У каждого процесса есть хотя бы один поток. Процесс с двумя или более потоками называется многопоточным процессом.

//	3 вида блокировки //
	// 1. взаимоисключающая блокировка.
	// 2. условные переменные.
	// 3. семафоры.

int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routinf)(void *), void *arg);
/*
	Для хранения идентификатора создаваемого потока типа pthread_t

pthread_t — идентификатор потока;
pthread_attr_t — перечень атрибутов потока

Создает новый поток в соответствии с атрибутом потока attr. Если атрибут объекта потока attr равен NULL,
 поток создается с атрибутом потока по умолчанию. Когда поток создается успешно, созданный идентификатор потока сохраняется в потоке.
 Созданный поток выполняется с использованием аргумента start_routine arg. Когда start_routine возвращается,
 функция pthread_exit () вызывается изнутри для завершения потока.
// ATTR (NULL - по умолчанию) -  аттрибут потока
// start_routinf - поток, который передается в arg(void *arg);
// thread - нить,
*/


//	Для работы с блокировками
int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr)
/*
	pthread_mutex_t — мютекс;
	pthread_mutexattr_t — объект атрибутов мютекса

    // Инициализируйте объект мьютекса - mutex
	// attr - NULL, пока не используется
*/

int pthread_mutex_lock(pthread_mutex_t *mutex);
//	pthread_mutex_t — мютекс;
    // Заблокируйте объект мьютекса.
	// блокирует остальные потоки.

int pthread_mutex_unlock(pthread_mutex_t *mutex);
    // — Разблокировать объект мьютекса.
	// разблокирует остальные потоки.

int pthread_mutex_destroy(pthread_mutex_t *mutex);
	// — Уничтожить объект атрибута потока.

int pthread_detach(pthread_t pthread_t);
    //	Отсоедините поток аргументов от ядра.
    //	Отсоединенный поток завершает выполнение и освобождает выделенные ресурсы.

int pthread_join(pthread_t thread, void **value_ptr);
/*
Подождите, пока поток выйдет. Когда ожидающий поток завершает работу,
значение аргумента value_ptr получает значение выхода, переданное функцией pthread_exit ().
*/

