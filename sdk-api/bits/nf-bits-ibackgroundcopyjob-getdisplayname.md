# IBackgroundCopyJob::GetDisplayName

## Description

Retrieves the display name for the job. Typically, you use the display name to identify the job in a user interface.

## Parameters

### `pVal` [out]

Null-terminated string that contains the display name that identifies the job. More than one job can have the same display name. Call the
[CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function to free *ppDisplayName* when done.

## Return value

This method returns the following **HRESULT** values, as well as others.

| Return code | Description |
| --- | --- |
| ****S_OK**** | Display name was successfully retrieved. |
| **E_INVALIDARG** | The *ppDisplayName* parameter cannot be **NULL**. |

## See also

[IBackgroundCopyJob::SetDisplayName](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-setdisplayname)