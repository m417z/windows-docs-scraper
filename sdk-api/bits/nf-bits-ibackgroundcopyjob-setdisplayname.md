# IBackgroundCopyJob::SetDisplayName

## Description

Specifies a display name for the job. Typically, you use the display name to identify the job in a user interface.

## Parameters

### `Val` [in]

Null-terminated string that identifies the job. Must not be **NULL**. The length of the string is limited to 256 characters, not including the null terminator.

## Return value

This method returns the following **HRESULT** values, as well as others.

| Return code | Description |
| --- | --- |
| **S_OK** | Display name was successfully set. |
| **E_INVALIDARG** | The *pDisplayName* parameter cannot be **NULL** or the name exceeds 256 characters. |
| **BG_E_STRING_TOO_LONG** | The display name exceeds 256 characters. |
| **BG_E_INVALID_STATE** | The state of the job cannot be BG_JOB_STATE_CANCELLED or BG_JOB_STATE_ACKNOWLEDGED. |

## Remarks

The display name is originally set when you create the job. For details on specifying the display name when you create the job, see the
[IBackgroundCopyManager::CreateJob](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopymanager-createjob) method.

## See also

[IBackgroundCopyJob::GetDisplayName](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-getdisplayname)

[IBackgroundCopyManager::CreateJob](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopymanager-createjob)