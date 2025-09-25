# PcCompleteIrp function

## Description

The **PcCompleteIrp** function completes an IRP that was previously marked as pending.

## Parameters

### `pDeviceObject` [in]

Pointer to the device object for the device. This parameter must point to a system structure of type [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object).

### `pIrp` [in]

Pointer to the [IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp) that is to be completed

### `ntStatus` [in]

Specifies the status of the completed IRP. See the list of NTSTATUS values defined in header file ntstatus.h.

## Return value

**PcCompleteIrp** returns STATUS_SUCCESS if the call was successful. Otherwise, it returns an appropriate error code.

## Remarks

**PcCompleteIrp** is used when an IRP handler returns STATUS_PENDING and the IRP must later be completed. When the adapter driver finishes all processing of the IRP, it calls **PcCompleteIrp** to complete the IRP.

The IRP handler should not call this function. An adapter driver's IRP handler instead calls [PcDispatchIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcdispatchirp) to pass the IRP to the PortCls system driver's IRP handler to perform all remaining processing of the IRP.

## See also

[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)

[IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp)

[IoCompleteRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocompleterequest)

[PcDispatchIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcdispatchirp)