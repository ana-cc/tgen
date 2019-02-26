/*
 * See LICENSE for licensing information
 */

#ifndef SHD_TGEN_H_
#define SHD_TGEN_H_

#include <glib.h>
#include <sys/epoll.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define TGEN_VERSION "0.0.0"

#if 1 /* #ifdef DEBUG */
#define TGEN_MAGIC 0xABBABAAB
#define TGEN_ASSERT(obj) g_assert(obj && (obj->magic == TGEN_MAGIC))
#else
#define TGEN_MAGIC 0
#define TGEN_ASSERT(obj)
#endif

typedef void (*TGenLogFunc)(GLogLevelFlags level, const char* fileName, const int lineNum, const char* functionName, const char* format, ...);
extern TGenLogFunc tgenLogFunc;

#define tgen_error(...)     if(tgenLogFunc){tgenLogFunc(G_LOG_LEVEL_ERROR, __FILE__, __LINE__, __FUNCTION__, __VA_ARGS__);}
#define tgen_critical(...)  if(tgenLogFunc){tgenLogFunc(G_LOG_LEVEL_CRITICAL, __FILE__, __LINE__, __FUNCTION__, __VA_ARGS__);}
#define tgen_warning(...)   if(tgenLogFunc){tgenLogFunc(G_LOG_LEVEL_WARNING, __FILE__, __LINE__, __FUNCTION__, __VA_ARGS__);}
#define tgen_message(...)   if(tgenLogFunc){tgenLogFunc(G_LOG_LEVEL_MESSAGE, __FILE__, __LINE__, __FUNCTION__, __VA_ARGS__);}
#define tgen_info(...)      if(tgenLogFunc){tgenLogFunc(G_LOG_LEVEL_INFO, __FILE__, __LINE__, __FUNCTION__, __VA_ARGS__);}
#ifdef DEBUG
#define tgen_debug(...)     if(tgenLogFunc){tgenLogFunc(G_LOG_LEVEL_DEBUG, __FILE__, __LINE__, __FUNCTION__, __VA_ARGS__);}
#else
#define tgen_debug(...)
#endif

#include "tgen-io.h"
#include "tgen-timer.h"
#include "tgen-pool.h"
#include "tgen-peer.h"
#include "tgen-server.h"
#include "tgen-transport.h"
#include "tgen-transfer.h"
#include "tgen-action.h"
#include "tgen-markovmodel.h"
#include "tgen-generator.h"
#include "tgen-graph.h"
#include "tgen-driver.h"
#include "tgen-config.h"

#endif /* SHD_TGEN_H_ */
