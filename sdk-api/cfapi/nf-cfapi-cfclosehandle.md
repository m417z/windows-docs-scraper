# CfCloseHandle function

## Description

Closes the file or directory handle returned by [CfOpenFileWithOplock](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfopenfilewithoplock). This should not be used with standard Win32 file handles, only on handles used within `CfApi.h`.

## Parameters

### `FileHandle` [in]

The file or directory handle to be closed.

## See also

[CfOpenFileWithOplock](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfopenfilewithoplock)