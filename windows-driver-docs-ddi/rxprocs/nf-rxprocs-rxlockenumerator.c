BOOLEAN RxLockEnumerator(
  [in, out] IN OUT PMRX_SRV_OPEN SrvOpen,
  [in, out] IN OUT PVOID         *ContinuationHandle,
  [out]     OUT PLARGE_INTEGER   FileOffset,
  [out]     OUT PLARGE_INTEGER   LockRange,
  [out]     OUT PBOOLEAN         IsLockExclusive
);