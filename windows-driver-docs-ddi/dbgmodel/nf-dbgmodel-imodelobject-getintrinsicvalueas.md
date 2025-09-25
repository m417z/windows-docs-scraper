# IModelObject::GetIntrinsicValueAs

## Description

The GetIntrinsicValueAs method behaves much as the GetIntrinsicValue method excepting that it converts the value to the specified variant type. If the conversion cannot be performed, the method returns an error.

## Parameters

### `vt`

The type of value to convert to is passed here as a VARTYPE. Legal values are VT_I1 through VT_I8, VT_U1 through VT_U8, VT_R4 through VT_R8, and VT_BOOL. String conversions cannot be performed through this method.

### `intrinsicData`

The value boxed inside the [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject) converted to the type described by the vt argument is returned here. The pointer must point to a VARIANT structure which does not contain a freeable value. It is the responsibility of the caller to clear this VARIANT with VariantClear when finished with it.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Code Sample**

```cpp
ComPtr<IModelObject> spObject; /* get from somewhere */

// Unbox as VT_I4.  This will fail if the value does not FIT into an int (I4):
VARIANT vtVal;
HRESULT hr = spObject->GetIntrinsicValueAs(VT_I4, &vtVal);
if (SUCCEEDED(hr))
{
    int iVal = vtVal.lVal; // The object has successfully packed into an I4 and been unboxed as an int.
}
// Since we know this is a VT_I4, VariantClear is superfluous.
```

## See also

[IModelObject interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject)