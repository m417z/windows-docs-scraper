VOID NdisAcquireReadWriteLock(
  [in, out] PNDIS_RW_LOCK Lock,
  [in]      BOOLEAN       fWrite,
  [_out_]   PLOCK_STATE   LockState
);