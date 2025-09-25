# IQueueCallbackStateChange::OnStateChange

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **OnStateChange** method is called when the state of the I/O queue object changes.

## Parameters

### `pWdfQueue` [in]

A pointer to the [IWDFIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfioqueue) interface for the I/O queue object whose state changes.

### `QueueState` [in]

A valid bitwise OR of [WDF_IO_QUEUE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi_types/ne-wudfddi_types-_wdf_io_queue_state)-typed values that indicates status for the queue.

## Remarks

A driver registers the [IQueueCallbackStateChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iqueuecallbackstatechange) interface when the driver calls the [IWDFDevice::CreateIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-createioqueue) method to create an I/O queue or to configure the default I/O queue. The driver can optionally register the **IQueueCallbackStateChange** interface only for a manual queue. The driver must not register **IQueueCallbackStateChange** for a sequential or a parallel queue.

## See also

[IQueueCallbackStateChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iqueuecallbackstatechange)

[IWDFDevice::CreateIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-createioqueue)

[IWDFIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfioqueue)

[WDF_IO_QUEUE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi_types/ne-wudfddi_types-_wdf_io_queue_state)