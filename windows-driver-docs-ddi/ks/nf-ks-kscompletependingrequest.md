# KsCompletePendingRequest function

## Description

The **KsCompletePendingRequest** function is used to complete an I/O request in response to which an AVStream dispatch function previously returned STATUS_PENDING.

## Parameters

### `Irp` [in]

A pointer to the [IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp) structure that must be completed; this is passed in the dispatch function that returned a STATUS_PENDING.

## Remarks

If the dispatch function in question does not pass an IRP, it **cannot** return STATUS_PENDING. Minidrivers should set **IRP.IoStatus.Status** before calling this function.

**KsCompletePendingRequest** can be used for PnP dispatch functions in the device dispatch table or filter creation and closure requests. Dispatch functions that return STATUS_PENDING must call this function when they complete the request.

## See also

[IO_STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_status_block)

[IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp)

[KSDEVICE_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice_dispatch)

[KSFILTER_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter_dispatch)