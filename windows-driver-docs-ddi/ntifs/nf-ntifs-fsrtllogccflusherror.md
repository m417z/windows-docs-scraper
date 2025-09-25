# FsRtlLogCcFlushError function

## Description

The **FsRtlLogCcFlushError** routine logs a lost delayed-write error and displays a dialog box to the user.

## Parameters

### `FileName` [in]

The name of the file that could not be flushed.

### `DeviceObject` [in]

A pointer to the device object that this log entry should be filed against.

### `SectionObjectPointer` [in]

A pointer to the section object for the file on which the flush failed.

### `FlushError` [in]

The error returned by the call to [CcFlushCache](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccflushcache).

### `Flags` [in]

A value of 0 or a bitwise combination of one or more of the following flags:

| Flag | Meaning |
| --- | --- |
| FSRTL_CC_FLUSH_ERROR_FLAG_NO_HARD_ERROR | Suppresses presentation of an informational dialog box to the user. |
| FSRTL_CC_FLUSH_ERROR_FLAG_NO_LOG_ENTRY | Suppresses generation of a system error log entry. |

## Return value

The **FsRtlLogCcFlushError** routine returns STATUS_SUCCESS on success or another NTSTATUS value, such as STATUS_INSUFFICIENT_RESOURCES.

## Remarks

Unless the call includes appropriate *Flags*, the **FsRtlLogCcFlushError** routine uses [IoRaiseInformationalHardError](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioraiseinformationalharderror) to display a dialog box to the user, including the specific error and *FileName*, and uses [IoWriteErrorLogEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iowriteerrorlogentry) logs the error.

If the entire *FileName* cannot fit within the log buffer, the routine inserts an ellipsis into the file name.

If the cache still has pages that have been modified, the error is not fatal. The routine returns to the caller without logging an error or displaying the dialog box.

If the error is fatal, the routine increments the lost delayed write counter in the processor control block ([PRCB](https://learn.microsoft.com/windows-hardware/drivers/)). This counter can be used in troubleshooting lost delayed write errors.

## See also

[CcFlushCache](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccflushcache)

[IoRaiseInformationalHardError](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioraiseinformationalharderror)

[IoWriteErrorLogEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iowriteerrorlogentry)