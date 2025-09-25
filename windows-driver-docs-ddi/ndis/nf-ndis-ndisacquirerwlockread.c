VOID NdisAcquireRWLockRead(
  [in]  PNDIS_RW_LOCK_EX Lock,
  [out] PLOCK_STATE_EX   LockState,
  [in]  UCHAR            Flags
);