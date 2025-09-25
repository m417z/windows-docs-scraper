## Description

The Compare method compares two model-based objects for equality linguistically. It handles pointers and pointer coercion equality if necessary.

## Parameters

### `pLeft`

A pointer to the [IModelObject interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject) of the first object to be compared.

### `pRight`

A pointer to the [IModelObject interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject) of the second object to be compared.

### `ppResult`

A pointer to a pointer variable that receives the result [IModelObject interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject). This will contain the result of the comparison.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.

## Remarks

The Compare method is useful for linguistic and semantic comparisons of model-based objects, including checks for pointer and pointer coercion equality.

## See also

[IDebugHostEvaluator3 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostevaluator3)