# KsSynchronousDeviceControl function

## Description

The **KsSynchronousDeviceControl** function issues a synchronous device I/O control operation to the KS object that is specified by a file handle.

## Parameters

### `Handle` [in]

Handle to the KS object on which to perform the operation.

### `IoControl` [in]

Control code that identifies a specific type of operation to perform on a KS object.

### `InBuffer` [in, optional]

Pointer to a buffer that contains data that specifies the operation to perform.

### `InLength` [in]

Size, in bytes, of the buffer at *InBuffer*.

### `OutBuffer` [out, optional]

Pointer to a buffer that contains either data for the operation or buffer space that receives data for the operation.

### `OutLength` [in]

Size, in bytes, of the buffer at *OutBuffer*.

### `BytesReturned` [in, out]

Pointer to a variable that receives the size, in bytes, of the data that **KsSynchronousDeviceControl** stores in the buffer at *OutBuffer*.

## Return value

Returns NOERROR if successful; otherwise, returns an error code.

## Remarks

To retrieve the handle to the KS object, an application should call the [IKsObject::KsGetObjectHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nf-ksproxy-iksobject-ksgetobjecthandle) method.

An application can set the control code in *IoControl* and the buffers at *InBuffer* and *OutBuffer* as follows to specify the operation to perform:

* Set *IoControl* to [IOCTL_KS_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ni-ks-ioctl_ks_property) to access a property. Set *InBuffer* to point to a [KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure) structure that specifies the property of the property set to access and whether to retrieve information about the property or set information in the property. To set information in the property, set *OutBuffer* to point to that information. To retrieve information from the property, set *OutBuffer* to receive that information.
* Set *IoControl* to [IOCTL_KS_METHOD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ni-ks-ioctl_ks_method) to execute a method. Set *InBuffer* to point to a [KSMETHOD](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethod-structure) structure that specifies the method of the method set to execute and whether to read and/or write data related to the method. To read data, set *OutBuffer* to point to that data. To write data, set *OutBuffer* to receive that data.
* Set *IoControl* to [IOCTL_KS_ENABLE_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ni-ks-ioctl_ks_enable_event) to request that the KS object specified by *Handle* notify the application whenever a specific event action occurs. Set *InBuffer* to point to a [KSEVENT](https://learn.microsoft.com/windows-hardware/drivers/stream/ksevent-structure) structure that specifies the event of the event set about which to notify. Set *OutBuffer* to point to a [KSEVENTDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kseventdata) structure that describes how the KS object should notify the application when the event occurs. Also see [KS Events](https://learn.microsoft.com/windows-hardware/drivers/stream/ks-events).
* Set *IoControl* to [IOCTL_KS_DISABLE_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ni-ks-ioctl_ks_disable_event) to inform the KS object specified by *Handle* to stop notifying the application whenever a specific event action occurs. Set *InBuffer* to point to the [KSEVENTDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kseventdata) structure that was previously used in the event-notification request.

To retrieve a list of all properties, events, or methods supported by a filter, an application can set *IoControl* to IOCTL_KS_PROPERTY, IOCTL_KS_ENABLE_EVENT, or IOCTL_KS_METHOD. For the KSPROPERTY, KSEVENT, or KSMETHOD structure to which *InBuffer* points, set the *Set* member to GUID_NULL and set the *Flags* member to KSPROPERTY_TYPE_SETSUPPORT.

After the call to **KsSynchronousDeviceControl**, *OutBuffer* will contain an array of set GUIDs supported by the object specified by *Handle*.

## See also

[IKsObject::KsGetObjectHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nf-ksproxy-iksobject-ksgetobjecthandle)

[IOCTL_KS_DISABLE_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ni-ks-ioctl_ks_disable_event)

[IOCTL_KS_ENABLE_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ni-ks-ioctl_ks_enable_event)

[IOCTL_KS_METHOD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ni-ks-ioctl_ks_method)

[IOCTL_KS_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ni-ks-ioctl_ks_property)

[KSEVENT](https://learn.microsoft.com/windows-hardware/drivers/stream/ksevent-structure)

[KSEVENTDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kseventdata)

[KSMETHOD](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethod-structure)

[KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure)