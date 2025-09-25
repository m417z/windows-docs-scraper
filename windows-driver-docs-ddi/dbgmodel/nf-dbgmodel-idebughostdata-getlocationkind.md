# IDebugHostData::GetLocationKind

## Description

The GetLocationKind method returns what kind of location the symbol is at according to the LocationKind enumeration. The description of this enumeration can be found in the documentation for [IDebugHostField](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostfield).

## Parameters

### `locationKind`

The kind of location for this field will be returned here as a value of the LocationKind enumeration.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Sample Code**

```cpp
ComPtr<IDebugHostData> spData; /* get a data symbol */

LocationKind kind;
if (SUCCEEDED(spData->GetLocationKind(&kind)))
{
    // kind indicates the kind of location (e.g.: static, constant, member, etc...)
}
```

## See also

[IDebugHostData interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostdata)