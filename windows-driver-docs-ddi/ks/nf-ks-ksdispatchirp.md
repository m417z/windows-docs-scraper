# KsDispatchIrp function

## Description

**KsDispatchIrp** calls a dispatch routine corresponding to the function code of the specified IRP. **KsDispatchIrp** then returns the status code from this call.

## Parameters

### `DeviceObject` [in]

Specifies a pointer to the [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) to which the specific file object belongs.

### `Irp` [in]

Contains the IRP for which to call a dispatch routine.

## Return value

Returns the status code returned from the dispatch routine.

## Remarks

A [KSDISPATCH_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksdispatch_table) can be contained in the stack location's file object's **FsContext** member. **KsDispatchIrp** calls the dispatch routine listed in this dispatch table for that major code.

## See also

[KsSetMajorFunctionHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kssetmajorfunctionhandler)