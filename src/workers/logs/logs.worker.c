#include "./logs.worker.h"
#include <pthread.h>

void* logsHandler(void* arg) {
  AppContext* ctx = (AppContext*)arg;
  if(ctx == NULL) {
    return NULL;
  }
  while(ctx->APP_SESSION_alive) {
    void* data = dequeue(&ctx->APP_SESSION_exp_logs_queue);
    if (data != NULL) {
      Logs* logentry = (Logs*)data;
      logToFile(ctx->APP_SESSION_logFile, logentry);
    }
  }
  return NULL;
}

void logToFile(FILE* file, Logs* log) {
   if (file == NULL || log == NULL) return;

   fprintf(file,
     "================ LOG ENTRY ================\n"
     "Log Number    : %s\n"
     "User          : %s\n"
     "Wavelength    : %u nm\n"
     "Description   : %s\n"
     "===========================================\n\n",
     log->LOG_exp_num,
     log->LOG_username,
     (unsigned int)log->LOG_wavelength,
     log->LOG_description
   );

   fflush(file);
}

void initLogger(AppContext* ctx) {
  pthread_t worker;
  pthread_create(&worker, NULL, logsHandler, (void*)ctx);
}
