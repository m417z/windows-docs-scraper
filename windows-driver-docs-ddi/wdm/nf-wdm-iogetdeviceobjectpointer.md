# IoGetDeviceObjectPointer function

## Description

The **IoGetDeviceObjectPointer** routine returns a pointer to the top object in the named device object's stack and a pointer to the corresponding file object, if the requested access to the objects can be granted.

## Parameters

### `ObjectName` [in]

Pointer to a buffer that contains a Unicode string that is the name of the device object.

### `DesiredAccess` [in]

Specifies the [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) value that represents the desired access. Usually *DesiredAccess* is FILE_READ_DATA. Infrequently, the FILE_WRITE_DATA, or FILE_ALL_ACCESS access rights are specified.

### `FileObject` [out]

Pointer to the file object that represents the corresponding device object to user-mode code if the call is successful.

### `DeviceObject` [out]

Pointer to the device object that represents the named logical, virtual, or physical device if the call is successful.

## Return value

**IoGetDeviceObjectPointer** returns STATUS_SUCCESS if it is successful. Possible error return values include the following status codes:

STATUS_OBJECT_TYPE_MISMATCH

STATUS_INVALID_PARAMETER

STATUS_PRIVILEGE_NOT_HELD

STATUS_INSUFFICIENT_RESOURCES

STATUS_OBJECT_NAME_INVALID

## Remarks

**IoGetDeviceObjectPointer** establishes a "connection" between the caller and the next-lower-level driver. A successful caller can use the returned device object pointer to initialize its own device objects. It can also be used as an argument to [IoAttachDeviceToDeviceStack](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioattachdevicetodevicestack), [IoCallDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocalldriver), and any routine that creates IRPs for lower drivers. The returned pointer is a required argument to **IoCallDriver**.

This routine also returns a pointer to the corresponding file object. When unloading, a driver can dereference the file object as a means of indirectly dereferencing the device object. To do so, the driver calls [ObDereferenceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobject) from its Unload routine, passing the file object pointer returned by **IoGetDeviceObjectPointer**. Failure to dereference the device object in a driver's Unload routine prevents the next-lower driver from being unloaded. However, drivers that close the file object before the unload process must take out an extra reference on the device object before dereferencing the file object. Otherwise, dereferencing the file object can lead to a premature deletion of the device object.

To get a pointer to the highest-level driver in the file system driver stack, a driver must ensure that the file system is mounted; if it is not, this routine traverses the storage device stack. To ensure that the file system is mounted on the storage device, the driver must specify an appropriate access mask, such as FILE_READ_DATA or FILE_WRITE_ATTRIBUTES, in the *DesiredAccess* parameter. Specifying FILE_READ_ATTRIBUTES does not cause the file system to be mounted.

After any higher-level driver has chained itself over another driver by successfully calling this routine, the higher-level driver must set the **StackSize** field in its device object to that of the next-lower-level driver's device object plus one.

Callers of **IoGetDeviceObjectPointer** must be running at IRQL = PASSIVE_LEVEL.

## See also

[ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)

[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)

[IoAllocateIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocateirp)

[IoAttachDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioattachdevice)

[IoAttachDeviceToDeviceStack](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioattachdevicetodevicestack)

[IoCallDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocalldriver)

[ObDereferenceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobject)

[ObReferenceObjectByPointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obreferenceobjectbypointer)