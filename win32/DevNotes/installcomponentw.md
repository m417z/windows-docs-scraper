# InstallComponentW function

Installs an exception package.

## Parameters

*InfPath* \[in\]

The path to the exception INF to process.

*CompGuid* \[in, optional\]

The GUID of the exception component being installed.

*Flags* \[in\]

The flags used to control installation behaviors. This parameter can be a combination of the following values.

| Value | Meaning |
|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------|
|

**COMP\_FLAGS\_FORCE**

0x00000020

| Skips the version check on file replacements.<br> |
|

**COMP\_FLAGS\_NEEDS\_UNINSTALL**

| Back up files that are updated to be used by an uninstall of the component.<br> |
|

**COMP\_FLAGS\_NO\_OVERWRITE**

| Skips backing up files if the Exception component version is the same as an installed component. This flag is used in a reinstallation scenario.<br> |
|

**COMP\_FLAGS\_NOUI**

0x00000002

| Suppresses all UI.<br> |
|

**COMP\_FLAGS\_UPDATE\_DLLCACHE**

| Forces the DLLCACHE directory to be updated when a system file is updated.<br> |
|

**COMP\_FLAGS\_USE\_SVCPACK\_CACHE**

| Uses files cached by a Windows service pack install to supersede files backed up.<br> |

*VerMajor* \[in, optional\]

The major version of the Exception component.

*VerMinor* \[in, optional\]

The minor version of the Exception component.

*VerBuild* \[in, optional\]

The build version of the Exception component.

*VerQFE* \[in, optional\]

The hotfix revision of the Exception component.

*Name* \[in, optional\]

The descriptive string of the component shown by the Windows File Protection dialog box if the operating system detects that a Windows File Protection protect file is damaged, tampered with, or corrupted.

## Return value

This function returns an **HRESULT** value (S\_OK or a failure code). A failure code can be checked against a value of 0x20000100 to determine whether the failure is because a reboot is required.

## Remarks

Exception packages are Windows system files that are released outside of a full package Windows release and that update operating-system files. Exception packages are authored only by operating-system teams that have been granted authorization to update Windows system files.

To install and uninstall files that are not protected by Windows File Protection, use the functions documented in [General Setup Functions](https://msdn.microsoft.com/library/ms794585.aspx). To install device drivers, venders should use functions documented in [Device Installation Functions](https://msdn.microsoft.com/library/ms792954.aspx) and [PnP Configuration Manager Functions](https://msdn.microsoft.com/library/ms790838.aspx).

This function has no associated import library or header file; you must call it by using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

## Requirements

| Requirement | Value |
|----------------|----------------------------------------------------------------------------------------|
| DLL<br> | Msoobci.dll |

