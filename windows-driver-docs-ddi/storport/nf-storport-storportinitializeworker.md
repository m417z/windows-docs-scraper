# StorPortInitializeWorker function

## Description

Creates a new Storport work item that runs in a system worker thread.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension for the host bus adapter (HBA).

### `Worker` [out]

A pointer to an opaque buffer that holds context information for the work item.

## Return value

The **StorPortInitializeWorker** routine returns one of these status codes:

| Return code | Description |
| --- | --- |
| **STOR_STATUS_INVALID_IRQL** | Current IRQL > DISPATCH_LEVEL. |
| **STOR_STATUS_INVALID_PARAMETER** | Either *HwDeviceExtension* or *Worker* is NULL. |
| **STOR_STATUS_INSUFFICIENT_RESOURCES** | Insufficient resources are available to initialize the work item context. |
| **STOR_STATUS_SUCCESS** | The work item was successfully initialized. |

## Remarks

The work item context returned in the *Worker* parameter by **StorPortInitializeWorker** is used in future calls to [StorPortQueueWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportqueueworkitem) or [StorPortFreeWorker](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportfreeworker).

If the miniport uses the work item during IO processing, we recommended that **StorPortInitializeWorker** be called during the miniport's [HwStorFindAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_find_adapter) function to ensure that resources are available when needed.

## See also

[HwStorFindAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_find_adapter)

[StorPortFreeWorker](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportfreeworker)

[StorPortQueueWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportqueueworkitem)