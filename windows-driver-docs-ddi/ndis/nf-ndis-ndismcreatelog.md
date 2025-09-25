# NdisMCreateLog function

## Description

**NdisMCreateLog** allocates and opens a log file in which a miniport driver can write data to be
displayed by a driver-dedicated Win32 application.

## Parameters

### `MiniportAdapterHandle` [in]

Specifies the handle input to
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize).

### `Size` [in]

Specifies how many bytes to allocate for the log file. NDIS creates a temporary file that is not
stored on disk.

### `LogHandle` [out]

Pointer to a caller-supplied variable in which this function returns a handle to the log file.
This handle is a required parameter to the
**Ndis***Xxx***Log** functions that the miniport driver calls subsequently.

## Return value

**NdisMCreateLog** can return one of the following:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | The miniport driver can use the handle returned at *LogHandle* to write data to the NDIS-allocated log file. |
| **NDIS_STATUS_RESOURCES** | A log file of the specified size could not be allocated. |
| **NDIS_STATUS_FAILURE** | The driver already called **NdisMCreateLog** successfully. |

## Remarks

A miniport driver can call the
**NdisM..Log** functions to provide any information the driver writer chooses. Whatever the miniport
driver logs can be displayed by a driver-dedicated Win32 application. Such an application calls the Win32
function
[DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) with IOCTL_NDIS_GET_LOG_DATA periodically to retrieve whatever the miniport driver
has written to the log file. For example, an under-development miniport driver might write test data to
be displayed by its corresponding application.

If
**NdisMCreateLog** returns NDIS_STATUS_RESOURCES, the driver can adjust the original
*Size* down and try calling this function again. However, a miniport driver cannot call
**NdisMCreateLog** to create more than one log file after a call succeeds.

Whatever size of log file is allocated, subsequent calls to
[NdisMWriteLogData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismwritelogdata) store data in this
file, which is treated as a circular buffer. That is, a sequence of calls to
**NdisMWriteLogData** eventually overwrites the data originally written to the log file.

## See also

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NdisMCloseLog](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcloselog)

[NdisMFlushLog](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismflushlog)

[NdisMWriteLogData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismwritelogdata)