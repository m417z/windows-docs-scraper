# IoRemoveLinkShareAccessEx function

## Description

The **IoRemoveLinkShareAccessEx** routine removes the access and share access information in a file system Share Access structure for a given open instance.

## Parameters

### `FileObject` [in]

Pointer to the file object, which usually is being closed by the current thread.

### `ShareAccess` [in, out]

A pointer to the common share-access data structure that is associated with *FileObject*. Drivers should treat this structure as opaque.

### `LinkShareAccess` [in, out, optional]

A pointer to the common link share-access data structure ([LINK_SHARE_ACCESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_link_share_access)) that is associated with *FileObject*. Drivers should treat this structure as opaque.

### `IoShareAccessFlags`

A bitmask of these flags:

IO_SHARE_ACCESS_NON_PRIMARY_STREAM (0x00000080) specifies that the stream is neither the primary data stream nor a directory stream.

## Remarks

## See also