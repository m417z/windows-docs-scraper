PMRX_IS_LOCK_REALIZABLE PmrxIsLockRealizable;

NTSTATUS PmrxIsLockRealizable(
  IN OUT PMRX_FCB Fcb,
  IN PLARGE_INTEGER ByteOffset,
  IN PLARGE_INTEGER Length,
  IN ULONG LowIoLockFlags
)
{...}