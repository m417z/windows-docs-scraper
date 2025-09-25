# IDataObjectAsyncCapability::EndOperation

## Description

Notifies the data object that the asynchronous data extraction has ended.

## Parameters

### `hResult` [in]

Type: **HRESULT**

Indicates the outcome of the data extraction. Set this value to S_OK if successful, or a COM error code otherwise.

### `pbcReserved` [in]

Type: **[IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx)***

Reserved. Set to **nullptr**.

### `dwEffects` [in]

Type: **DWORD**

A [DROPEFFECT](https://learn.microsoft.com/windows/desktop/com/dropeffect-constants) value that indicates the result of an optimized move. This should be the same value that would be passed to the data object as a CFSTR_PERFORMEDDROPEFFECT format with a normal data extraction operation.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**EndOperation** retrieves the [IDataObjectAsyncCapability](https://learn.microsoft.com/windows/desktop/api/shldisp/nn-shldisp-idataobjectasynccapability) pointer stored by [IDataObjectAsyncCapability::SetAsyncMode](https://learn.microsoft.com/windows/desktop/api/shldisp/nf-shldisp-idataobjectasynccapability-setasyncmode) and passes its parameter values to that interface's **IDataObjectAsyncCapability::EndOperation** method. **EndOperation** then releases the **IDataObjectAsyncCapability** pointer.

**EndOperation** is also responsible for any associated clean-up operations. When finished, **EndOperation** should notify the drop source through a private interface.

## See also

[IDataObjectAsyncCapability](https://learn.microsoft.com/windows/desktop/api/shldisp/nn-shldisp-idataobjectasynccapability)