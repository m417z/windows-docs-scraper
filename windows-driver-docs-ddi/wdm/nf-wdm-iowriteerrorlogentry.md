# IoWriteErrorLogEntry function (wdm.h)

## Description

The **IoWriteErrorLogEntry** routine queues a given error log packet to the system error logging thread.

## Parameters

### `ElEntry` [in]

Pointer to the error log packet the driver has allocated with [IoAllocateErrorLogEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocateerrorlogentry) and filled in by the caller.

## Remarks

**IoWriteErrorLogEntry** frees the error log entry. Drivers must not call **IoFreeErrorLogEntry** on a log entry that they have already passed to **IoWriteErrorLogEntry**.

## See also

[IO_ERROR_LOG_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_error_log_packet)

[IoAllocateErrorLogEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocateerrorlogentry)

[IoFreeErrorLogEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iofreeerrorlogentry)