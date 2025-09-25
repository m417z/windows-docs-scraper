# IoIsFileOriginRemote function

## Description

The **IoIsFileOriginRemote** routine determines whether a given file object is for a remote create request.

## Parameters

### `FileObject` [in]

Pointer to a file object for the file.

## Return value

**IoIsFileOriginRemote** returns **TRUE** if the file object was created to satisfy a remote create request, otherwise **FALSE**.

## Remarks

File system filter drivers call **IoIsFileOriginRemote** for a file object to determine whether it represents a remote create request.

**IoIsFileOriginRemote** must be called after the create request has entirely completed. In other words, it cannot be called in the create dispatch ("pre-create") path or the create completion ("post-create") path.

**IoIsFileOriginRemote** checks the FO_REMOTE_ORIGIN flag on the file object pointed to by *FileObject*. Network file systems set or clear this flag by calling [IoSetFileOrigin](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iosetfileorigin).

## See also

[IoSetFileOrigin](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iosetfileorigin)