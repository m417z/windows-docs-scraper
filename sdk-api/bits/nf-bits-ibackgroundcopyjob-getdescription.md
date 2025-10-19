# IBackgroundCopyJob::GetDescription

## Description

Retrieves the description of the job.

## Parameters

### `pVal` [out]

Null-terminated string that contains a short description of the job. Call the
[CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function to free *ppDescription* when done.

## Return value

This method returns the following **HRESULT** values, as well as others.

| Return code | Description |
| --- | --- |
| **S_OK** | Description of the job was successfully retrieved. |
| **E_INVALIDARG** | The parameter, *ppDescription*, cannot be **NULL**. |

## See also

[IBackgroundCopyJob::SetDescription](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-setdescription)