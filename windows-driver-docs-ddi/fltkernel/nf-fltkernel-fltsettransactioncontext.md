# FltSetTransactionContext function

## Description

The **FltSetTransactionContext** routine sets a context on a transaction.

## Parameters

### `Instance` [in]

Opaque instance pointer for the caller.

### `Transaction` [in]

Opaque transaction pointer for the transaction on which the context is being set.

### `Operation` [in]

Flag that specifies the details of the operation to be performed. This parameter must be one of the following:

| Flag | Meaning |
| ---- | ------- |
| FLT_SET_CONTEXT_REPLACE_IF_EXISTS | If a context is already set for the transaction pointed to by the *Transaction* parameter, **FltSetTransactionContext** will replace it with the context pointed to by the *NewContext* parameter. Otherwise, it will set the context pointed to by the *NewContext* parameter as the context for the transaction pointed to by the *Transaction* parameter. |
| FLT_SET_CONTEXT_KEEP_IF_EXISTS | If a context is already set for the transaction pointed to by the *Transaction* parameter, **FltSetTransactionContext** will return STATUS_FLT_CONTEXT_ALREADY_DEFINED, and will not replace the existing context or increment the reference count. If a context has not already been set, this routine will set the context pointed to by the *NewContext* parameter as the context for transaction pointed to by the *Transaction* parameter, and will increment the reference count. |

### `NewContext` [in]

Pointer to the new context to be set for the transaction. This parameter is required and cannot be **NULL**.

### `OldContext` [out, optional]

Pointer to a caller-allocated variable that receives the address of the existing transaction context, if one is already set. This parameter is optional and can be **NULL**. For more information about this parameter, see the following Remarks section.

## Return value

**FltSetTransactionContext** returns STATUS_SUCCESS or an appropriate NTSTATUS value such as one of the following:

| Return code | Description |
| ----------- | ----------- |
| STATUS_FLT_CONTEXT_ALREADY_DEFINED | If FLT_SET_CONTEXT_KEEP_IF_EXISTS was specified for the *Operation* parameter, this error code indicates that a context is already attached to the transaction. Only one context can be attached to a transaction for a given minifilter driver. |
| STATUS_FLT_CONTEXT_ALREADY_LINKED | The context pointed to by the *NewContext* parameter is already linked to an object. In other words, this error code indicates that *NewContext* is already in use due to a successful prior call of an **FltSet***Xxx***Context** routine. |
| STATUS_FLT_DELETING_OBJECT |
| The instance specified in the *Instance* parameter is being torn down. This is an error code. |
| STATUS_INVALID_PARAMETER | An invalid parameter was passed. For example, the *NewContext* parameter does not point to a valid transaction context, or an invalid value was specified for the *Operation* parameter. This is an error code. |

## Remarks

For more information about contexts, see [About minifilter contexts](https://learn.microsoft.com/windows-hardware/drivers/ifs/managing-contexts-in-a-minifilter-driver).

A minifilter driver calls **FltSetTransactionContext** to attach a context to a transaction or to remove or replace an existing transaction context. A minifilter driver can attach only one context to a given transaction.

### Reference Counting

If **FltSetTransactionContext** succeeds:

- The reference count on *NewContext* is incremented. When *NewContext* is no longer needed, the minifilter must call [**FltReleaseContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasecontext) to decrement its reference count.

Else if **FltSetTransactionContext** fails:

- The reference count on *NewContext* remains unchanged.
- If *OldContext* is not **NULL** and does not point to NULL_CONTEXT then *OldContext* is a referenced pointer to the context currently associated with the transaction. The filter calling **FltSetTransactionContext** must call **FltReleaseContext** for *OldContext* as well when the context pointer is no longer needed.

Regardless of success:

- The filter calling **FltSetTransactionContext** must call [**FltReleaseContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasecontext) to decrement the reference count on the *NewContext* object that was incremented by [**FltAllocateContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecontext).

For more information, see [Referencing Contexts](https://learn.microsoft.com/windows-hardware/drivers/ifs/referencing-contexts).

### Other context operations

For more information, see [Setting Contexts](https://learn.microsoft.com/windows-hardware/drivers/ifs/setting-contexts), and [Releasing Contexts](https://learn.microsoft.com/windows-hardware/drivers/ifs/releasing-contexts):

- To allocate a new context, call [**FltAllocateContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecontext).

To get a transaction context, call [**FltGetTransactionContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgettransactioncontext).

- To delete a transaction context, call [**FltDeleteTransactionContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletetransactioncontext) or [**FltDeleteContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletecontext).

## See also

[**FltAllocateContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecontext)

[**FltCommitComplete**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcommitcomplete)

[**FltDeleteContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletecontext)

[**FltDeleteTransactionContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletetransactioncontext)

[**FltEnlistInTransaction**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenlistintransaction)

[**FltGetTransactionContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgettransactioncontext)

[**FltPrePrepareComplete**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltprepreparecomplete)

[**FltPrepareComplete**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltpreparecomplete)

[**FltReleaseContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasecontext)

[**FltRollbackComplete**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltrollbackcomplete)

[**FltRollbackEnlistment**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltrollbackenlistment)