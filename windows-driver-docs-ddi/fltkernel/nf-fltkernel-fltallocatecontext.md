# FltAllocateContext function

## Description

The **FltAllocateContext** routine allocates a context structure for a specified context type.

## Parameters

### `Filter` [in]

Opaque filter pointer for the caller. This parameter is required and cannot be **NULL**.

### `ContextType` [in]

A **FLT_CONTEXT_TYPE** value that indicates the type of context to allocate. **ContextType** can be one of the following:

| Value | Meaning |
| ------ | ------- |
| FLT_VOLUME_CONTEXT (0x0001) | Allocate a volume context. |
| FLT_INSTANCE_CONTEXT (0x0002) | Allocate an instance context. |
| FLT_FILE_CONTEXT (0x0004) | Allocate a file context. |
| FLT_STREAM_CONTEXT (0x0008) | Allocate a stream context. |
| FLT_STREAMHANDLE_CONTEXT (0x0010) | Allocate a stream handle context. |
| FLT_TRANSACTION_CONTEXT (0x0020) | Allocate a transaction context. |
| FLT_SECTION_CONTEXT (0x0040) | Allocate a section context. Available starting in Windows 8. |

### `ContextSize` [in]

The size, in bytes, of the portion of the context defined by the minifilter driver. Must be greater than zero and less than or equal to **MAXUSHORT**; for fixed-size contexts, must be less than or equal to the **Size** specified in the [**FLT_CONTEXT_REGISTRATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_context_registration) structure. A minifilter uses this portion of the context to maintain context information specific to itself. *FltMgr* treats this portion of the context structure as opaque. This parameter is required and cannot be zero.

### `PoolType` [in]

The type of pool to allocate. This parameter is required and must be one of the following. See [**POOL_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_pool_type) for a detailed description of each type. See Remarks for more information.

| Value | Meaning |
| ------ | ------- |
| **NonPagedPool** | Nonpageable system memory. **PoolType** must be **NonPagedPool** if **ContextType** is FLT_VOLUME_CONTEXT.|
| **PagedPool** | Pageable system memory. |
| **NonPagedPoolNx** | No-execute (NX) nonpaged pool. |

### `ReturnedContext` [out]

Pointer to a caller-allocated variable that receives the address of the newly allocated context. The caller is responsible for calling [**FltReleaseContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasecontext) to release this context when it is no longer needed.

## Return value

**FltAllocateContext** returns **STATUS_SUCCESS** or an appropriate **NTSTATUS** value, such as one of the following:

| Return code | Description |
| ----------- | ----------- |
| STATUS_FLT_CONTEXT_ALLOCATION_NOT_FOUND | The allocation information for the context of the specified type was not provided at the time of filter registration. OR, for fixed-size contexts, the requested **ContextSize** is greater than the **Size** specified in the [**FLT_CONTEXT_REGISTRATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_context_registration) structure for the specified **ContextType**. |
| STATUS_FLT_DELETING_OBJECT | The minifilter driver that is specified in the **Filter** parameter is being torn down. This is an error code. |
| STATUS_INSUFFICIENT_RESOURCES | **FltAllocateContext** encountered a pool allocation failure. This is an error code. |
| STATUS_INVALID_BUFFER_SIZE | **ContextSize** cannot be greater than **MAXUSHORT**. This is an error code. |
| STATUS_INVALID_PARAMETER | An invalid value was specified for the **ContextType** or the **ContextSize** parameter. This is an error code. |
| STATUS_NOT_SUPPORTED | The file system does not support per-stream contexts. This is an error code. |

## Remarks

For more information about contexts, see [About minifilter contexts](https://learn.microsoft.com/windows-hardware/drivers/ifs/managing-contexts-in-a-minifilter-driver).

**FltAllocateContext** allocates a context of the specified type from the specified pool. Starting in Windows 11, whether the memory that **ReturnedContext** points to is zeroed depends as follows:

* The memory is guaranteed to be zeroed for variable-sized contexts.
* The memory content is implementation-defined for fixed-sized contexts allocated by a caller-provided callback function.
* Otherwise, the memory can't be assumed to be zeroed for fixed-sized contexts because of lookaside list behavior. That is, an entry returned from the lookaside list might not be zeroed if it is memory that was previously freed to the lookaside list as opposed to a fresh allocation.

Before Windows 11, the contents of the returned context are not zeroed.

Setting **PoolType** to an invalid value can result in unexpected behavior such as causing lookaside lists to be bypassed, resulting in the loss of the performance benefits of lookaside lists. For contexts that have a **ContextAllocateCallback** callback function, the behavior due to an invalid **PoolType** is implementation-dependent.

After the context is allocated, it can be set on an object by passing the **ReturnedContext** pointer to the appropriate set-context routine from the following table.

| Context Type | Set-Context Routine |
| ------------ | ------------------- |
| FLT_FILE_CONTEXT | [**FltSetFileContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetfilecontext) (starting with Windows Vista) |
| FLT_INSTANCE_CONTEXT | [**FltSetInstanceContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetinstancecontext) |
| FLT_SECTION_CONTEXT | [**FltCreateSectionForDataScan**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatesectionfordatascan) (starting with Windows 8) |
| FLT_STREAM_CONTEXT | [**FltSetStreamContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetstreamcontext) |
| FLT_STREAMHANDLE_CONTEXT | [**FltSetStreamHandleContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetstreamhandlecontext) |
| FLT_TRANSACTION_CONTEXT | [**FltSetTransactionContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsettransactioncontext) (starting with Windows Vista) |
| FLT_VOLUME_CONTEXT | [**FltSetVolumeContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetvolumecontext) |

When a minifilter driver calls [**FltRegisterFilter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltregisterfilter) from its **DriverEntry** routine, it must register each context type that it uses. For more information, see the reference entry for the [**FLT_CONTEXT_REGISTRATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_context_registration) structure, and [Registering context types](https://learn.microsoft.com/windows-hardware/drivers/ifs/registering-context-types).

**FltAllocateContext** does not initialize the contents of the portion of the context structure specific to the minifilter driver.

To get the context for an object, call [**FltGetContexts**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetcontexts) or the appropriate get-context routine from the following table.

| Context Type | Get-Context Routine |
| ------------ | ------------------- |
| FLT_FILE_CONTEXT | [**FltGetFileContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetfilecontext) (starting with Windows Vista) |
| FLT_INSTANCE_CONTEXT | [**FltGetInstanceContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetinstancecontext) |
| FLT_SECTION_CONTEXT | [**FltGetSectionContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetsectioncontext) (starting with Windows 8) |
| FLT_STREAM_CONTEXT | [**FltGetStreamContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetstreamcontext) |
| FLT_STREAMHANDLE_CONTEXT | [**FltGetStreamHandleContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetstreamhandlecontext) |
| FLT_TRANSACTION_CONTEXT | [**FltGetTransactionContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgettransactioncontext) (starting with Windows Vista ) |
| FLT_VOLUME_CONTEXT | [**FltGetVolumeContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetvolumecontext) |

Contexts are reference-counted, and on a successful return from **FltAllocateContext**, the context pointed to by **ReturnedContext** has been initialized to have a reference count of 1. A context is freed automatically when its reference count reaches zero. To increment the reference count on a context, call [**FltReferenceContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreferencecontext).

To decrement the reference count on a context, call [**FltReleaseContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasecontext).

Because contexts are reference-counted, it is not usually necessary to delete them. To delete a context explicitly, call [**FltDeleteContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletecontext) or the appropriate delete-context routine from the following table.

| Context Type | Delete-Context Routine |
| ------------ | ---------------------- |
| FLT_FILE_CONTEXT | [**FltDeleteFileContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletefilecontext) (starting with Windows Vista) |
| FLT_INSTANCE_CONTEXT | [**FltDeleteInstanceContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeleteinstancecontext) |
| FLT_SECTION_CONTEXT | [**FltCloseSectionForDataScan**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltclosesectionfordatascan) (starting with Windows 8) |
| FLT_STREAM_CONTEXT | [**FltDeleteStreamContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletestreamcontext) |
| FLT_STREAMHANDLE_CONTEXT | [**FltDeleteStreamHandleContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletestreamhandlecontext) |
| FLT_TRANSACTION_CONTEXT | [**FltDeleteTransactionContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletetransactioncontext) (starting with Windows Vista) |
| FLT_VOLUME_CONTEXT | [**FltDeleteVolumeContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletevolumecontext) |

## See also

[**FLT_CONTEXT_REGISTRATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_context_registration)

[**FltCloseSectionForDataScan**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltclosesectionfordatascan)

[**FltCreateSectionForDataScan**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatesectionfordatascan)

[**FltDeleteContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletecontext)

[**FltDeleteFileContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletefilecontext)

[**FltDeleteInstanceContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeleteinstancecontext)

[**FltDeleteStreamContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletestreamcontext)

[**FltDeleteStreamHandleContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletestreamhandlecontext)

[**FltDeleteTransactionContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletetransactioncontext)

[**FltDeleteVolumeContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletevolumecontext)

[**FltGetContexts**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetcontexts)

[**FltGetFileContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetfilecontext)

[**FltGetInstanceContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetinstancecontext)

[**FltGetSectionContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetsectioncontext)

[**FltGetStreamContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetstreamcontext)

[**FltGetStreamHandleContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetstreamhandlecontext)

[**FltGetTransactionContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgettransactioncontext)

[**FltGetVolumeContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetvolumecontext)

[**FltReferenceContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreferencecontext)

[**FltRegisterFilter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltregisterfilter)

[**FltReleaseContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasecontext)

[**FltSetFileContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetfilecontext)

[**FltSetInstanceContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetinstancecontext)

[**FltSetStreamContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetstreamcontext)

[**FltSetStreamHandleContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetstreamhandlecontext)

[**FltSetTransactionContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsettransactioncontext)

[**FltSetVolumeContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetvolumecontext)