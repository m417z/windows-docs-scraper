# KsDispatchInvalidDeviceRequest function

## Description

The **KsDispatchInvalidDeviceRequest** function is used in KSDISPATCH_TABLE entries that are not handled and that need to return STATUS_INVALID_DEVICE_REQUEST.

## Parameters

### `DeviceObject` [in]

Specifies the device object associated with the IRP.

### `Irp` [in]

Specifies the IRP that is not being handled.

## Return value

The **KsDispatchInvalidDeviceRequest** function returns STATUS_INVALID_DEVICE_REQUEST and completes the IRP.

## Remarks

The **KsDispatchInvalidDeviceRequest** function is needed because the dispatch table for an opened instance of a device may not handle a specific major function that another opened instance needs to handle. Therefore, the function pointer in the driver object must always point to a function that calls a dispatch table entry.

## See also

[KsDispatchFastIoDeviceControlFailure](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksdispatchfastiodevicecontrolfailure)

[KsDispatchFastReadFailure](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksdispatchfastreadfailure)

[KsDispatchFastWriteFailure](https://learn.microsoft.com/previous-versions/ff561706(v=vs.85))