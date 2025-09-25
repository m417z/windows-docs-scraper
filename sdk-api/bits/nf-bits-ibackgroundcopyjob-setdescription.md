# IBackgroundCopyJob::SetDescription

## Description

Provides a description of the job.

## Parameters

### `Val` [in]

Null-terminated string that provides additional information about the job. The length of the string is limited to 1,024 characters, not including the null terminator.

## Return value

This method returns the following **HRESULT** values, as well as others.

| Return code | Description |
| --- | --- |
| ****S_OK**** | Description of the job was successfully set. |
| **E_INVALIDARG** | The *pDescription* parameter cannot be **NULL**. |
| **BG_E_STRING_TOO_LONG** | The description exceeds 1,024 characters. |
| **BG_E_INVALID_STATE** | The state of the job cannot be BG_JOB_STATE_CANCELLED or BG_JOB_STATE_ACKNOWLEDGED. |

## See also

[IBackgroundCopyJob::GetDescription](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-getdescription)