# KsServiceBusEnumCreateRequest function

## Description

*This function is intended for internal use only.*

The **KsServiceBusEnumCreateRequest** function services IRP_MJ_CREATE requests for the software bus device interface.

## Parameters

### `DeviceObject` [in]

Pointer to the device object.

### `Irp` [in, out]

Pointer to the IRP that is associated with the device object.

## Return value

Returns STATUS_SUCCESS if successful. Otherwise. it returns STATUS_OBJECT_NAME_NOT_FOUND if the IRP's *FileObject->FileName* is **NULL** or if the reference string cannot be located. Otherwise, an appropriate error returns.

## Remarks

**KsServiceBusEnumCreateRequest** services the IRP_MJ_CREATE request for the registered device interface by matching the given IRP's *FileObject->FileName* with the registered bus reference strings. If the device reference is present, enumerated and created, the IRP is simply re-routed to the actual device. If the reference string is **NULL**, it is assumed that this is a request for the bus interface and the IRP_MJ_CREATE is completed. If the device reference has not already been enumerated, or is not active, the IRP is queued and a PDO is created and a bus enumeration is initiated by IoInvalidateDeviceRelations().

## See also

[KsServiceBusEnumPnpRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/swenum/nf-swenum-ksservicebusenumpnprequest)