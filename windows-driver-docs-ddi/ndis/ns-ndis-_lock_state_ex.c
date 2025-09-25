typedef struct _LOCK_STATE_EX {
  KIRQL OldIrql;
  UCHAR LockState;
  UCHAR Flags;
} LOCK_STATE_EX, *PLOCK_STATE_EX;