# IBackgroundCopyJob::SetNotifyInterface

## Description

Identifies your implementation of the
[IBackgroundCopyCallback](https://learn.microsoft.com/windows/desktop/api/bits/nn-bits-ibackgroundcopycallback) interface to BITS. Use the
**IBackgroundCopyCallback** interface to receive notification of job-related events.

## Parameters

### `Val`

An
[IBackgroundCopyCallback](https://learn.microsoft.com/windows/desktop/api/bits/nn-bits-ibackgroundcopycallback) interface pointer. To remove the current callback interface pointer, set this parameter to **NULL**.

## Return value

This method returns the following **HRESULT** values, as well as others.

| Return code | Description |
| --- | --- |
| ****S_OK**** | Notification interface pointer was successfully set. |
| **BG_E_INVALID_STATE** | The state of the job cannot be BG_JOB_STATE_CANCELLED or BG_JOB_STATE_ACKNOWLEDGED. |

## Remarks

Call this method only if you implement the
[IBackgroundCopyCallback](https://learn.microsoft.com/windows/desktop/api/bits/nn-bits-ibackgroundcopycallback) interface. Use the
**SetNotifyInterface** method in conjunction with the
[SetNotifyFlags](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-setnotifyflags) method to specify the type of notification that you want to receive.

The notification interface becomes invalid when your application terminates; BITS does not persist the notify interface. As a result, your application's initialization process should call the
**SetNotifyInterface** method on those existing jobs for which you want to receive notification. If you need to capture state and progress information that occurred since the last time your application was run, poll for state and progress information during application initialization.

Note that BITS will call your callback even if the event for which you registered already occurred.

As an alternative to receiving callback notification, you can register to have BITS execute a command line for error and transferred events. For more details, see the
[IBackgroundCopyJob2::SetNotifyCmdLine](https://learn.microsoft.com/windows/desktop/api/bits1_5/nf-bits1_5-ibackgroundcopyjob2-setnotifycmdline) method.

Note that if more than one application calls the **SetNotifyInterface** method to set the notification interface for the job, the last application to call the **SetNotifyInterface** method is the one that will receive notifications—the other applications will not receive notifications.

#### Examples

The following example shows how to call the
**SetNotifyInterface** method. For details on the CNotifyInterface example class used in the following example, see the
[IBackgroundCopyCallback](https://learn.microsoft.com/windows/desktop/api/bits/nn-bits-ibackgroundcopycallback) interface. The example assumes the
[IBackgroundCopyJob](https://learn.microsoft.com/windows/desktop/api/bits/nn-bits-ibackgroundcopyjob) interface pointer is valid.

```cpp
IBackgroundCopyJob* pJob;
CNotifyInterface* pNotify = new CNotifyInterface();

hr = pJob->SetNotifyInterface(pNotify);
if (SUCCEEDED(hr))
{
  hr = pJob->SetNotifyFlags(BG_NOTIFY_JOB_TRANSFERRED |
                            BG_NOTIFY_JOB_ERROR);
}
pNotify->Release();
pNofity = NULL;

if (FAILED(hr))
{
  //Handle error - unable to register for event notification.
}
```

## See also

[IBackgroundCopyCallback](https://learn.microsoft.com/windows/desktop/api/bits/nn-bits-ibackgroundcopycallback)

[IBackgroundCopyJob2::SetNotifyCmdLine](https://learn.microsoft.com/windows/desktop/api/bits1_5/nf-bits1_5-ibackgroundcopyjob2-setnotifycmdline)

[IBackgroundCopyJob::GetNotifyInterface](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-getnotifyinterface)

[IBackgroundCopyJob::SetNotifyFlags](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-setnotifyflags)