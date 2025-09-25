# IoCreateStreamFileObjectLite function

## Description

The **IoCreateStreamFileObjectLite** routine creates a new stream file object, but does not cause an IRP_MJ_CLEANUP request to be sent to the file system driver stack.

## Parameters

### `FileObject` [in, optional]

A pointer to the file object to which the new stream file is related. This parameter is optional and can be **NULL**.

### `DeviceObject` [in, optional]

A pointer to a device object for the device on which the stream file is to be opened. If the caller specifies a non-**NULL** value for *FileObject*, the value of *DeviceObject* is ignored. Otherwise, the caller must specify a non-**NULL** value for *DeviceObject*.

## Return value

**IoCreateStreamFileObjectLite** returns a pointer to the newly created stream file object.

## Remarks

File systems call **IoCreateStreamFileObjectLite** to create a new stream file object. A *stream file object* is identical to an ordinary file object, except that the FO_STREAM_FILE file object flag is set.

A stream file object is commonly used to represent an internal stream for a volume mounted by the file system. This *virtual volume file* permits the file system to view, change, and cache the volume's on-disk structure as if it were an ordinary file. In this case, the *DeviceObject* parameter in the call to **IoCreateStreamFileObjectLite** specifies the volume device object (VDO) for the volume.

A stream file object can also be used to represent an alternate data stream for accessing metadata, such as extended attributes or security descriptors, for an already opened file. In this case, the *FileObject* parameter in the call to **IoCreateStreamFileObjectLite** specifies an existing file object for the file. The newly created stream file object permits the file system to view, change, and cache the file's metadata as if it were an ordinary file.

When the stream file object is no longer needed, the caller must decrement its reference count by calling [ObDereferenceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobject). When the stream file object's reference count reaches zero, an IRP_MJ_CLOSE request is sent to the file system driver stack for the volume.

File system filter driver writers should note that, unlike [IoCreateStreamFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iocreatestreamfileobject), **IoCreateStreamFileObjectLite** does not cause an IRP_MJ_CLEANUP request to be sent to the file system driver stack. For this reason, and because file systems often create stream file objects as a side effect of operations other than IRP_MJ_CREATE, it is difficult for filter drivers to reliably detect stream file object creation. Thus filter drivers should expect to receive IRP_MJ_CLOSE requests for previously unseen file objects.

If a pool allocation failure occurs, **IoCreateStreamFileObjectLite** raises a STATUS_INSUFFICIENT_RESOURCES exception.

## See also

[IRP_MJ_CLEANUP](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-cleanup)

[IRP_MJ_CLOSE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-close)

[IRP_MJ_CREATE](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-create)

[IoCreateStreamFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iocreatestreamfileobject)

[IoCreateStreamFileObjectEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iocreatestreamfileobjectex)

[ObDereferenceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobject)