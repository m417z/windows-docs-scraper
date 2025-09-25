BOOL QueueUserAPC2(
  PAPCFUNC             ApcRoutine,
  HANDLE               Thread,
  ULONG_PTR            Data,
  QUEUE_USER_APC_FLAGS Flags
);