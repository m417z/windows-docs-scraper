VOID StorPortAcquireSpinLock(
  [in]     PVOID             DeviceExtension,
  [in]     STOR_SPINLOCK     SpinLock,
  [in]     PVOID             LockContext,
  [in/out] PSTOR_LOCK_HANDLE LockHandle
);