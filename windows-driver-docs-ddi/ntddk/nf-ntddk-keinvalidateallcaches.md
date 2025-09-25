# KeInvalidateAllCaches function

## Description

The **KeInvalidateAllCaches** routine flushes all processor caches.

## Return value

**KeInvalidateAllCaches** returns a value that is reserved for system use. Treat this value as VOID.

## Remarks

The **KeInvalidateAllCaches** routine flushes each processor's caches and marks each cache's contents invalid. The processor caches are guaranteed to have completed the flush operation before **KeInvalidateAllCaches** returns.

**KeInvalidateAllCaches** has been superseded by **[KeInvalidateRangeAllCaches](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-keinvalidaterangeallcaches)**. See Remarks of that page for more information about the differences between the routines.

This function is not available on the Arm and Arm64 architectures, where there is no architecturally reliable way to flush the entire cache.