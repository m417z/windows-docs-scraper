# IoSetShareAccessEx function

## Description

The **IoSetShareAccessEx** routine sets the access rights for sharing the specified file object.

## Parameters

### `DesiredAccess` [in]

Specifies an [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) value that represents the type of access requested for the file object. See [IoCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatefile) for a complete list of system-defined *DesiredAccess* flags.

### `DesiredShareAccess` [in]

Specifies the type of share access to be set for the file object. This value can be zero, or any combination of the following flags:

FILE_SHARE_READ

FILE_SHARE_WRITE

FILE_SHARE_DELETE

### `FileObject` [in, out]

A pointer to the file object whose share access is being set or reset.

### `ShareAccess` [out]

A pointer to the **SHARE_ACCESS** structure that is associated with *FileObject*. Drivers should treat this structure as opaque.

### `WritePermission` [in, optional]

A pointer to the value that specifies whether the file object has write permission. This value is **TRUE** if the share has write permission; otherwise, it is **FALSE**. If the value is **FALSE** and the caller attempts to take exclusive read access, the write permission is downgraded to FILE_SHARE_READ.

## See also

[ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)

[IoCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatefile)