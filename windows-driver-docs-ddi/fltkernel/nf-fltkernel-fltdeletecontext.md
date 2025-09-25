# FltDeleteContext function

## Description

**FltDeleteContext** marks a specified context for deletion.

## Parameters

### `Context` [in]

A pointer to the context to delete. This parameter is required and cannot be **NULL**.

## Return value

None.

## Remarks

For more information about contexts, see [About minifilter contexts](https://learn.microsoft.com/windows-hardware/drivers/ifs/managing-contexts-in-a-minifilter-driver).

Because contexts are reference-counted, it is not usually necessary for a minifilter driver to call a routine, such as **FltDeleteContext**, to explicitly delete a context.

**FltDeleteContext** marks a context for deletion. The context is usually freed as soon as the current reference on it is released, unless there is an outstanding reference on it (for example, because the context is still being used by another thread).

You should consider the following items when you use **FltDeleteContext**:

* When a minifilter driver calls **FltDeleteContext**, the minifilter driver must already have a reference to the context. However, when the minifilter driver calls [FltDeleteStreamHandleContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletestreamhandlecontext), [FltDeleteStreamContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletestreamcontext), [FltDeleteInstanceContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeleteinstancecontext), and so on, the minifilter driver does not require a reference to the context. After the minifilter driver calls **FltDeleteContext**, that reference to the context is still valid. The minifilter driver must call the [FltReleaseContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasecontext) routine to release the reference to the context.

* **FltDeleteContext** removes the context from the internal filter manager structures. Then, further calls to functions that get contexts, such as [**FltGetContexts**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetcontexts) and [**FltGetInstanceContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetinstancecontext), cannot locate that context. However, the context memory is not released until the reference count for the context goes to 0.

Contexts can also be deleted by calling the appropriate delete-context routine from the following table.

| Context Type | Delete-Context Routine |
| ------------ | ---------------------- |
| FLT_FILE_CONTEXT | [FltDeleteFileContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletefilecontext) (Windows Vista and later only.) |
| FLT_INSTANCE_CONTEXT | [FltDeleteInstanceContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeleteinstancecontext) |
| FLT_SECTION_CONTEXT | [FltCloseSectionForDataScan](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltclosesectionfordatascan) (Windows 8 and later only.) |
| FLT_STREAM_CONTEXT | [FltDeleteStreamContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletestreamcontext) |
| FLT_STREAMHANDLE_CONTEXT | [FltDeleteStreamHandleContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletestreamhandlecontext) |
| FLT_TRANSACTION_CONTEXT | [FltDeleteTransactionContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletetransactioncontext) (Windows Vista and later only.) |
| FLT_VOLUME_CONTEXT | [FltDeleteVolumeContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletevolumecontext) |

To allocate a new context, call [FltAllocateContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecontext).

To increment the reference count on a context, call [FltReferenceContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreferencecontext).

To decrement the reference count on a context, call [FltReleaseContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasecontext).

A section context, FLT_SECTION_CONTEXT type, must not be deleted using **FltDeleteContext**. Instead, use [FltReleaseContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasecontext) to deallocate a section context.

## See also

[FltAllocateContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecontext)

[FltCloseSectionForDataScan](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltclosesectionfordatascan)

[FltDeleteFileContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletefilecontext)

[FltDeleteInstanceContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeleteinstancecontext)

[FltDeleteStreamContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletestreamcontext)

[FltDeleteStreamHandleContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletestreamhandlecontext)

[FltDeleteTransactionContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletetransactioncontext)

[FltDeleteVolumeContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletevolumecontext)

[FltReferenceContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreferencecontext)

[FltReleaseContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasecontext)