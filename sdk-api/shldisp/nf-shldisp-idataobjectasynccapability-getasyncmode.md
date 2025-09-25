# IDataObjectAsyncCapability::GetAsyncMode

## Description

Called by a drop target to determine whether the data object supports asynchronous data extraction.

## Parameters

### `pfIsOpAsync` [out]

Type: **BOOL***

**VARIANT_TRUE** if an asynchronous operation is supported; otherwise, **VARIANT_FALSE**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The purpose of this method is to give the drop target the value of the [IDataObjectAsyncCapability::SetAsyncMode](https://learn.microsoft.com/windows/desktop/api/shldisp/nf-shldisp-idataobjectasynccapability-setasyncmode) method's *fDoOpAsync* parameter. This parameter is set to **VARIANT_FALSE** by default. If the data object supports asynchronous data extraction, it must call **IDataObjectAsyncCapability::SetAsyncMode** and set *fDoOpAsync* to **VARIANT_TRUE**.

## See also

[IDataObjectAsyncCapability](https://learn.microsoft.com/windows/desktop/api/shldisp/nn-shldisp-idataobjectasynccapability)