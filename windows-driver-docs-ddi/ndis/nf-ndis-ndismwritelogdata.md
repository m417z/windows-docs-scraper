# NdisMWriteLogData function

## Description

**NdisMWriteLogData** transfers driver-supplied information into the log file for consumption and display
by a driver-dedicated Win32 application.

## Parameters

### `LogHandle` [in]

Specifies the handle returned by
[NdisMCreateLog](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcreatelog).

### `LogBuffer` [in]

Pointer to a driver-allocated buffer containing the information to be written.

### `LogBufferSize` [in]

Specifies how many bytes of data to copy into the log file.

## Return value

**NdisMWriteLogData** can return one of the following:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | The driver-supplied data at *LogBuffer* has been copied into the log file. |
| **NDIS_STATUS_BUFFER_OVERFLOW** | The given *LogBufferSize* is too large, that is, larger than the log file itself. |

## Remarks

If the driver-dedicated application has an outstanding request for log file data,
**NdisMWriteLogData** satisfies that request as soon as it has copied the driver-supplied information
into the log file.

The miniport driver can supply a
*LogBuffer* pointer to a location on the kernel stack if it is currently running at IRQL <
DISPATCH_LEVEL. Otherwise,
*LogBuffer* must access a buffer that the driver allocated from nonpaged pool.

The driver must release any spin lock it is holding before calling
**NdisMWriteLogData**.

**NdisMWriteLogData** does not recognize boundaries between log records, nor does the Win32 function,
[DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol), which applications can call with IOCTL_NDIS_GET_LOG_DATA to retrieve data written
to an NDIS log file by an NDIS miniport driver.
**NdisMWriteLogData** writes all miniport driver-supplied data at
*LogBuffer* into the log file as a byte stream.
**DeviceIoControl** reads the data from such a log as a byte stream, as well.

Consequently, an application reading an NDIS log must collect retrieved data into records. To aid such
an application in collecting variable-length records, any miniport driver writing to such a log can
insert a marker at the beginning of each record. Then, the application formatting the retrieved data can
search for these markers to determine the start of each record.

## See also

[NdisAllocateFromNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatefromnpagedlookasidelist)

[NdisAllocateMemoryWithTagPriority](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatememorywithtagpriority)

[NdisMCloseLog](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcloselog)

[NdisMCreateLog](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcreatelog)

[NdisMFlushLog](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismflushlog)

[NdisReleaseSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisreleasespinlock)