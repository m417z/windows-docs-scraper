# IDataObjectAsyncCapability::StartOperation

## Description

Called by a drop target to indicate that asynchronous data extraction is starting.

## Parameters

### `pbcReserved` [in, optional]

Type: **[IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx)***

Reserved. Set this value to **nullptr**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The drop target calls this method to notify the data object that asynchronous data extraction is starting. The method should store this information so that it can be returned by [IDataObjectAsyncCapability::InOperation](https://learn.microsoft.com/windows/desktop/api/shldisp/nf-shldisp-idataobjectasynccapability-inoperation). Once **StartOperation** has been called, the drop target returns the [IDropTarget::Drop](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-idroptarget-drop) call as it would for normal synchronous data extraction.

## See also

[IDataObjectAsyncCapability](https://learn.microsoft.com/windows/desktop/api/shldisp/nn-shldisp-idataobjectasynccapability)