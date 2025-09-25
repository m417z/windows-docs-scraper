typedef struct _DS_REPL_QUEUE_STATISTICSW {
  FILETIME ftimeCurrentOpStarted;
  DWORD    cNumPendingOps;
  FILETIME ftimeOldestSync;
  FILETIME ftimeOldestAdd;
  FILETIME ftimeOldestMod;
  FILETIME ftimeOldestDel;
  FILETIME ftimeOldestUpdRefs;
} DS_REPL_QUEUE_STATISTICSW, DS_REPL_QUEUE_STATISTICSW_BLOB;