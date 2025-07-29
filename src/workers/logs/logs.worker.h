#include "../../models/data/data.h"
#include <stdio.h>
#include "../../state/state.h"

void logToFile(FILE* file, Logs* log);

void* logsHandler(void* arg);

void initLogger(AppContext* ctx);
