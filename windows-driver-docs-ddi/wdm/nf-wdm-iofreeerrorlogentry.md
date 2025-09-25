# IoFreeErrorLogEntry function

## Description

The **IoFreeErrorLogEntry** routine frees an unused error log entry.

## Parameters

### `ElEntry` [in]

Pointer to an error log packet allocated by [IoAllocateErrorLogEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocateerrorlogentry).

## Remarks

Drivers use **IoFreeErrorLogEntry** to free an error log entry allocated by [IoAllocateErrorLogEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocateerrorlogentry). [IoWriteErrorLogEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iowriteerrorlogentry) also frees any error log entries passed to it, so drivers must not call both on the same log entry.

## See also

[IO_ERROR_LOG_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_error_log_packet)

[IoAllocateErrorLogEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocateerrorlogentry)

[IoWriteErrorLogEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iowriteerrorlogentry)