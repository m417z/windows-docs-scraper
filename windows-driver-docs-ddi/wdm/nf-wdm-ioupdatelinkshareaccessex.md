# IoUpdateLinkShareAccessEx function

## Description

The **IoUpdateLinkShareAccessEx** routine updates the access and share access for the given file object.

## Parameters

### `FileObject`

Pointer to the file object, which usually is being closed by the current thread.

### `ShareAccess`

A pointer to the common share-access data structure that is associated with *FileObject*. Drivers should treat this structure as opaque.

### `LinkShareAccess`

A pointer to the common link share-access data structure ([LINK_SHARE_ACCESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_link_share_access)) that is associated with *FileObject*. Drivers should treat this structure as opaque.

### `IoShareAccessFlags`

A bitmask of these flags:

IO_SHARE_ACCESS_NON_PRIMARY_STREAM (0x00000080) specifies that the stream is neither the primary data stream nor a directory stream.

## Remarks

Before calling **IoUpdateLinkShareAccessEx**, the driver must successfully call [**IoCheckLinkShareAccess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iochecklinkshareaccess) with the *Update* parameter set to **FALSE**.

## See also