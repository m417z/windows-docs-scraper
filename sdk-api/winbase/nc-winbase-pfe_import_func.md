# PFE_IMPORT_FUNC callback function

## Description

An application-defined callback function used with
[WriteEncryptedFileRaw](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-writeencryptedfileraw). The system calls
**ImportCallback** one or more times, each time to retrieve a
portion of a backup file's data.
**ImportCallback** reads the data from a backup file
sequentially and restores the data, and the system continues calling it until it has read all of the backup file
data.

The **PFE_IMPORT_FUNC** type defines a pointer to this callback function.
**ImportCallback** is a placeholder for the
application-defined function name.

## Parameters

### `pbData` [in]

A pointer to a system-supplied buffer that will receive a block of data to be restored.

### `pvCallbackContext` [in, optional]

A pointer to an application-defined and allocated context block. The application passes this pointer to
[WriteEncryptedFileRaw](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-writeencryptedfileraw), and it passes this
pointer to the callback function so that the callback function can have access to application-specific data.
This data can be a structure and can contain any data the application needs, such as the handle to the file that
contains the backup copy of the encrypted file.

### `ulLength` [in, out]

On function entry, this parameter specifies the length of the buffer the system has supplied. The callback
function must write no more than this many bytes to the buffer pointed to by the
*pbData* parameter.

On exit, the function must set this to the number of bytes of data written into the
*pbData*.

## Return value

If the function succeeds, it must set the return value to **ERROR_SUCCESS**, and set
the value pointed to by the *ulLength* parameter to the number of bytes copied into
*pbData*.

When the end of the backup file is reached, set *ulLength* to zero to tell the system
that the entire file has been processed.

If the function fails, set the return value to a nonzero error code defined in WinError.h. For
example, if this function fails because an API that it calls fails, you can set the return value to the value
returned by [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) for the failed API.

## Remarks

The system calls the **ImportCallback** function until the
callback function indicates there is no more data to restore. To indicate that there is no more data to be
restored, set **ulLength* to 0 and use a return code of
**ERROR_SUCCESS**. You can use the application-defined context block for internal tracking
of information such as the file handle and the current offset in the file.

## See also

[CloseEncryptedFileRaw](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-closeencryptedfileraw)

[ExportCallback](https://learn.microsoft.com/windows/desktop/api/winbase/nc-winbase-pfe_export_func)

[File Encryption](https://learn.microsoft.com/windows/desktop/FileIO/file-encryption)

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[OpenEncryptedFileRaw](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openencryptedfilerawa)

[ReadEncryptedFileRaw](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-readencryptedfileraw)

[WriteEncryptedFileRaw](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-writeencryptedfileraw)