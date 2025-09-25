## Description

An AVStream minidriver's IRP handling routine is called when these IRPs are dispatched by the device.

[IRP_MN_CANCEL_STOP_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-cancel-stop-device)

[IRP_MN_CANCEL_REMOVE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-cancel-remove-device)

[IRP_MN_REMOVE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-remove-device)

[IRP_MN_STOP_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-stop-device)

[IRP_MN_SURPRISE_REMOVAL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-surprise-removal)

## Parameters

### `Device` [in]

Pointer to the [**KSDEVICE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice) that dispatched the IRP.

### `Irp` [in]

The IRP issued by *Device*.

## Remarks

| IRP | Description |
|---|---|
| [IRP_MN_CANCEL_STOP_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-cancel-stop-device) | The minidriver specifies this routine's address in the **CancelStop** member of its [**KSDEVICE_DISPATCH**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice_dispatch) structure. This routine is optional. |
| [IRP_MN_CANCEL_REMOVE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-cancel-remove-device) | The minidriver specifies this routine's address in the **CancelRemove** member of its [KSDEVICE_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice_dispatch) structure. This routine is called when an [IRP_MN_CANCEL_REMOVE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-cancel-remove-device) is dispatched by the device. This routine is optional. |
| [IRP_MN_REMOVE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-remove-device) | The minidriver specifies this routine's address in the **MiniRemove** member of its [**KSDEVICE_DISPATCH**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice_dispatch) structure. AVStream calls this routine when an [IRP_MN_REMOVE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-remove-device) is dispatched by the device. Typically, it will be provided by minidrivers that must free device-associated resources upon device removal. This routine is optional. |
| [IRP_MN_STOP_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-stop-device) | The minidriver specifies this routine's address in the **Stop** member of its [**KSDEVICE_DISPATCH**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice_dispatch) structure. This is usually provided by minidrivers that need to detach from previously assigned resources before completing a stop operation. This routine is optional. |
| [IRP_MN_SURPRISE_REMOVAL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-surprise-removal) | The minidriver specifies this routine's address in the **SurpriseRemoval** member of its [**KSDEVICE_DISPATCH**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice_dispatch) structure. This routine is optional. |

## See also

[**KSDEVICE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice)

[**KSDEVICE_DISPATCH**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice_dispatch)