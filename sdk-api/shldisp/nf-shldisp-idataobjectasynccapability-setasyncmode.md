# IDataObjectAsyncCapability::SetAsyncMode

## Description

Called by a drop source to specify whether the data object supports asynchronous data extraction.

## Parameters

### `fDoOpAsync` [in]

Type: **BOOL**

**VARIANT_TRUE** if an asynchronous operation is supported; otherwise, **VARIANT_FALSE**. The default value is **VARIANT_FALSE**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is called by the drop source to indicate that the data object supports asynchronous data extraction. Store the *fDoOpAsync* for later use by [IDataObjectAsyncCapability::GetAsyncMode](https://learn.microsoft.com/windows/desktop/api/shldisp/nf-shldisp-idataobjectasynccapability-getasyncmode). The drop target determines whether asynchronous data extraction is supported by calling **IDataObjectAsyncCapability::GetAsyncMode** to retrieve the *fDoOpAsync* value.

If *fDoOpAsync* is set to **VARIANT_TRUE**, **SetAsyncMode** must call [IDataObjectAsyncCapability::AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref), and store the interface pointer for use by [IDataObjectAsyncCapability::EndOperation](https://learn.microsoft.com/windows/desktop/api/shldisp/nf-shldisp-idataobjectasynccapability-endoperation).

## See also

[IDataObjectAsyncCapability](https://learn.microsoft.com/windows/desktop/api/shldisp/nn-shldisp-idataobjectasynccapability)