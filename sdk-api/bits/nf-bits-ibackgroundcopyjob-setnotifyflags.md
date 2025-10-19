# IBackgroundCopyJob::SetNotifyFlags

## Description

Specifies the type of event notification you want to receive, such as job transferred events.

## Parameters

### `Val` [in]

Set one or more of the following flags to identify the events that you want to receive.

| Value | Meaning |
| --- | --- |
| **BG_NOTIFY_JOB_TRANSFERRED**<br><br>0x0001 | All of the files in the job have been transferred. |
| **BG_NOTIFY_JOB_ERROR**<br><br>0x0002 | An error has occurred. |
| **BG_NOTIFY_DISABLE**<br><br>0x0004 | Event notification is disabled. BITS ignores the other flags. |
| **BG_NOTIFY_JOB_MODIFICATION**<br><br>0x0008 | The job has been modified. For example, a property value changed, the state of the job changed, or progress is made transferring the files. This flag is ignored in command-line callbacks if [command line notification](https://learn.microsoft.com/windows/desktop/api/bits1_5/nf-bits1_5-ibackgroundcopyjob2-setnotifycmdline) is specified. |
| **BG_NOTIFY_FILE_TRANSFERRED**<br><br>0x0010 | A file in the job has been transferred. This flag is ignored in command-line callbacks if [command line notification](https://learn.microsoft.com/windows/desktop/api/bits1_5/nf-bits1_5-ibackgroundcopyjob2-setnotifycmdline) is specified. |
| **BG_NOTIFY_FILE_RANGES_TRANSFERRED**<br><br>0x0020 | A range of bytes in the file has been transferred. This flag is ignored in command-line callbacks if [command line notification](https://learn.microsoft.com/windows/desktop/api/bits1_5/nf-bits1_5-ibackgroundcopyjob2-setnotifycmdline) is specified. The flag can be specified for any job, but you will only get notifications for jobs that meet the requirements for a **BITS_JOB_PROPERTY_ON_DEMAND_MODE** job. |

## Return value

This method returns the following **HRESULT** values, as well as others.

| Return code | Description |
| --- | --- |
| **S_OK** | Type of event notification was successfully set. |
| **E_NOTIMPL** | The *NotifyFlags* value is not valid. |
| **BG_E_INVALID_STATE** | The state of the job cannot be BG_JOB_STATE_CANCELLED or BG_JOB_STATE_ACKNOWLEDGED. |

## Remarks

Use the
**SetNotifyFlags** method in conjunction with the
[IBackgroundCopyJob::SetNotifyInterface](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-setnotifyinterface) and
[IBackgroundCopyJob2::SetNotifyCmdLine](https://learn.microsoft.com/windows/desktop/api/bits1_5/nf-bits1_5-ibackgroundcopyjob2-setnotifycmdline) methods to receive event notification.

#### Examples

See the example code for the
[IBackgroundCopyJob::SetNotifyInterface](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-setnotifyinterface) method.

## See also

[IBackgroundCopyCallback](https://learn.microsoft.com/windows/desktop/api/bits/nn-bits-ibackgroundcopycallback)

[IBackgroundCopyCallback2](https://learn.microsoft.com/windows/desktop/api/bits3_0/nn-bits3_0-ibackgroundcopycallback2)

[IBackgroundCopyJob2::SetNotifyCmdLine](https://learn.microsoft.com/windows/desktop/api/bits1_5/nf-bits1_5-ibackgroundcopyjob2-setnotifycmdline)

[IBackgroundCopyJob::GetNotifyFlags](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-getnotifyflags)

[IBackgroundCopyJob::SetNotifyInterface](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-setnotifyinterface)