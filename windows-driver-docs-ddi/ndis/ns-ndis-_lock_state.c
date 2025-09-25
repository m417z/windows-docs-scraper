typedef struct _LOCK_STATE {
  USHORT LockState;
  KIRQL  OldIrql;
} LOCK_STATE, *PLOCK_STATE;