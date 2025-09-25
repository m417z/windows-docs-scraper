# IoSetFileOrigin function

## Description

The **IoSetFileOrigin** routine specifies whether a given file object is for a remote create request.

## Parameters

### `FileObject` [in]

Pointer to the file object.

### `Remote` [in]

Set to **TRUE** to set the FO_REMOTE_ORIGIN flag on the file object, **FALSE** to clear it.

## Return value

If the FO_REMOTE_ORIGIN flag on the file object is not already set (or cleared) as specified by the *Remote* parameter, **IoSetFileOrigin** sets or clears the flag as appropriate and returns STATUS_SUCCESS.

If the flag is already set (or cleared) as specified, **IoSetFileOrigin** returns STATUS_INVALID_PARAMETER_MIX and does not set or clear the flag.

## Remarks

Network file systems call **IoSetFileOrigin** to set or clear the FO_REMOTE_ORIGIN flag on the file object pointed to by *FileObject*. This flag is set to indicate that the file object was created to satisfy a remote create request.

Network file systems should call **IoSetFileOrigin** in their servers for any file objects that are created to satisfy a create request from a network client.

File system filter drivers should not call **IoSetFileOrigin**.

## See also

[IoIsFileOriginRemote](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioisfileoriginremote)