# IEnumOfflineFilesSettings::Next

## Description

Retrieves the next item in the enumeration and advances the enumerator.

## Parameters

### `celt` [in]

Number of elements requested.

### `rgelt` [out]

Array of elements returned.

### `pceltFetched` [out]

Number of elements returned.

## Return value

Returns **S_OK** if the number of elements returned is *celt*; S_FALSE if a number less than *celt* is returned; or an error value otherwise.

## See also

[IEnumOfflineFilesSettings](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-ienumofflinefilessettings)