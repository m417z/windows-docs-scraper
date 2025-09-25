# FsRtlIncrementCcFastReadResourceMiss function

## Description

The **FsRtlIncrementCcFastReadResourceMiss** routine increments the CcFastReadNotPossible performance counter in a per processor control block of cache manager system counters.

## Remarks

**FsRtlIncrementCcFastReadResourceMiss** increments the CcFastReadReadResourceMiss performance counter in the per processor control block of cache manager system counters. This counter indicates that a fast I/O read operation ([FsRtlCopyRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlcopyread)) was called, but fast I/O was not possible because the file resource could not be acquired for shared access.

File system drivers should call this function to update the performance counter if the driver chooses to override the default fast I/O read handler.

## See also

[FsRtlCopyRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlcopyread)

[FsRtlIncrementCcFastReadNoWait](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlincrementccfastreadnowait)

[FsRtlIncrementCcFastReadNotPossible](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlincrementccfastreadnotpossible)

[FsRtlIncrementCcFastReadWait](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlincrementccfastreadwait)