# UninitializeNapAgentNotifier function

> [!Note]
> The Network Access Protection platform is not available starting with Windows 10

The **UninitializeNapAgentNotifier** function unsubscribes the calling process from NapAgent state change notifications and quarantine state change notifications. These notifications are provided by the NapAgent service.

## Parameters

*type* \[in\]

A [**NapNotifyType**](https://learn.microsoft.com/windows/win32/api/naptypes/ne-naptypes-napnotifytype) value that specifies the type of service notifications to unsubscribe from.

## Return value

This function has no return values.

## Remarks

This function is not thread safe.

Each process subscribed to NapAgent service notifications of the specified *type* must call **UninitializeNapAgentNotifier** to unsubscribe from notifications. If a process is subscribed to more than one type of notification, it must call **UninitializeNapAgentNotifier** once for each type of notification.

This function will fail silently if the process had not previously called [**InitializeNapAgentNotifier**](https://learn.microsoft.com/windows/win32/nap/initializenapagentnotifier) for the notification type.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| Header<br> | NapUtil.h |
| DLL<br> | Qutil.dll |

## See also

[**InitializeNapAgentNotifier**](https://learn.microsoft.com/windows/win32/nap/initializenapagentnotifier)

