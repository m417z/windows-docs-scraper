# IBackgroundCopyJob::GetNotifyFlags

## Description

Retrieves the event notification flags for the job.

## Parameters

### `pVal` [out]

Identifies the events that your application receives. The following table lists the event notification flag values.

| Value | Meaning |
| --- | --- |
| **BG_NOTIFY_JOB_TRANSFERRED** | All of the files in the job have been transferred. |
| **BG_NOTIFY_JOB_ERROR** | An error has occurred. |
| **BG_NOTIFY_DISABLE** | Event notification is disabled. If set, BITS ignores the other flags. |
| **BG_NOTIFY_JOB_MODIFICATION** | The job has been modified. |

## Return value

This method returns the following **HRESULT** values, as well as others.

| Return code | Description |
| --- | --- |
| ****S_OK**** | Event notify flags were successfully retrieved. |
| **E_INVALIDARG** | Must pass the address of *pNotifyFlags*. |

## See also

[IBackgroundCopyCallback](https://learn.microsoft.com/windows/desktop/api/bits/nn-bits-ibackgroundcopycallback)

[IBackgroundCopyJob::GetNotifyInterface](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-getnotifyinterface)

[IBackgroundCopyJob::SetNotifyFlags](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-setnotifyflags)