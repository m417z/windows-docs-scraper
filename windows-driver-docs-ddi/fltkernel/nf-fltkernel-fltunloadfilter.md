# FltUnloadFilter function

## Description

A minifilter driver that has loaded a supporting minifilter driver by calling [FltLoadFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltloadfilter) can unload the minifilter driver by calling **FltUnloadFilter**.

## Parameters

### `FilterName` [in]

Pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure containing the minifilter driver service name that was passed to [FltLoadFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltloadfilter).

## Return value

**FltUnloadFilter** returns STATUS_SUCCESS or an appropriate NTSTATUS value such as one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_FLT_DELETING_OBJECT** | A matching minifilter driver was found, but it is already being torn down. This is an error code. |
| **STATUS_FLT_FILTER_NOT_FOUND** | No matching minifilter driver was found. This is an error code. |

## Remarks

A minifilter driver that has a dependency on another minifilter driver can unload that minifilter driver by calling **FltUnloadFilter**. This routine searches for a registered minifilter driver whose service name matches the given *FilterName* and calls that minifilter driver's *FilterUnloadCallback* ([PFLT_FILTER_UNLOAD_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_filter_unload_callback)) routine.

If the supporting minifilter driver did not register a *FilterUnloadCallback* routine, the call to **FltUnloadFilter** fails.

A minifilter driver cannot call **FltUnloadFilter** to unload itself.

## See also

[FltLoadFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltloadfilter)

[PFLT_FILTER_UNLOAD_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_filter_unload_callback)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)