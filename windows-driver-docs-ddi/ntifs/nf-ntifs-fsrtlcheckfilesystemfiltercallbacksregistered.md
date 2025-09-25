## Description

The **FsRtlCheckFileSystemFilterCallbacksRegistered** routine checks whether the driver object has already registered file system filter callbacks under its driver extension field.

## Parameters

### `FilterDriverObject`

[in] Pointer to the driver object for the filter driver or filesystem that might have registered file system filter callbacks.

## Return value

**FsRtlCheckFileSystemFilterCallbacksRegistered** returns TRUE if the driver object has already registered file system filter callbacks; otherwise, it returns FALSE.