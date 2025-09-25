# ShouldBlockRevert function

## Description

Checks the registry for writers that should block revert operations on the specified volume.

**Note** This function is only available on Windows Server operating systems.

## Parameters

### `wszVolumeName` [in]

The name of the volume. This name must be in one of the following formats and must include a trailing backslash (\\):

* The path of a mounted folder, for example, Y:\MountX\
* A drive letter, for example,
  D:\
* A volume GUID path of the form \\?\*Volume*{*GUID*}\ (where *GUID* identifies the volume)

### `pbBlock` [out]

A pointer to a variable that receives **true** if the volume contains components from any writers that are listed in the registry as writers that should block revert operations, or **false** otherwise.

## Return value

This function can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | The function succeeded. |
| **E_ACCESSDENIED** | The caller is not an administrator. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## Remarks

The list of writers that should block revert operations is stored in the registry under the following key:

**HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Services\VSS\Settings\WritersBlockingRevert**