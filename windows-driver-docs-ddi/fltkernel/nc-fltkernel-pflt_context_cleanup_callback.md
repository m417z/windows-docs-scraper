# PFLT_CONTEXT_CLEANUP_CALLBACK callback function

## Description

A minifilter driver can register a routine of type PFLT_CONTEXT_CLEANUP_CALLBACK as the minifilter driver's *ContextCleanupCallback* routine.

## Parameters

### `Context` [in]

A pointer to the minifilter driver's portion of the context.

### `ContextType` [in]

The type of context. Must be one of the following values:

FLT_FILE_CONTEXT (starting with Windows Vista)

FLT_INSTANCE_CONTEXT

FLT_STREAM_CONTEXT

FLT_STREAMHANDLE_CONTEXT

FLT_SECTION_CONTEXT (starting with Windows 8)

FLT_TRANSACTION_CONTEXT (starting with Windows Vista)

FLT_VOLUME_CONTEXT

## Remarks

A minifilter driver can optionally specify a routine of type PFLT_CONTEXT_CLEANUP_CALLBACK as the minifilter driver's *ContextCleanupCallback* routine for each context type that it registers when it calls [FltRegisterFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltregisterfilter) from its [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine. To specify this routine, the minifilter driver stores a pointer to the routine in the *ContextCleanupCallback* member of the FLT_CONTEXT_REGISTRATION structure for the context type.

If the minifilter driver specifies a *ContextCleanupCallback* routine for a context type, the filter manager calls this routine before freeing any of the minifilter driver's contexts of that type. In this routine, the minifilter driver performs any needed cleanup, such as freeing additional memory that the minifilter driver allocated inside the context structure. After the *ContextCleanupCallback* routine returns, the filter manager frees the context.

For more information about context registration, see the reference entry for [FLT_CONTEXT_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_context_registration).

## See also

[FLT_CONTEXT_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_context_registration)

[FLT_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_registration)

[FltRegisterFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltregisterfilter)

[PFLT_CONTEXT_ALLOCATE_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_context_allocate_callback)

[PFLT_CONTEXT_FREE_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_context_free_callback)