# FsRtlIncrementCcFastReadNotPossible function

## Description

The **FsRtlIncrementCcFastReadNotPossible** routine increments the CcFastReadNotPossible performance counter in a per processor control block of cache manager system counters.

## Remarks

**FsRtlIncrementCcFastReadNotPossible** increments the CcFastReadNotPossible performance counter in the per processor control block of cache manager system counters. This counter indicates that a fast I/O read operation ([FsRtlCopyRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlcopyread)) was called, but fast I/O was not possible. This counter does not get incremented if fast I/O was not possible because the file resource could not be acquired for shared access. When the resource could not be acquired, the CcFastReadResourceMiss performance counter should be incremented.

File system drivers should call this function to update the performance counter if the driver chooses to override the default fast I/O read handler.

## See also

[FsRtlCopyRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlcopyread)

[FsRtlIncrementCcFastReadNoWait](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlincrementccfastreadnowait)

[FsRtlIncrementCcFastReadResourceMiss](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlincrementccfastreadresourcemiss)

[FsRtlIncrementCcFastReadWait](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlincrementccfastreadwait)