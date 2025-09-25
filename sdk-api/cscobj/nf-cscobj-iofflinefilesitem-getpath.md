# IOfflineFilesItem::GetPath

## Description

Retrieves the fully qualified UNC path string for an item in the Offline Files cache.

## Parameters

### `ppszPath` [out]

Receives the fully qualified UNC path of the item. The caller is responsible for freeing the path buffer by using the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function.

## Return value

Returns **S_OK** if successful, or an error value otherwise.

## See also

[IOfflineFilesItem](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesitem)