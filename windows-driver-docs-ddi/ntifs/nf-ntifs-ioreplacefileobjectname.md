# IoReplaceFileObjectName function

## Description

The **IoReplaceFileObjectName** routine replaces the name of a file object.

## Parameters

### `FileObject` [in]

Pointer to the file object whose file name is being replaced.

### `NewFileName` [in]

Pointer to the string buffer for the new name for the file object.

### `FileNameLength` [in]

Length, in bytes, of the new name for the file object.

## Return value

Returns STATUS_SUCCESS or one of the following NTSTATUS values otherwise:

| Return code | Description |
| ----------- | ----------- |
| STATUS_INVALID_PARAMETER | The provided file object doesn't have a name to replace. |
| STATUS_INSUFFICIENT_RESOURCES | Inadequate memory is available to allocate a buffer to complete this operation. |

## Remarks

Drivers should use **IoReplaceFileObjectName** to safely replace the name in a file object. This allows the I/O manager to control the lifetime of the buffer associated with the file object. Replacing a file object name directly without using **IoReplaceFileObjectName** may conflict with other uses of the name and should be avoided when possible.

This routine should be used to replace the file object name instead of doing so manually to allow the kernel to manage the lifetime of the name correctly.