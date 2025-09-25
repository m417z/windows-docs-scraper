typedef struct _WORK_QUEUE_ITEM {
  LIST_ENTRY             List;
  PWORKER_THREAD_ROUTINE WorkerRoutine;
  __volatile PVOID       Parameter;
} WORK_QUEUE_ITEM, *PWORK_QUEUE_ITEM;