# IDebugHostData::GetLocation

## Description

For data which has an address, the GetLocation method will return the abstract location (address) of the field.
If the given data does not have a static location, the GetLocation method will fail.

## Parameters

### `location`

The abstract location (e.g.: address) of the data will be returned here.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Sample Code**

```cpp
ComPtr<IDebugHostData> spData; /* get a data symbol */

Location dataLocation;
if (SUCCEEDED(spData->GetLocation(&dataLocation)))
{
    // For data which has a static location as determined by
    // GetLocationKind, dataLocation contains the location of the data
}
```

## See also

[IDebugHostData interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostdata)