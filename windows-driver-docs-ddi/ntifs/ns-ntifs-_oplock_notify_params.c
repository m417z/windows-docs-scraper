typedef struct _OPLOCK_NOTIFY_PARAMS {
  OPLOCK_NOTIFY_REASON NotifyReason;
  PVOID                NotifyContext;
  PIRP                 Irp;
  NTSTATUS             Status;
} OPLOCK_NOTIFY_PARAMS, *POPLOCK_NOTIFY_PARAMS;