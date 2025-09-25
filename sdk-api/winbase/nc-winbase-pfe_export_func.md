# PFE_EXPORT_FUNC callback function

## Description

An application-defined callback function used with
[ReadEncryptedFileRaw](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-readencryptedfileraw). The system calls
**ExportCallback** one or more times, each time with a block
of the encrypted file's data, until it has received all of the file data.
**ExportCallback** writes the encrypted file's data to
another storage media, usually for purposes of backing up the file.

The **PFE_EXPORT_FUNC** type defines a pointer to the callback function.
**ExportCallback** is a placeholder for the
application-defined function name.

## Parameters

### `pbData` [in]

A pointer to a block of the encrypted file's data to be backed up. This block of data is allocated by the
system.

### `pvCallbackContext` [in, optional]

A pointer to an application-defined and allocated context block. The application passes this pointer to
[ReadEncryptedFileRaw](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-readencryptedfileraw), and
**ReadEncryptedFileRaw** passes this pointer to the
callback function so that it can have access to application-specific data. This data can be a structure and can
contain any data the application needs, such as the handle to the file that contains the backup copy of the
encrypted file.

### `ulLength` [in]

The size of the data pointed to by the *pbData* parameter, in bytes.

## Return value

If the function succeeds, it must set the return value to **ERROR_SUCCESS**.

If the function fails, set the return value to a nonzero error code defined in WinError.h. For
example, if this function fails because an API that it calls fails, you can set the return value to the value
returned by [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) for the failed API.

## Remarks

You can use the application-defined context block for internal tracking of information such as the file handle
and the current offset in the file.

## See also

[CloseEncryptedFileRaw](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-closeencryptedfileraw)

[File Encryption](https://learn.microsoft.com/windows/desktop/FileIO/file-encryption)

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[ImportCallback](https://learn.microsoft.com/windows/desktop/api/winbase/nc-winbase-pfe_import_func)

[OpenEncryptedFileRaw](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openencryptedfilerawa)

[ReadEncryptedFileRaw](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-readencryptedfileraw)

[WriteEncryptedFileRaw](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-writeencryptedfileraw)