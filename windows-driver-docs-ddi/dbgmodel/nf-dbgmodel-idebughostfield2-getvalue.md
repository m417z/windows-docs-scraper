## Description

For fields which have a constant value defined within the symbolic information (e.g.: fields whose location kind indicates LocationConstant), the GetValue method will return the constant value of the field.

If the given field does not have a constant value, the GetValue method will fail.

## Parameters

### `value`

The value of the field packed into a VARIANT will be returned here.

## Return value

This method returns HRESULT which indicates success or failure.

## Remarks

**Sample Code**

```cpp
ComPtr<IDebugHostField> spField; /* get a field (see EnumerateChildren) */

VARIANT vtValue;
if (SUCCEEDED(spField->GetValue(&vtValue)))
{
    // For fields which have a constant value as determined by GetLocationKind,
    // vtValue will contain the value of the field.
    VariantClear(&vtValue);
}
```

## See also

[IDebugHostField2 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostfield2)