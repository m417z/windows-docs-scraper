# IDebugHostField::GetLocation

## Description

For fields which have an address regardless of the particular type instance (e.g. fields whose location kind indicates LocationStatic), the GetLocation method will return the abstract location (address) of the field.

If the given field does not have a static location, the GetLocation method will fail.

## Parameters

### `location`

The abstract location (e.g.: address) of the field will be returned here.

## Return value

This method returns HRESULT which indicates success or failure.

## Remarks

**Sample Code***
```cpp
ComPtr<IDebugHostField> spField; /* get a field symbol (see EnumerateChildren) */

Location fieldLocation;
if (SUCCEEDED(spField->GetLocation(&fieldLocation)))
{
    // For fields which have a static location as determined by GetLocationKind,
    // the location of the field will be in fieldLocation.
}
```

## See also

[IDebugHostField interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostfield)