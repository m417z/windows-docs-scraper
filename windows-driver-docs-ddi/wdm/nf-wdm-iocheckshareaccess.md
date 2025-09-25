# IoCheckShareAccess function

## Description

The **IoCheckShareAccess** routine is called by file system drivers (FSDs) or other highest-level drivers to check whether shared access to a file object is permitted.

## Parameters

### `DesiredAccess` [in]

Specifies an [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) value that indicates the desired type of access to the given *FileObject* for the current open request. Drivers compute the value of this parameter by taking the requested access in the [IRP_MJ_CREATE](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-create) request and then applying [SeAccessCheck](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-seaccesscheck) for each security descriptor to determine the actual access granted. If the granted access is more restrictive than the desired access, then that is an error, and the driver should complete the current IRP with a status of STATUS_ACCESS_DENIED. (Note that **SeAccessCheck** clears the MAXIMUM_ALLOWED bit in the granted access; be sure to not use that bit when comparing desired access to granted access.) The driver then passes the granted access as the value of *DesiredAccess*.

### `DesiredShareAccess` [in]

Specifies the desired type of shared access to *FileObject* for the current open request. The value of this parameter is usually the same as the *ShareAccess* passed to the file system or highest-level driver by the I/O manager when the open request was made. This value can be zero, or any combination of the following:

FILE_SHARE_READ

FILE_SHARE_WRITE

FILE_SHARE_DELETE

### `FileObject` [in, out]

Pointer to the file object for which to check access for the current open request.

### `ShareAccess` [in, out]

Pointer to the common share-access data structure associated with *FileObject*. Drivers should treat this structure as opaque.

### `Update` [in]

Specifies whether to update the share-access status for *FileObject*. A Boolean value of **TRUE** means this routine will update the share access information for the file object if the open request is permitted.

## Return value

**IoCheckShareAccess** returns STATUS_SUCCESS if the requester's access to the file object is compatible with the way in which it is currently open. If the request is denied because of a sharing violation, then STATUS_SHARING_VIOLATION is returned.

## Remarks

**IoCheckShareAccess** checks a file object open request to determine whether the types of desired and shared accesses specified are compatible with the way in which the file object is currently being accessed by other opens.

File systems maintain state about files through structures called file control blocks (FCBs). The SHARE_ACCESS is a structure describing how the file is currently accessed by all opens. This state is contained in the FCB as part of the open state for each file object. Each file object should have only one share access structure. Other highest-level drivers might call this routine to check the access requested when a file object representing such a driver's device object is opened.

**IoCheckShareAccess** is not an atomic operation. Therefore, drivers calling this routine must protect the shared file object passed to **IoCheckShareAccess** by means of some kind of lock, such as a mutex or a resource lock, in order to prevent corruption of the shared access counts.

## See also

[ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)

[IoCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatefile)

[IoCreateFileEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iocreatefileex)

[IoGetRelatedDeviceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetrelateddeviceobject)

[IoRemoveShareAccess](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioremoveshareaccess)

[IoSetShareAccess](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iosetshareaccess)

[IoUpdateShareAccess](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioupdateshareaccess)