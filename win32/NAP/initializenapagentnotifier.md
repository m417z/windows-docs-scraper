# InitializeNapAgentNotifier function

> [!Note]
> The Network Access Protection platform is not available starting with Windows 10

The **InitializeNapAgentNotifier** function subscribes the calling process to NapAgent state change notifications and quarantine state change notifications. These notifications are provided by the NapAgent service.

## Parameters

*type* \[in\]

A [**NapNotifyType**](https://learn.microsoft.com/windows/win32/api/naptypes/ne-naptypes-napnotifytype) value that specifies the type of service notifications to receive.

*hNotifyEvent* \[in\]

An event handle used for notification. The caller must pass an open handle to the *hNotifyEvent* parameter. The caller must also close the event handle when it is no longer needed.

## Return value

| Return code | Description |
|------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------|
| **S\_OK** | Initialization completed successfully.<br> |
| **E\_FAIL** | Initialization failed.<br> |
| **ERROR\_ALREADY\_INITIALIZED** | The process has already subscribed to NapAgent service notifications of the *type* specified. <br> |
| **E\_INVALIDARG** | An invalid argument was passed. <br> |

## Remarks

This function is not thread safe.

Each process that requires a subscription to NapAgent service notifications of the specified *type* must call **InitializeNapAgentNotifier** to subscribe to notifications. If a process must subscribe to more than one type of notification, it must call **InitializeNapAgentNotifier** once for each type of notification.

Once a process does not require further notifications, the process must call [**UninitializeNapAgentNotifier**](https://learn.microsoft.com/windows/win32/nap/uninitializenapagentnotifier) for the specified *type*.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| Header<br> | NapUtil.h |
| DLL<br> | Qutil.dll |

## See also

[**UninitializeNapAgentNotifier**](https://learn.microsoft.com/windows/win32/nap/uninitializenapagentnotifier)

