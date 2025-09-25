# IoSetLinkShareAccess function

## Description

The **IoSetLinkShareAccess** routine sets the access rights for link sharing the specified file object.

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

### `LinkShareAccess` [in, out, optional]

A pointer to the common link share-access data structure ([LINK_SHARE_ACCESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_link_share_access)) that is associated with *FileObject*. Drivers should treat this structure as opaque.

### `IoShareAccessFlags` [in]

A bitmask of these flags:

IO_SHARE_ACCESS_NO_WRITE_PERMISSION (0x80000000) specifies that the user has no write permission for the file. This flag is used to prevent opening a file for exclusive read access
when the user does not have appropriate permissions.

IO_CHECK_SHARE_ACCESS_UPDATE_SHARE_ACCESS (0x00000001) indicates whether the SHARE_ACCESS structure
is updated.

## See also

[IoCheckLinkShareAccess](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iochecklinkshareaccess)

[IoRemoveLinkShareAccess](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioremovelinkshareaccess)

[IoUpdateLinkShareAccess](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioupdatelinkshareaccess)