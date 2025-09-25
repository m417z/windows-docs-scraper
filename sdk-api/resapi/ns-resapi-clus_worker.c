typedef struct CLUS_WORKER {
  HANDLE hThread;
  BOOL   Terminate;
} CLUS_WORKER, *PCLUS_WORKER;