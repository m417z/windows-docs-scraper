# IoSetShareAccess function

## Description

The **IoSetShareAccess** routine sets the access rights for sharing the given file object.

## Parameters

### `DesiredAccess` [in]

Specifies an [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) value that represents the type of access requested for the *FileObject*. See [IoCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatefile) for a complete list of system-defined *DesiredAccess* flags.

### `DesiredShareAccess` [in]

Specifies the type of share access to be set for the file object. This value can be zero, or any combination of the following:

FILE_SHARE_READ

FILE_SHARE_WRITE

FILE_SHARE_DELETE

### `FileObject` [in, out]

Pointer to the file object whose share access is being set or reset.

### `ShareAccess` [out]

Pointer to the SHARE_ACCESS structure associated with *FileObject*. Drivers should treat this structure as opaque.

## Remarks

Only highest-level kernel-mode drivers should call this routine. The call must occur in the context of the first thread that attempts to open the *FileObject*.

This routine sets the access and share access information when the *FileObject* is first opened. It returns a pointer to the common share-access data structure associated with *FileObject*. Callers should save this pointer for later use when updating the access or closing the file.

Generally, file system drivers (FSDs) are most likely to call this routine. However, other highest-level drivers can call **IoSetShareAccess** to control the kind of access allowed to a driver-created device object associated with the given *FileObject*.

**IoSetShareAccess** is not an atomic operation. Therefore, drivers calling this routine must protect the shared file object passed to **IoSetShareAccess** by means of some kind of lock, such as a mutex or a resource lock, in order to prevent corruption of the shared access counts.

## See also

[ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)

[IoCheckShareAccess](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocheckshareaccess)

[IoCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatefile)

[IoCreateFileEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iocreatefileex)

[IoGetFileObjectGenericMapping](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iogetfileobjectgenericmapping)

[IoGetRelatedDeviceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetrelateddeviceobject)

[IoRemoveShareAccess](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioremoveshareaccess)

[IoUpdateShareAccess](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioupdateshareaccess)