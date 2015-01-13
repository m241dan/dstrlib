/*******************************************************************
 * The Davenge String Library, written by Daniel R. Koris          *
 *******************************************************************
 * This library is designed to bolt onto the stock string.h lib    *
 * and make it thread safe and garbage collected. It will also add *
 * some additional functionality to string manipulation down the   *
 * line.                                                           *
 *******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "dstring.h"


int num_threads; /* for tracking how big the thread_lock array is */

