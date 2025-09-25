# FltGetContextsEx function

## Description

The **FltGetContextsEx** routine retrieves a minifilter driver's contexts for the objects related to the current operation.

## Parameters

### `FltObjects` [in]

Pointer to a [**FLT_RELATED_OBJECTS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_related_objects) structure containing opaque pointers for the objects related to the current operation. See Remarks for more information.

### `DesiredContexts` [in]

Identifies the types of contexts to retrieve. This parameter can be a bitwise OR of the following values.

| Constant | Value |
| -------- | ----- |
| FLT_VOLUME_CONTEXT | 0x0001 |
| FLT_INSTANCE_CONTEXT | 0x0002 |
| FLT_FILE_CONTEXT | 0x0004 |
| FLT_STREAM_CONTEXT | 0x0008 |
| FLT_STREAMHANDLE_CONTEXT | 0x0010 |
| FLT_TRANSACTION_CONTEXT | 0x0020 |
| FLT_SECTION_CONTEXT | 020040 |
| FLT_ALL_CONTEXTS | Bitwise OR of all of the context values |

### `ContextsSize` [in]

The size, in bytes, of the [**FLT_RELATED_CONTEXTS_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_related_contexts_ex) structure pointed to by **Contexts**. Set to **sizeof**(FLT_RELATED_CONTEXTS_EX).

### `Contexts` [out]

Pointer to a caller-allocated [**FLT_RELATED_CONTEXTS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_related_contexts) structure that receives the requested contexts. This parameter is required and cannot be set to NULL. *FltMgr* sets a structure member to zero for:

* Contexts that the caller did not request.
* Contexts that the caller requested but *FltMgr* couldn't find.

## Return value

**FltGetContextsEx** returns STATUS_SUCCESS upon successful completion. Otherwise, it returns a status code such as one of the following.

| Code | Meaning |
| ---- | ------- |
| STATUS_INVALID_PARAMETER | An invalid context value was input. |

## Remarks

For more information about contexts, see [About minifilter contexts](https://learn.microsoft.com/windows-hardware/drivers/ifs/managing-contexts-in-a-minifilter-driver).

A minifilter driver calls **FltGetContextsEx** to retrieve pointers to its contexts for the objects in a [**FLT_RELATED_OBJECTS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_related_objects) structure. On STATUS_SUCCESS, the minifilter will need to check that a context is not zero before using it.

The following minifilter driver callback routine types receive a pointer to a [**FLT_RELATED_OBJECTS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_related_objects) structure as the **FltObjects** input parameter:

* [**PFLT_PRE_OPERATION_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_pre_operation_callback)
* [**PFLT_POST_OPERATION_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_post_operation_callback)
* [**PFLT_INSTANCE_SETUP_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_instance_setup_callback)
* [**PFLT_INSTANCE_QUERY_TEARDOWN_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_instance_query_teardown_callback)
* [**PFLT_INSTANCE_TEARDOWN_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_instance_teardown_callback)

**FltGetContextsEx** increments the reference count on each of the contexts returned in the [**FLT_RELATED_CONTEXTS_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_related_contexts_ex) structure that the *Contexts* parameter points to. Thus for every successful call to **FltGetContextsEx**, the caller must either:

* Call [**FltReleaseContextsEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasecontextsex) for the entire structure that the *Contexts* parameter points to.
* Call [**FltReleaseContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasecontext) for each of the contexts returned in the structure and set each context field returned in the structure to zero.

## See also

[**FLT_RELATED_CONTEXTS_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_related_contexts_ex)

[**FLT_RELATED_OBJECTS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_related_objects)

[**FltRegisterFilter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltregisterfilter)

[**FltReleaseContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasecontext)

[**FltReleaseContextsEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasecontextsex)

[**PFLT_INSTANCE_QUERY_TEARDOWN_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_instance_query_teardown_callback)

[**PFLT_INSTANCE_SETUP_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_instance_setup_callback)

[**PFLT_INSTANCE_TEARDOWN_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_instance_teardown_callback)

[**PFLT_POST_OPERATION_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_post_operation_callback)

[**PFLT_PRE_OPERATION_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_pre_operation_callback)