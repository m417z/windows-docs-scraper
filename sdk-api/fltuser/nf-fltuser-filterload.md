# FilterLoad function

## Description

The **FilterLoad** function dynamically loads a minifilter driver into the system.

## Parameters

### `lpFilterName` [in]

Pointer to a null-terminated wide-character string that specifies the service name of the minifilter driver. This parameter is required and cannot be **NULL** or an empty string.

## Return value

**FilterLoad** returns S_OK if successful. Otherwise, it returns one of the following error values:

| Return code | Description |
| --- | --- |
| ****HRESULT_FROM_WIN32 (ERROR_ALREADY_EXISTS)**** | The minifilter driver is already running. |
| ****HRESULT_FROM_WIN32 (ERROR_FILE_NOT_FOUND)**** | No matching minifilter driver was found. |
| ****HRESULT_FROM_WIN32 (ERROR_SERVICE_ALREADY_RUNNING)**** | The minifilter driver is already running. |
| ****HRESULT_FROM_WIN32 (ERROR_BAD_EXE_FORMAT)**** | The load image for the minifilter driver specified by *lpFilterName* is invalid. |
| ****HRESULT_FROM_WIN32 (ERROR_BAD_DRIVER)**** | The load image for the minifilter driver specified by *lpFilterName* is invalid. |
| ****HRESULT_FROM_WIN32 (ERROR_INVALID_IMAGE_HASH)**** | The minifilter driver has an invalid digital signature. |

## Remarks

**FilterLoad** is the Win32 equivalent of [FltLoadFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltkernel/nf-fltkernel-fltloadfilter).

A user-mode application that has a dependency on a kernel-mode minifilter driver can load the minifilter driver by calling **FilterLoad**.

Callers of **FilterLoad** must have **SeLoadDriverPrivilege** (the LUID of SE_LOAD_DRIVER_PRIVILEGE) to load or unload a minifilter driver. This privilege is named by the SE_LOAD_DRIVER_NAME name constant. (Privileges are described in the Microsoft Windows Software Development Kit (SDK) for Windows 7 and .NET Framework 4.0 documentation.)

To unload the minifilter driver, call [FilterUnload](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterunload).

## See also

[FilterUnload](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterunload)

[FltLoadFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltkernel/nf-fltkernel-fltloadfilter)

[HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/win32/api/winerror/nf-winerror-hresult_from_win32)