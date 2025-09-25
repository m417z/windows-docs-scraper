# FilterUnload function

## Description

An application that has loaded a supporting minifilter by calling [FilterLoad](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterload) can unload the minifilter by calling the **FilterUnload** function.

## Parameters

### `lpFilterName` [in]

Pointer to a null-terminated wide-character string containing the same minifilter name that was passed to [FilterLoad](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterload). This parameter is required and cannot be **NULL** or an empty string.

## Return value

**FilterUnload** returns S_OK if successful. Otherwise, it returns an error value.

## Remarks

**FilterUnload** is the Win32 equivalent of [FltUnloadFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltkernel/nf-fltkernel-fltunloadfilter).

**FilterUnload** searches for a registered minifilter whose service name matches the given *lpFilterName* and calls that minifilter's *FilterUnloadCallback* ([PFLT_FILTER_UNLOAD_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltkernel/nc-fltkernel-pflt_filter_unload_callback)) routine.

If the minifilter did not register a *FilterUnloadCallback* routine, the call to **FilterUnload** fails.

Callers of **FilterUnload** must have **SeLoadDriverPrivilege** (the LUID of SE_LOAD_DRIVER_PRIVILEGE) to load or unload a minifilter driver. This privilege is named by the SE_LOAD_DRIVER_NAME name constant. (Privileges are described in the Microsoft Windows Software Development Kit (SDK) for Windows 7 and .NET Framework 4.0 documentation.)

## See also

[FilterLoad](https://learn.microsoft.com/windows/desktop/api/fltuser/nf-fltuser-filterload)

[FltUnloadFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltkernel/nf-fltkernel-fltunloadfilter)

[PFLT_FILTER_UNLOAD_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fltkernel/nc-fltkernel-pflt_filter_unload_callback)