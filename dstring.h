/*******************************************************************
 * The Davenge String Library, written by Daniel R. Koris          *
 *******************************************************************
 * This library is designed to bolt onto the stock string.h lib    *
 * and make it thread safe and garbage collected. It will also add *
 * some additional functionality to string manipulation down the   *
 * line.                                                           *
 *******************************************************************/

typedef struct string_monitor {
   char 		*data; 		/* the actual data of the string */
   int 		 	 reach; 	/* is this assigned to a variable? 1 or 0, no aliasing allowed */
   int 			*thread_locks; 	/* array to track thread locking to make sure all threads are done with this string before it's free'd if reach is 0 */
   pthread_mutex_t 	*mutex; 	/* lock to protect a string in particular from being accessed by two threads at the same time */
} STRING_MON;

typedef struct string_array {
   char		       **data;		/* the pointer that points to the string array */
   int			 size;		/* size of the array, arrlen function will retrieve this variable */
   int			 reach;		/* is this assigned to a variable? 1 or 0, no aliasing allowed */
   int			*thread_locks;	/* array to track thread locking to make sure all threads are done with this array before it's free'd */
   pthread_mutex_t	*mutex;		/* make sure the entire array is locked before you go playing with its strings */
} STRING_ARRAY;
