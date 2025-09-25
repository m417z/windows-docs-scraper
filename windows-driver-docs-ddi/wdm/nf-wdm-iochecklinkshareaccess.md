# IoCheckLinkShareAccess function

## Description

The **IoCheckLinkShareAccess** routine is called by file system drivers (FSDs) or other highest-level drivers to check whether link shared access to a file object is permitted.

## Parameters

### `DesiredAccess` [in]

Specifies an [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) value that indicates the desired type of access to the given file object.

### `DesiredShareAccess` [in]

Specifies the desired type of shared access to the file object for the current open request. The value of this parameter is usually the same as the *ShareAccess* parameter that is passed to the file system or highest-level driver by the I/O manager when the open request was made. This value can be zero, or any combination of the following:

FILE_SHARE_READ

FILE_SHARE_WRITE

FILE_SHARE_DELETE

### `FileObject` [in, out, optional]

A pointer to the file object for which to check access for the current open request.

### `ShareAccess` [in, out, optional]

A pointer to the common share-access data structure that is associated with *FileObject*. Drivers should treat this structure as opaque.

### `LinkShareAccess` [in, out, optional]

A pointer to the common link share-access data structure ([LINK_SHARE_ACCESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_link_share_access)) that is associated with *FileObject*. Drivers should treat this structure as opaque.

### `IoShareAccessFlags` [in]

A bitmask of these flags:

IO_SHARE_ACCESS_NO_WRITE_PERMISSION (0x80000000) specifies that the user has no write permission for the file. This flag is used to prevent opening a file for exclusive read access when the user does not have appropriate permissions.

IO_SHARE_ACCESS_NON_PRIMARY_STREAM (0x00000080) specifies that the stream is neither the primary data stream nor a directory stream.

IO_CHECK_SHARE_ACCESS_UPDATE_SHARE_ACCESS (0x00000001) indicates whether the **SHARE_ACCESS** structure is updated.

IO_CHECK_SHARE_ACCESS_DONT_UPDATE_FILE_OBJECT (0x00000002) indicates to not update **FILE_OBJECT** structure.

IO_CHECK_SHARE_ACCESS_DONT_CHECK_READ (0x00000004) indicates to not check read share access.

IO_CHECK_SHARE_ACCESS_DONT_CHECK_WRITE (0x00000008) indicates to not check write share access.

IO_CHECK_SHARE_ACCESS_DONT_CHECK_DELETE (0x00000010) indicates to not check delete share access.

IO_CHECK_SHARE_ACCESS_FORCE_CHECK (0x00000020) indicate to force check share access even if the request is not read/write/delete access.

IO_CHECK_SHARE_ACCESS_FORCE_USING_SCB (0x00000040) indicates to force check delete share access using ShareAccess regardless of whether LinkShareAccess is present or not.

## Return value

The **IoCheckLinkShareAccess** routine returns STATUS_SUCCESS if the requester's access to the file object is compatible with the way in which it is currently open. If the request is denied because of a sharing violation, then STATUS_SHARING_VIOLATION is returned.

## Remarks

 The *ShareAccess* parameter must be locked against other accesses
from other threads while this routine is executing. Otherwise the counts
can be synchronization.

## See also

[I/O Manager Routines](https://learn.microsoft.com/windows-hardware/drivers/ddi/)

[IoRemoveLinkShareAccess](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioremovelinkshareaccess)

[IoSetLinkShareAccess](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iosetlinkshareaccess)

[IoUpdateLinkShareAccess](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioupdatelinkshareaccess)