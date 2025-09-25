# IoUpdateShareAccess function

## Description

The **IoUpdateShareAccess** routine updates the share access for the given file object, usually when the file is being opened.

## Parameters

### `FileObject` [in]

Pointer to a referenced file object representing the file or associated device object for which to update the share access.

### `ShareAccess` [in, out]

Pointer to the common **SHARE_ACCESS** structure associated with the *FileObject*. Drivers should treat this structure as opaque.

## Remarks

**IoUpdateShareAccess** is not an atomic operation. Therefore, drivers calling this routine must protect the shared file object passed to **IoUpdateShareAccess** by means of some kind of lock, such as a mutex or a resource lock, in order to prevent corruption of the shared access counts.

Before calling **IoUpdateShareAccess**, the caller must successfully call **IoCheckShareAccess** with *Update* set to False. Such a call to **IoCheckShareAccess** determines whether the requested shared access is compatible with the way the file object is currently being accessed by other opens, but it does not update the **SHARE_ACCESS** structure. **IoUpdateShareAccess** actually updates the **SHARE_ACCESS** structure associated with the file object.

## See also

[IoCheckShareAccess](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocheckshareaccess)

[IoRemoveShareAccess](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioremoveshareaccess)

[IoSetShareAccess](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iosetshareaccess)