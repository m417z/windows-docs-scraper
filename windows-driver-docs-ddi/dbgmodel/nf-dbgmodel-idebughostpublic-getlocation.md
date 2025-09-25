# IDebugHostPublic::GetLocation

## Description

For data which has an address, the GetLocation method will return the abstract location (address) of the field.

If the given public does not have a static location, the GetLocation method will fail.

## Parameters

### `location`

The abstract location (e.g.: address) of the data will be returned here.

## Return value

This method returns HRESULT which indicates success or failure.

## Remarks

**Sample Code**

```cpp
ComPtr<IDebugHostPublic> spPublic; /* get a public symbol (see EnumerateChildren) */

Location publicLocation;
if (SUCCEEDED(spPublic->GetLocation(&publicLocation)))
{
    // For public symbols which indicate they have a static location
    // via GetLocationKind, publicLocation will be the location of the symbol
}

```

## See also

[IDebugHostPublic interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostpublic)