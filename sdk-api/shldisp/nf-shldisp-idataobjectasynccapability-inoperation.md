# IDataObjectAsyncCapability::InOperation

## Description

Called by the drop source to determine whether the target is extracting data asynchronously.

## Parameters

### `pfInAsyncOp` [out]

Type: **BOOL***

**VARIANT_TRUE** if data extraction is being handled asynchronously; otherwise, **VARIANT_FALSE**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is called by the drop source after [DoDragDrop](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-dodragdrop) returns. The *pfInAsyncOp* parameter should be set to **VARIANT_TRUE** only if the drop target has called [IDataObjectAsyncCapability::StartOperation](https://learn.microsoft.com/windows/desktop/api/shldisp/nf-shldisp-idataobjectasynccapability-startoperation).

## See also

[IDataObjectAsyncCapability](https://learn.microsoft.com/windows/desktop/api/shldisp/nn-shldisp-idataobjectasynccapability)