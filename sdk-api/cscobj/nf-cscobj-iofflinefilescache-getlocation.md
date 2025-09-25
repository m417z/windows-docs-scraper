# IOfflineFilesCache::GetLocation

## Description

Retrieves the current fully qualified directory path of the Offline Files cache.

## Parameters

### `ppszPath` [out]

Address of pointer variable to accept the address of a string containing the fully qualified path of the Offline Files cache directory. Upon successful return, the caller is expected to free the returned buffer by using the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function.

## Return value

Returns **S_OK** if successful, or an error value otherwise.

## See also

[IOfflineFilesCache](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilescache)