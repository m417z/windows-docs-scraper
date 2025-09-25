# IoGetPagingIoPriority function

## Description

The **IoGetPagingIoPriority** routine indicates the priority level of a paging I/O request.

## Parameters

### `Irp` [in]

Pointer to the IRP to be tested for paging priority.

## Return value

**IoGetPagingIoPriority** returns the [IO_PAGING_PRIORITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_io_paging_priority) value for the associated IRP.

## Remarks

For I/O requests that causing paging, the system associates an **IO_PAGING_PRIORITY** value that describes the IRP's priority. Drivers can use this value when queuing IRPs.

## See also

[IO_PAGING_PRIORITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_io_paging_priority)