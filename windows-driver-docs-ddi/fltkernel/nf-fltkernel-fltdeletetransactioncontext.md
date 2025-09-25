# FltDeleteTransactionContext function

## Description

The **FltDeleteTransactionContext** routine removes a context from a given transaction and marks the context for deletion.

## Parameters

### `Instance` [in]

Opaque instance pointer for the caller.

### `Transaction` [in]

Opaque transaction pointer for the transaction whose context is being deleted.

### `OldContext` [out, optional]

Pointer to a caller-allocated variable that receives the address of the deleted context. This parameter is optional and can be **NULL**. If *OldContext* is not **NULL** and does not point to NULL_CONTEXT, the caller is responsible for calling [**FltReleaseContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasecontext) to release this context when it is no longer needed.

## Return value

**FltDeleteTransactionContext** returns STATUS_SUCCESS or an appropriate NTSTATUS value such as the following:

| Return code | Description |
| ----------- | ----------- |
| STATUS_FLT_DELETING_OBJECT | The specified *Instance* is being torn down. This is an error code. |
| STATUS_NOT_FOUND | No matching context was found. This is an error code. |

## Remarks

For more information about contexts, see [About minifilter contexts](https://learn.microsoft.com/windows-hardware/drivers/ifs/managing-contexts-in-a-minifilter-driver).

Because contexts are reference-counted, it is not usually necessary for a minifilter driver to call a routine such as **FltDeleteTransactionContext** to explicitly delete a context.

A minifilter driver calls **FltDeleteTransactionContext** to remove a context from a transaction and mark the context for deletion. The context is usually freed immediately unless there is an outstanding reference on it (for example, because the context is still being used by another thread).

To allocate a new context, call [**FltAllocateContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecontext).

To retrieve a transaction context, call [**FltGetTransactionContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgettransactioncontext).

To set a transaction context, call [**FltSetTransactionContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsettransactioncontext).

## See also

[**FltAllocateContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecontext)

[**FltDeleteContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletecontext)

[**FltCommitComplete**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcommitcomplete)

[**FltEnlistInTransaction**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenlistintransaction)

[**FltGetTransactionContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgettransactioncontext)

[**FltPrePrepareComplete**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltprepreparecomplete)

[**FltPrepareComplete**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltpreparecomplete)

[**FltReleaseContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasecontext)

[**FltRollbackComplete**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltrollbackcomplete)

[**FltRollbackEnlistment**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltrollbackenlistment)

[**FltSetTransactionContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsettransactioncontext)