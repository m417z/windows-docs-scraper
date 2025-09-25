## Description

The **IoSkipCurrentIrpStackLocation** macro modifies the system's [**IO_STACK_LOCATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location) array pointer, so that when the current driver calls the next-lower driver, that driver receives the same **IO_STACK_LOCATION** structure that the current driver received.

## Parameters

### `Irp` [in, out]

A pointer to the IRP.

## Remarks

When your driver sends an IRP to the next-lower driver, your driver can call **IoSkipCurrentIrpStackLocation** if you do not intend to provide an [_IoCompletion_](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_completion_routine) routine (the address of which is stored in the driver's [**IO_STACK_LOCATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location) structure). If you call **IoSkipCurrentIrpStackLocation** before calling [**IoCallDriver**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocalldriver), the next-lower driver receives the same **IO_STACK_LOCATION** that your driver received.

If you intend to provide an _IoCompletion_ routine for the IRP, your driver should call [**IoCopyCurrentIrpStackLocationToNext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocopycurrentirpstacklocationtonext) instead of **IoSkipCurrentIrpStackLocation**. If a badly written driver makes the mistake of calling **IoSkipCurrentIrpStackLocation** and then setting a completion routine, this driver might overwrite a completion routine set by the driver above it.

If the driver has pended an IRP, the driver should not be calling **IoSkipCurrentIrpStackLocation** before it passes the IRP to the next lower driver. If the driver calls **IoSkipCurrentIrpStackLocation** on a pended IRP before passing it to the next lower driver, the SL_PENDING_RETURNED flag is still set in the **Control** member of the I/O stack location for the next driver. Because the next driver owns that stack location and might modify it, it could potentially clear the pending flag. This situation might cause the operating system to issue a bug check or the processing of the IRP to never be completed.

Instead, a driver that has pended an IRP should call **IoCopyCurrentIrpStackLocationToNext** to set up a new stack location for the next lower driver before it calls **IoCallDriver**.

If your driver calls **IoSkipCurrentIrpStackLocation**, be careful not to modify the **IO_STACK_LOCATION** structure in a way that could unintentionally affect the lower driver or the system's behavior with respect to that driver. Examples include modifying the **IO_STACK_LOCATION** structure's **Parameters** union or calling [**IoMarkIrpPending**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iomarkirppending).