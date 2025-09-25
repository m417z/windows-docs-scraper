# PcDispatchIrp function

## Description

The **PcDispatchIrp** function dispatches an IRP to the PortCls system driver's default handler.

## Parameters

### `pDeviceObject` [in]

Pointer to the device object. This parameter must point to a system structure of type [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object).

### `pIrp` [in]

Pointer to the [IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp) that is to be dispatched

## Return value

**PcDispatchIrp** returns STATUS_SUCCESS if the call was successful. Otherwise, it returns an appropriate error code.

## Remarks

As part of its initialization process, the [PcInitializeAdapterDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcinitializeadapterdriver) function loads pointers to handlers for several IRPs into the driver object. Following the call to **PcInitializeAdapterDriver**, an adapter driver can choose to overwrite one or more of the PortCls handler pointers with pointers to its own IRP handlers.

If, after receiving an IRP, the adapter driver's IRP handler determines that the IRP should be handled by the PortCls IRP handler instead, the adapter driver's handler calls **PcDispatchIrp** to forward the IRP to the PortCls handler.

For a code example, see the SB16 sample audio driver in the Microsoft Windows Driver Kit (WDK).

## See also

[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)

[IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp)

[PcInitializeAdapterDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcinitializeadapterdriver)