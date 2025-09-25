# DavGetTheLockOwnerOfTheFile function

## Description

Returns the file lock owner for a file that is locked on a WebDAV server.

## Parameters

### `FileName` [in]

A pointer to a **null**-terminated Unicode string that contains the name of a locked file on the WebDAV server. This string must be in one of the following formats:

* \\*server*\*path*\*filename*
* *drive*:\*filename*

where *server* is the name of a server, *path* is the path to a remote file on the server, *filename* is a valid file name, and *drive* is the drive letter that a remote share is mapped to on the local computer. (A *share* is a directory on a server that is made available to users over the network.)

### `LockOwnerName` [out, optional]

A pointer to a caller-allocated buffer that receives the name of the owner of the file lock. This parameter is optional and can be **NULL**. If it is **NULL**, the *LockOwnerNameLengthInBytes* parameter must point to zero on input.

### `LockOwnerNameLengthInBytes` [in, out]

A pointer to a variable that on input specifies the maximum size, in Unicode characters, of the buffer that the *LockOwnerName* parameter points to. If the function succeeds, on output the variable receives the number of characters that were copied into the buffer. If the function fails with ERROR_INSUFFICIENT_BUFFER, on output the variable receives the number of characters needed to store the lock owner name, including the terminating **NULL** character.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes), such as one of the following values.

| Return code | Description |
| --- | --- |
| **ERROR_INSUFFICIENT_BUFFER** | The buffer that the *LockOwnerName* parameter points to was not large enough to store the lock owner name. |
| **ERROR_INVALID_PARAMETER** | One or more parameter values were not valid. For example, this error code is returned if the *FileName* parameter is a **null** pointer. |

## Remarks

If a call to a function such as [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) for a file on a WebDAV server fails with ERROR_LOCK_VIOLATION, you can use the **DavGetTheLockOwnerOfTheFile** function to determine the owner of the file lock.

To obtain the required buffer length for the *LockOwnerName* buffer, call **DavGetTheLockOwnerOfTheFile** with *LockOwnerName* set to **NULL** and *LockOwnerNameLengthInBytes* set to zero. The return value is ERROR_INSUFFICIENT_BUFFER, and on output the *LockOwnerNameLengthInBytes* parameter receives the required buffer length.