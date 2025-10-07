# UninstallComponent function

Removes an exception package.

## Parameters

*CompGuid* \[in, optional\]

The GUID of the exception component being uninstalled.

*Flags* \[in\]

The flags used to control installation behaviors. This parameter can be a combination of the following values.

| Value | Meaning |
|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------|
| **COMP\_FLAGS\_NOUI** | Suppresses all UI.<br> |
| **COMP\_FLAGS\_UPDATE\_DLLCACHE** | Forces the DLLCACHE directory to be updated when a system file is updated.<br> |
| **COMP\_FLAGS\_USE\_SVCPACK\_CACHE** | Uses files cached by a Windows service pack install to supersede files backed up.<br> |

*VerMajor* \[in, optional\]

The major version of the Exception component to be uninstalled.

*VerMinor* \[in, optional\]

The minor version of the Exception component to be uninstalled.

*VerBuild* \[in, optional\]

The build version of the Exception component to be uninstalled.

*VerQFE* \[in, optional\]

The hotfix revision of the Exception component to be uninstalled.

## Return value

This function does not return a value.

## Remarks

Exception packages are Windows system files that are released outside of a full package Windows release and that update operating-system files. Exception packages are authored only by operating-system teams that have been granted authorization to update Windows system files.

To install and uninstall files that are not protected by Windows File Protection, use the functions documented in [General Setup Functions](https://msdn.microsoft.com/library/ms794585.aspx). To install device drivers, venders should use functions documented in [Device Installation Functions](https://msdn.microsoft.com/library/ms792954.aspx) and [PnP Configuration Manager Functions](https://msdn.microsoft.com/library/ms790838.aspx).

This function has no associated import library or header file; you must call it by using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

## Requirements

| Requirement | Value |
|----------------|----------------------------------------------------------------------------------------|
| DLL<br> | Msoobci.dll |

## See also

[**InstallComponentW**](https://learn.microsoft.com/windows/win32/devnotes/installcomponentw)

