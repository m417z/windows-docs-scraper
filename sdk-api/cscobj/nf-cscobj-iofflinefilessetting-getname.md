# IOfflineFilesSetting::GetName

## Description

Retrieves a name associated with a particular Offline Files setting.

## Parameters

### `ppszName` [out]

Address of pointer variable that receives the address of a string containing the name of the Offline Files setting. Upon successful return, the caller must free this memory block by using the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function.

## Return value

Returns **S_OK** if successful, or an error value otherwise.

## See also

[IOfflineFilesSetting](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilessetting)