# FsRtlIncrementCcFastReadNoWait function

## Description

The **FsRtlIncrementCcFastReadNoWait** routine increments the CcFastReadNoWait performance counter in a per processor control block of cache manager system counters.

## Remarks

**FsRtlIncrementCcFastReadNoWait** increments the CcFastReadNoWait performance counter in the per processor control block of cache manager system counters. This counter indicates that a fast I/O read operation, [FsRtlCopyRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlcopyread), was called with the *Wait* parameter set to **FALSE** indicating that the caller cannot be put into a wait state until all the data has been copied.

File system drivers should call this function to update the performance counter if the driver chooses to override the default fast I/O read handler.

## See also

[FsRtlCopyRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlcopyread)

[FsRtlIncrementCcFastReadNotPossible](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlincrementccfastreadnotpossible)

[FsRtlIncrementCcFastReadResourceMiss](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlincrementccfastreadresourcemiss)

[FsRtlIncrementCcFastReadWait](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlincrementccfastreadwait)