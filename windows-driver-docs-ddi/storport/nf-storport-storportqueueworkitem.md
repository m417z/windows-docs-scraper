# StorPortQueueWorkItem function

## Description

**StorPortQueueWorkItem** queues a Storport work item to execute within the context of a system (kernel) worker thread.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension for the host bus adapter (HBA).

### `WorkItemCallback` [in]

A pointer to a work item callback routine supplied by the miniport. This routine is called in context of the system thread to process the scheduled work item that **Worker** points to.

### `Worker` [in]

A pointer to an opaque buffer for the allocated and initialized work item returned by [**StorPortInitializeWorker**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitializeworker).

### `Context` [in, optional]

Optional context for the **Worker** that is processed by the callback routine in **WorkItemCallback**.

## Return value

**StorPortQueueWorkItem** routine returns one of these status codes:

| Return code | Description |
| ----------- | ----------- |
| STOR_STATUS_BUSY | The work item is already queued for processing. |
| STOR_STATUS_INVALID_DEVICE_STATE | The work item cannot be queued as the device is in process of removal. |
| STOR_STATUS_INVALID_IRQL | The current IRQL is greater than DISPATCH_LEVEL. |
| STOR_STATUS_INVALID_PARAMETER | **HwDeviceExtension**, **Worker**, or **WorkItemCallback** is NULL. |
| STOR_STATUS_SUCCESS | The work item was successfully queued. |

## See also

[**HwStorWorkItem**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_workitem)

[**StorPortFreeWorker**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportfreeworker)

[**StorPortInitializeWorker**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitializeworker)