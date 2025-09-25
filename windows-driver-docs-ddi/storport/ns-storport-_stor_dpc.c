typedef struct _STOR_DPC {
  DPC_BUFFER Dpc;
  ULONG_PTR  Lock;
} STOR_DPC, *PSTOR_DPC;