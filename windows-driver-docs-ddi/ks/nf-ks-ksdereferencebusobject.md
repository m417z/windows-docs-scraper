# KsDereferenceBusObject function

## Description

Dereferences the bus Physical Device Object.

## Parameters

### `Header` [in]

Points to a header previously allocated by **KsAllocateDeviceHeader** that also contains the PnP device stack object.

## Return value

None.

## Remarks

This is used by filters that use the device header to keep track of the corresponding PnP object stack. This is normally called when closing a filter, if required by the bus for the given device. As an example, a software device would require such a call. This call matches a previous call to [KsReferenceBusObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksreferencebusobject) when opening the filter instance. The caller must have previously also called **KsSetDevicePnpAndBaseObject** in order to set the PnP device stack object. This would have been done in the PnP **AddDevice** function. The function calls the **DereferenceDeviceObject** method on the previously retrieved interface. The interface itself is released and freed when the device header is freed.