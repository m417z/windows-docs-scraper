# IDebugHostData::GetValue

## Description

Returns the value of the constant in a VARIANT data structure.

## Parameters

### `value`

The value of the data packed into a VARIANT will be returned here.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Sample Code**

```cpp
ComPtr<IDebugHostData> spData; /* get a data symbol */

VARIANT vtValue;
if (SUCCEEDED(spData->GetValue(&vtValue)))
{
    // For data which has a constant value as determined by GetLocationKind,
    // vtValue contains the value of the data
    VariantClear(&vtValue);
}
```

## See also

[IDebugHostData interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostdata)