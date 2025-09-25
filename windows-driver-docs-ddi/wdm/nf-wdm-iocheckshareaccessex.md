# IoCheckShareAccessEx function

## Description

The **IoCheckShareAccessEx** routine is called by file system drivers (FSDs) or other highest-level drivers to check whether shared access to a file object is permitted.

## Parameters

### `DesiredAccess` [in]

Specifies an [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) value that indicates the desired type of access to the given file object.

### `DesiredShareAccess` [in]

Specifies the desired type of shared access to the file object for the current open request. The value of this parameter is usually the same as the *ShareAccess* parameter that is passed to the file system or highest-level driver by the I/O manager when the open request was made. This value can be zero, or any combination of the following:

FILE_SHARE_READ

FILE_SHARE_WRITE

FILE_SHARE_DELETE

### `FileObject` [in, out]

A pointer to the file object for which to check access for the current open request.

### `ShareAccess` [in, out]

A pointer to the common share-access data structure that is associated with *FileObject*. Drivers should treat this structure as opaque.

### `Update` [in]

Specifies whether to update the share-access status for *FileObject*. A Boolean value of **TRUE** means this routine will update the share access information for the file object if the open request is permitted.

### `WritePermission` [in]

Specifies whether the share access has write permission. This value is TRUE if the share has write permission; otherwise, FALSE. If the value is FALSE and the share access has write permission and the caller attempts to take exclusive read access, the write permission is downgraded to FILE_SHARE_READ. This value is NULL if a write permission check is not done on the share access.

## Return value

The **IoCheckShareAccessEx** routine returns STATUS_SUCCESS if the requester's access to the file object is compatible with the way in which it is currently open. If the request is denied because of a sharing violation, then STATUS_SHARING_VIOLATION is returned.

## See also

[I/O Manager Routines](https://learn.microsoft.com/windows-hardware/drivers/ddi/)