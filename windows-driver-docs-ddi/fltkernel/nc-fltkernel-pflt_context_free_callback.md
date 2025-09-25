# PFLT_CONTEXT_FREE_CALLBACK callback function

## Description

A minifilter can register a routine of type PFLT_CONTEXT_FREE_CALLBACK as the minifilter driver's *ContextFreeCallback* routine.

## Parameters

### `Pool` [in]

A pointer to the context to be freed.

### `ContextType` [in]

The type of context. This parameter is required and must be one of the following values:

FLT_FILE_CONTEXT (starting with Windows Vista)

FLT_INSTANCE_CONTEXT

FLT_STREAM_CONTEXT

FLT_STREAMHANDLE_CONTEXT

FLT_SECTION_CONTEXT (starting with Windows 8)

FLT_TRANSACTION_CONTEXT (starting with Windows Vista)

FLT_VOLUME_CONTEXT

## Remarks

For the rare cases that a minifilter driver must free its own contexts manually, the minifilter driver can specify a routine of type PFLT_CONTEXT_FREE_CALLBACK as the minifilter driver's *ContextFreeCallback* routine for each context type that it registers when it calls [FltRegisterFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltregisterfilter) from its [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine. To specify this routine, the minifilter driver stores a pointer to the routine in the *ContextFreeCallback* member of the FLT_CONTEXT_REGISTRATION structure for the context type.

For more information about context registration, see the reference entry for [FLT_CONTEXT_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_context_registration).

## See also

[FLT_CONTEXT_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_context_registration)

[FLT_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_registration)

[FltRegisterFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltregisterfilter)

[PFLT_CONTEXT_ALLOCATE_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_context_allocate_callback)

[PFLT_CONTEXT_CLEANUP_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_context_cleanup_callback)