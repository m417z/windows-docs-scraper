# NdisMFlushLog function

## Description

**NdisMFlushLog** clears the log file.

## Parameters

### `LogHandle` [in]

Specifies the handle returned by
[NdisMCreateLog](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcreatelog).

## Remarks

**NdisMFlushLog** resets the position pointers within the log file to the start of the file.

The driver must release any spin lock it is holding before calling
**NdisMFlushLog**.

## See also

[NdisMCloseLog](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcloselog)

[NdisMCreateLog](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcreatelog)

[NdisMWriteLogData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismwritelogdata)

[NdisReleaseSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisreleasespinlock)