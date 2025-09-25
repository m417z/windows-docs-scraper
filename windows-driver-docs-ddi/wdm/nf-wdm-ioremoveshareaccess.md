# IoRemoveShareAccess function

## Description

The **IoRemoveShareAccess** routine removes the access and share-access information for a given open instance of a file object.

## Parameters

### `FileObject` [in]

Pointer to the file object, which usually is being closed by the current thread.

### `ShareAccess` [in, out]

Pointer to the share-access structure that describes how the open file object is currently being accessed.

## Remarks

This routine is a reciprocal to [IoUpdateShareAccess](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioupdateshareaccess).

**IoRemoveShareAccess** is not an atomic operation. Therefore, drivers calling this routine must protect the shared file object passed to **IoRemoveShareAccess** by means of some kind of lock, such as a mutex or a resource lock, in order to prevent corruption of the shared access counts.

Callers of **IoRemoveShareAccess** must be running at IRQL = PASSIVE_LEVEL and in the context of the thread that requested that the *FileObject* be closed.

## See also

[IoCheckShareAccess](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocheckshareaccess)

[IoSetShareAccess](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iosetshareaccess)

[IoUpdateShareAccess](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioupdateshareaccess)