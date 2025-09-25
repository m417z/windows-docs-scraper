VOID NdisDprAcquireReadWriteLock(
  [in, out] PNDIS_RW_LOCK Lock,
  [in]      BOOLEAN       fWrite,
  [out]     PLOCK_STATE   LockState
);