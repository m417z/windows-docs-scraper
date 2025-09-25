## Description

Gets disk space information for a volume at a given root path.

## Parameters

### `rootPath`

A pointer to a string that contains the root directory of the volume to be queried.

If this parameter is `NULL`, the function uses the root of the current disk.

### `diskSpaceInfo`

A [**DISK_SPACE_INFORMATION**](https://learn.microsoft.com/windows/win32/api/fileapi/ns-fileapi-disk_space_information) structure containing information about the current disk space for the volume at the given root path.

## Return value

Returns `S_OK` if the function succeeds, or a value from [Common HRESULT Values](https://learn.microsoft.com/windows/win32/seccrypto/common-hresult-values) if it fails. You can call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) for extended error information.

## Remarks

The `rootPath` must be a root path, such as `C:\` or `D:\`, and not a subdirectory of a root path.

## See also

[GetDiskSpaceInformationW](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-getdiskspaceinformationw)

[DISK_SPACE_INFORMATION](https://learn.microsoft.com/windows/win32/api/fileapi/ns-fileapi-disk_space_information)