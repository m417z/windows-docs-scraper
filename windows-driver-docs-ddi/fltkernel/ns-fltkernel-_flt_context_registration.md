# _FLT_CONTEXT_REGISTRATION structure

## Description

The FLT_CONTEXT_REGISTRATION structure is used to register context types.

## Members

### `ContextType`

The type of context. This member is required and must be one of the following values:

FLT_FILE_CONTEXT (Windows Vista and later only.)

FLT_INSTANCE_CONTEXT

FLT_STREAM_CONTEXT

FLT_STREAMHANDLE_CONTEXT

FLT_SECTION_CONTEXT (Windows 8 and later only.)

FLT_TRANSACTION_CONTEXT (Windows Vista and later only.)

FLT_VOLUME_CONTEXT

### `Flags`

A bitmask of flags that specify how the filter manager allocates a new context from a lookaside list of fixed-size contexts. This member can be zero or the following value.

| Flag | Meaning |
| --- | --- |
| FLTFL_CONTEXT_REGISTRATION_NO_EXACT_SIZE_MATCH | If the minifilter uses fixed-size contexts and this flag is specified, the filter manager allocates a context from the lookaside list if the size of the context in the lookaside list is greater than or equal to the requested size. Otherwise, the filter manager allocates a context from the lookaside list only if the size of the context in the lookaside list is equal to the requested size. |

### `ContextCleanupCallback`

A pointer to a minifilter-defined **ContextCleanupCallback** routine of type [PFLT_CONTEXT_CLEANUP_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_context_cleanup_callback). The filter manager calls this routine immediately before it deletes the context. If the minifilter has no memory or pointers to clean up inside the context, this member is optional and can be **NULL**.

### `Size`

The size, in bytes, of the minifilter-defined portion of the context, if the minifilter uses fixed-size contexts. Zero is a valid size value. If the minifilter uses variable-size contexts, this member is required and must be set to FLT_VARIABLE_SIZED_CONTEXTS.

### `PoolTag`

A pool tag value to be used for the context. This tag, which is specified as a string of one to four 7-bit ASCII characters, appears in any crash dump of the system that occurs. If the **ContextAllocateCallback** member is **NULL**, this member is required and cannot be zero.

### `ContextAllocateCallback`

Pointer to a minifilter-defined **ContextAllocateCallback** routine of type [PFLT_CONTEXT_ALLOCATE_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_context_allocate_callback). This member is optional and can be **NULL**. If it is not **NULL**, the **Size** and **PoolTag** members are ignored.

### `ContextFreeCallback`

A pointer to a minifilter-defined **ContextFreeCallback** routine of type [PFLT_CONTEXT_FREE_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_context_free_callback). This member is optional and can be **NULL**. If it is not **NULL**, the **Size** and **PoolTag** members are ignored.

### `Reserved1`

Reserved for system use. Minifilters must set this member to **NULL**.

## Remarks

When a minifilter calls [FltRegisterFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltregisterfilter) from its **DriverEntry** routine, it must register each context type that it uses.

To register these context types, the minifilter creates a variable-length array of FLT_CONTEXT_REGISTRATION structures and stores a pointer to the array in the **ContextRegistration** member of the [FLT_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_registration) structure that the minifilter passes as the *Registration* parameter of [FltRegisterFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltregisterfilter). The last element of this array must be {FLT_CONTEXT_END}.

For each context type that the minifilter uses, the minifilter must supply at least one FLT_CONTEXT_REGISTRATION structure, according to the following rules:

* If the minifilter supplies an FLT_CONTEXT_REGISTRATION structure with a non-**NULL** **ContextAllocateCallback** member, it cannot supply any additional FLT_CONTEXT_REGISTRATION structures for that context type.
* If the minifilter supplies two or more identical FLT_CONTEXT_REGISTRATION structures, only the first one will be used. The others will be ignored.
* Only one FLT_CONTEXT_REGISTRATION structure with a **Size** member of FLT_VARIABLE_SIZED_CONTEXTS can be supplied for each context type.
* No more than three FLT_CONTEXT_REGISTRATION structures with a **Size** member other than FLT_VARIABLE_SIZED_CONTEXTS can be supplied for each context type.

## See also

[FLT_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_registration)

[FltRegisterFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltregisterfilter)

[PFLT_CONTEXT_ALLOCATE_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_context_allocate_callback)

[PFLT_CONTEXT_CLEANUP_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_context_cleanup_callback)

[PFLT_CONTEXT_FREE_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_context_free_callback)