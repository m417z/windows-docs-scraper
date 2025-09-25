# PcForwardIrpSynchronous function

## Description

The **PcForwardIrpSynchronous** function is used by IRP handlers to forward Plug and Play IRPs to the [physical device object (PDO)](https://learn.microsoft.com/windows-hardware/drivers/).

## Parameters

### `DeviceObject` [in]

Pointer to the audio device's device object. This parameter must point to a system structure of type [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object).

### `Irp` [in]

Pointer to the [IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp) that is to be forwarded

## Return value

**PcForwardIrpSynchronous** returns STATUS_SUCCESS if the call was successful. Otherwise, it returns an appropriate error code.

## Remarks

**PcForwardIrpSynchronous** causes the next PDO to receive the IRP and block until the IRP has been completed by the physical device driver. At that point, **PcForwardIrpSynchronous** unblocks and returns to the caller. The caller (an IRP handler) should eventually return--possibly with a status of STATUS_PENDING. In general, any IRP handler that calls this function must specify the action IRP_ACTION_FINISH upon returning. Any other action would result in the IRP being forwarded to the physical device a second time.

The [PcCompleteIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pccompleteirp) function is used when an IRP handler returns STATUS_PENDING and the IRP must be completed later.

## See also

[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)

[IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp)

[PcCompleteIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pccompleteirp)