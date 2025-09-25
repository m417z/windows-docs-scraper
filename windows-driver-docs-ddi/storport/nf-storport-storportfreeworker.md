# StorPortFreeWorker function

## Description

Frees a Storport work item previously allocated by the [StorPortInitializeWorker](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitializeworker) routine.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension for the host bus adapter (HBA).

### `Worker`

A pointer to an opaque buffer for the work item context returned by [**StorPortInitializeWorker**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitializeworker).

## Return value

The [StorPortInitializeWorker](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitializeworker) routine returns one of these status codes:

| Return code | Description |
| --- | --- |
| **STOR_STATUS_INVALID_IRQL** | Current IRQL > DISPATCH_LEVEL. |
| **STOR_STATUS_INVALID_PARAMETER** | Either *HwDeviceExtension* or *WorkItem* is NULL. |
| **STOR_STATUS_BUSY** | The work item is currently queued for processing. |
| **STOR_STATUS_SUCCESS** | The work item was successfully freed. |
| **STOR_STATUS_UNSUCCESSFUL** | The work item is already free. |

## Remarks

Miniports should call **StorPortFreeWorker** whenever a work item is no longer needed or when the miniport receives a PnP SRB notification that the adapter is removed.

## See also

[StorPortInitializeWorker](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitializeworker)

[StorPortQueueWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportqueueworkitem)