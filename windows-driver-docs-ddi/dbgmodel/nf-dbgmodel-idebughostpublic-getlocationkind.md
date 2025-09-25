# IDebugHostPublic::GetLocationKind

## Description

The GetLocationKind method returns what kind of location the symbol is at according to the LocationKind enumeration. The description of this enumeration can be found in the documentation for [IDebugHostField](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostfield).

## Parameters

### `locationKind`

The kind of location for this field will be returned here as a value of the LocationKind enumeration.

## Return value

This method returns HRESULT which indicates success or failure.

## Remarks

**Sample Code**

```cpp
ComPtr<IDebugHostPublic> spPublic; /* get a public symbol (see EnumerateChildren) */

LocationKind kind;
if (SUCCEEDED(spPublic->GetLocationKind(&kind)))
{
    // kind indicates the kind of location (static, none).
}
```

## See also

[IDebugHostPublic interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostpublic)