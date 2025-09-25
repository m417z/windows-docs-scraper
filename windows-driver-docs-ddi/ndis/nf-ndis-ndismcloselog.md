# NdisMCloseLog function

## Description

**NdisMCloseLog** releases resources that were used for logging.

## Parameters

### `LogHandle` [in]

Specifies the handle returned by
[NdisMCreateLog](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcreatelog).

## Remarks

**NdisMCloseLog** closes the temporary log file allocated by
**NdisMCreateLog** and releases all resources associated with the driver's logging operations when a
miniport driver is unloading.

## See also

[MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt)

[NdisMCreateLog](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcreatelog)

[NdisMFlushLog](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismflushlog)

[NdisMWriteLogData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismwritelogdata)