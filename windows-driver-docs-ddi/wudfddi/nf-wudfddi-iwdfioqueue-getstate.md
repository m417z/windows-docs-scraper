# IWDFIoQueue::GetState

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **GetState** method retrieves the state of an I/O queue.

## Parameters

### `pulNumOfRequestsInQueue` [out]

A pointer to a variable that receives the number of I/O requests that are currently in the I/O queue (that is, that have not been delivered to the driver).

### `pulNumOfRequestsInDriver` [out]

A pointer to a variable that receives the number of I/O requests that the driver accepted from the I/O queue but that the driver has not completed, canceled, or forwarded to another I/O queue.

## Return value

**GetState** returns a bitwise OR of [WDF_IO_QUEUE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi_types/ne-wudfddi_types-_wdf_io_queue_state)-typed values that provides the state of the queue.

## Remarks

The total number of requests that are associated with the I/O queue is the sum of the values that the *pulNumOfRequestsInQueue* and *pulNumOfRequestsInDriver* parameters point to.

## See also

[IWDFIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfioqueue)

[WDF_IO_QUEUE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi_types/ne-wudfddi_types-_wdf_io_queue_state)