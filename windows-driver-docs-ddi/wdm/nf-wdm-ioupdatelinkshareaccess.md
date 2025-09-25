# IoUpdateLinkShareAccess function

## Description

The **IoUpdateLinkShareAccess** routine updates the share access for the given file object, usually when the file is being opened.

## Parameters

### `FileObject` [in]

Pointer to the file object, which usually is being closed by the current thread.

### `ShareAccess` [in, out]

A pointer to the common share-access data structure that is associated with *FileObject*. Drivers should treat this structure as opaque.

### `LinkShareAccess` [in, out, optional]

A pointer to the common link share-access data structure ([LINK_SHARE_ACCESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_link_share_access)) that is associated with *FileObject*. Drivers should treat this structure as opaque.

## Remarks

**IoUpdateLinkShareAccess** is not an atomic operation. Therefore, drivers calling this routine must protect the shared file object passed to **IoUpdateLinkShareAccess** by means of some kind of lock, such as a mutex or a resource lock, in order to prevent corruption of the shared access counts.

Before calling **IoUpdateLinkShareAccess**, the caller must successfully call [IoCheckLinkShareAccess](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iochecklinkshareaccess) with *Update* set to False. Such a call to **IoCheckLinkShareAccess** determines whether the requested shared access is compatible with the way the file object is currently being accessed by other opens, but it does not update the **SHARE_ACCESS** structure. **IoUpdateLinkShareAccess** actually updates the **SHARE_ACCESS** structure associated with the file object.

## See also

[IoCheckLinkShareAccess](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iochecklinkshareaccess)

[IoRemoveLinkShareAccess](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioremovelinkshareaccess)

[IoSetLinkShareAccess](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iosetlinkshareaccess)