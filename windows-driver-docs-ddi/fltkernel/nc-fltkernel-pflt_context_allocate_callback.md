# PFLT_CONTEXT_ALLOCATE_CALLBACK callback function

## Description

A minifilter driver can register a routine of type PFLT_CONTEXT_ALLOCATE_CALLBACK as the minifilter driver's *ContextAllocateCallback* routine.

## Parameters

### `PoolType` [in]

The type of pool to allocate. This parameter is required and must be one of the following:

**NonPagedPool**

**PagedPool**

Must be **NonPagedPool** if the *ContextType* parameter is FLT_VOLUME_CONTEXT.

### `Size` [in]

The size, in bytes, of the entire context, including both the portion defined by the filter manager and the portion defined by the minifilter driver.

### `ContextType` [in]

The type of context. This parameter is required and must be one of the following values:

FLT_FILE_CONTEXT (starting with Windows Vista)

FLT_INSTANCE_CONTEXT

FLT_STREAM_CONTEXT

FLT_STREAMHANDLE_CONTEXT

FLT_SECTION_CONTEXT (starting with Windows 8)

FLT_TRANSACTION_CONTEXT (starting with Windows Vista)

FLT_VOLUME_CONTEXT

## Return value

If not enough free pool is available to satisfy the request, this routine returns a **NULL** pointer. Otherwise, it returns a pointer to the newly allocated context.

## Remarks

For the rare cases that a minifilter driver must perform its own context allocation, it can specify a routine of type PFLT_CONTEXT_ALLOCATE_CALLBACK as the *ContextAllocateCallback* routine for each context type that it registers when it calls [FltRegisterFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltregisterfilter) from its [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine. To specify this routine, the minifilter driver stores a pointer to the routine in the *ContextAllocateCallback* member of the FLT_CONTEXT_REGISTRATION structure for the context type.

For more information about context registration, see the reference entry for [FLT_CONTEXT_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_context_registration).

## See also

[FLT_CONTEXT_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_context_registration)

[FLT_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_registration)

[FltRegisterFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltregisterfilter)

[PFLT_CONTEXT_CLEANUP_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_context_cleanup_callback)

[PFLT_CONTEXT_FREE_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_context_free_callback)