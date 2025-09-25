# PFLT_NORMALIZE_CONTEXT_CLEANUP callback function

## Description

A minifilter driver that provides file names for the filter manager's name cache can register a routine of type PFLT_NORMALIZE_CONTEXT_CLEANUP as the minifilter driver's *NormalizeContextCleanupCallback* routine.

## Parameters

### `NormalizationContext` [in, optional]

Pointer to minifilter driver-provided context information to be passed in any calls to the [PFLT_NORMALIZE_NAME_COMPONENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_normalize_name_component) callback routine that are made to normalize multiple components in the same file name path.

## Remarks

A minifilter driver that provides file names for the filter manager's name cache can register a routine of type PFLT_NORMALIZE_CONTEXT_CLEANUP as the minifilter driver's *NormalizeContextCleanupCallback* routine.

To register this callback routine, the minifilter driver stores the address of a routine of type PFLT_NORMALIZE_CONTEXT_CLEANUP in the **NormalizeContextCleanupCallback** member of the [FLT_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_registration) structure that the minifilter driver passes as a parameter to [FltRegisterFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltregisterfilter).

The filter manager calls this callback routine to allow the minifilter driver to perform any needed cleanup for the context information passed in the *NormalizationContext* parameter of the [PFLT_NORMALIZE_NAME_COMPONENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_normalize_name_component) callback routine. This context is set by the minifilter driver when its PFLT_NORMALIZE_NAME_COMPONENT callback routine is called.

## See also

[FLT_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_registration)

[FltRegisterFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltregisterfilter)

[PFLT_GENERATE_FILE_NAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_generate_file_name)

[PFLT_NORMALIZE_NAME_COMPONENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_normalize_name_component)

[PFLT_NORMALIZE_NAME_COMPONENT_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_normalize_name_component_ex)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)