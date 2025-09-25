# IoRemoveLinkShareAccess function

## Description

The **IoRemoveLinkShareAccess** routine removes the access and link share-access information for a given open instance of a file object.

## Parameters

### `FileObject` [in]

Pointer to the file object, which usually is being closed by the current thread.

### `ShareAccess` [in, out]

A pointer to the common share-access data structure that is associated with *FileObject*. Drivers should treat this structure as opaque.

### `LinkShareAccess` [in, out, optional]

A pointer to the common link share-access data structure ([LINK_SHARE_ACCESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_link_share_access)) that is associated with *FileObject*. Drivers should treat this structure as opaque.

## Remarks

This routine is a reciprocal to [IoUpdateLinkShareAccess](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioupdatelinkshareaccess).

**IoRemoveLinkShareAccess** is not an atomic operation. Therefore, drivers calling this routine must protect the shared file object passed to **IoRemoveLinkShareAccess** by means of some kind of lock, such as a mutex or a resource lock, in order to prevent corruption of the shared access counts.

Callers of **IoRemoveLinkShareAccess** must be running at IRQL = PASSIVE_LEVEL and in the context of the thread that requested that the *FileObject* be closed.

## See also

[IoCheckLinkShareAccess](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iochecklinkshareaccess)

[IoSetLinkShareAccess](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iosetlinkshareaccess)

[IoUpdateLinkShareAccess](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioupdatelinkshareaccess)