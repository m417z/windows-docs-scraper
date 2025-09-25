# IModelObject::GetIntrinsicValue

## Description

The GetIntrinsicValue method returns the thing which is boxed inside an [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject). This method may only legally be called on [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject) interfaces which represent a boxed intrinsic or a particular interface which is boxed. It cannot be called on native objects, no value objects, synthetic objects, and reference objects.

## Parameters

### `intrinsicData`

The value boxed inside the [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject) is returned here. The pointer must point to a VARIANT structure which does not contain a freeable value. It is the responsibility of the caller to clear this VARIANT with VariantClear when finished with it.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Code Sample**

```cpp
ComPtr<IModelObject> spObject; /* get something */

VARIANT vtVal;
HRESULT hr = spObject->GetIntrinsicValue(&vtVal);
if (SUCCEEDED(hr) && vtVal.vt == VT_I4)
{
    int iVal = vtVal.lVal; // An integer has been unboxed into iVal.
}
VariantClear(&vtVal);
```

## See also

[IModelObject interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject)