# KsReferenceBusObject function

## Description

References the bus Physical device object.

## Parameters

### `Header` [in]

Points to a header previously allocated by **KsAllocateDeviceHeader** that also contains the PnP device stack object.

## Return value

Returns STATUS_SUCCESS if the reference was successful, else an error such as STATUS_INSUFFICIENT_RESOURCES.

## Remarks

This function is used by filters that use the device header to keep track of their PnP object stack. This is normally called on a successful Open of the filter when the bus for this device requires such a reference (such as software devices), and is matched by a call to [KsDereferenceBusObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksdereferencebusobject) on a close of that filter instance. The caller must have previously also called KsSetDevicePnpAndBaseObject in order to set the PnP device stack object. This would have been done in the PnP AddDevice function. If the object has not been previously referenced, interface space is allocated and the function uses the PnP device object to acquire the bus referencing interface. It then calls the ReferenceDeviceObject method on that interface. The interface itself is released and freed when the device header is freed.