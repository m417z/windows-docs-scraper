# StorPortFreeTimer function

## Description

Frees a Storport timer context object previously created by the [StorPortInitializeTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitializetimer) routine.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension for the host bus adapter (HBA).

### `TimerHandle` [in]

A pointer to an opaque buffer for the timer context returned by [StorPortInitializeTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitializetimer).

## Return value

The **StorPortFreeTimer** routine returns one of these status codes:

| Return code | Description |
| --- | --- |
| **STOR_STATUS_INVALID_IRQL** | Current IRQL > DISPATCH_LEVEL. |
| **STOR_STATUS_INVALID_PARAMETER** | Either *HwDeviceExtension* or *TimerHandle* is NULL. |
| **STOR_STATUS_INSUFFICIENT_RESOURCES** | Insufficient resources are available to free the timer. |
| **STOR_STATUS_SUCCESS** | The timer was successfully freed. |
| **STOR_STATUS_UNSUCCESSFUL** | The timer is already free. |

## Remarks

Miniports should call **StorPortFreeTimer** whenever a work item is no longer needed or when the miniport receives a PnP SRB notification that the adapter is removed.

## See also

[HwStorAdapterControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control)

[StorPortInitializeTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitializetimer)

[StorPortRequestTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportrequesttimer)