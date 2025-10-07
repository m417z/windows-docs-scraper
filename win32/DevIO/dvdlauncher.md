# DvdLauncher function

Verifies that the media region in the DVD drive matches the DVD drive region.

## Parameters

*HWnd* \[in\]

A handle to the top-level window to be used for any required user interface.

*DriveLetter* \[in\]

The drive letter.

## Return value

If the function succeeds and the regions match, the return value is nonzero. Otherwise, the return value is zero.

## Remarks

This function has no associated import library. You must use the [**LoadLibrary**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to StorProp.dll.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP<br> |
| Minimum supported server<br> | Windows Server 2003<br> |
| DLL<br> | StorProp.dll |

## See also

[Device Management Functions](https://learn.microsoft.com/windows/win32/devio/device-management-functions)

