## Description

An AVStream minidriver's IRP handler routine is called when these IRPs is dispatched by the device.

[IRP_MN_QUERY_REMOVE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-remove-device)

[IRP_MN_QUERY_STOP_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-stop-device)

[IRP_MN_QUERY_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-interface)

## Parameters

### `Device` [in]

Pointer to the [KSDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice) that dispatched the IRP.

### `Irp` [in]

The IRP issued by *Device*.

## Return value

Should return STATUS_SUCCESS or the error code that was returned from the attempt to perform the operation. If this is not the case, return an appropriate error code.

## Remarks

| IRP | Description |
|---|---|
| [IRP_MN_QUERY_REMOVE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-remove-device) | The minidriver specifies this routine's address in the **QueryRemove** member of its [KSDEVICE_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice_dispatch) structure. This routine is called when an [IRP_MN_QUERY_REMOVE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-remove-device) is dispatched by the device. It will usually be provided by minidrivers that want to prevent removal of the device or by minidrivers that must disallow activity that would otherwise prevent them from committing to a device removal operation. If this routine is not provided, AVStream will assume that the device can commit to a removal. The routine is called at IRQL = PASSIVE_LEVEL and may not return STATUS_PENDING; a success code indicates that the device can commit to a removal and an error code indicates that it cannot. Return success if the device can be removed (or drivers can be updated) without disrupting the machine. This routine is optional. |
| [IRP_MN_QUERY_STOP_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-stop-device) | The minidriver specifies a pointer to this routine in the **QueryStop** member of its [KSDEVICE_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice_dispatch) structure. Use *AVStrMiniQueryStop* to prevent the stopping of the device or to disallow activity that would prevent the minidriver from committing to a stop operation. If this routine is not specified, AVStream assumes that the minidriver can commit to a stop operation. This routine is optional. Success indicates that the device can commit to a stop and an error code indicates that it cannot. Do not return STATUS_PENDING. |
| [IRP_MN_QUERY_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-interface) | A driver or system component sends this IRP to get information about an interface exported by your driver. For more information about the IRP, see [IRP_MN_QUERY_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-interface). The minidriver specifies this routine's address in the **QueryInterface** member of its [KSDEVICE_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice_dispatch) structure. This routine is optional. |

## See also

[KSDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice)

[KSDEVICE_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice_dispatch)