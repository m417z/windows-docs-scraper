## Description

The **IoSetFileObjectIgnoreSharing** routine sets a file object to ignore file sharing access checks.

## Parameters

### `FileObject`

Pointer to a file object for the file.

## Return value

**IoSetFileObjectIgnoreSharing** returns STATUS_SUCCESS or an appropriate NTSTATUS code such as one of the following:

| Return code | Description |
|--|--|
| **STATUS_NOT_FOUND** | The option information for *FileObject* was not found. The status of sharing access checking cannot be set. |
| **STATUS_INSUFFICIENT_RESOURCES** | The option information was not created for *FileObject*. The status of sharing access checking cannot be set. |

## See also

[IoIsFileObjectIgnoringSharing](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioisfileobjectignoringsharing)