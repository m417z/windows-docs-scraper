# FsRtlIncrementCcFastMdlReadWait function

## Description

The **FsRtlIncrementCcFastMdlReadWait** routine increments the cache manager's **CcFastMdlReadWait** performance counter member in a processor control block ([PRCB](https://learn.microsoft.com/windows-hardware/drivers/)) object.

## Remarks

**FsRtlIncrementCcFastMdlReadWait** increments the cache manager's **CcFastMdlReadWait** performance counter in the per-processor control block for the processor on which **FsRtlIncrementCcFastMdlReadWait** is called. This counter records the number of fast I/O [MDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl) read operations (FsRtlMdlRead) serviced by a file system driver.

File system drivers should call this function to update the **CcFastMdlReadWait** performance counter if the driver chooses to override the default fast I/O MDL read handler.

The counter is only used to record fast I/O MDL read operations for a nonzero length. **FsRtlIncrementCcFastMdlReadWait** should not be called for a zero-length fast I/O MDL read.

File system drivers should not increment the **CcFastMdlReadWait** performance counter if their fast I/O MDL read handler returns **FALSE** due to [IoGetTopLevelIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iogettoplevelirp) returning a non-**NULL** value. The counter should only be incremented if the file system driver actually attempts to satisfy a nonzero-length fast I/O MDL read.

## See also

[IoGetTopLevelIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iogettoplevelirp)

[MDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl)