# DavGetExtendedError function

## Description

Retrieves the extended error code information that the WebDAV server returned for the previous failed I/O operation.

## Parameters

### `hFile` [in]

A handle to an open file for which the previous I/O operation has failed. If the previous operation is a failed create operation, in which case there is no open file handle, specify INVALID_HANDLE_VALUE for this parameter.

### `ExtError` [out]

Pointer to a variable that receives the extended error code.

### `ExtErrorString` [out]

Pointer to a buffer that receives the extended error information as a null-terminated Unicode string.

### `cChSize` [in, out]

A pointer to a variable that on input specifies the size, in Unicode characters, of the buffer that the *ExtErrorString* parameter points to. This value must be at least 1024 characters.

 If the function succeeds, on output the variable receives the number of characters that are actually copied into the buffer. If the function fails with ERROR_INSUFFICIENT_BUFFER, the variable receives 1024, but no characters are copied into the *ExtErrorString* buffer.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes), such as one of the following values.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more parameter values were not valid. |
| **ERROR_INSUFFICIENT_BUFFER** | The value that the *cChSize* parameter points to was less than 1024. |

## Remarks

If you call this function for a file handle whose previous I/O operation was successful, it returns ERROR_INVALID_PARAMETER.

## See also

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)

[OpenFile](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openfile)

[WriteFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefile)