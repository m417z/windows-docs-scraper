# IScheduledWorkItem::GetAccountInformation

## Description

[[This API may be altered or unavailable in subsequent versions of the operating system or product. Please use the [Task Scheduler 2.0 Interfaces](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-2-0-interfaces) instead.] ]

Retrieves the account name for the [work item](https://learn.microsoft.com/windows/desktop/TaskSchd/w).

## Parameters

### `ppwszAccountName` [out]

A pointer to a null-terminated string that contains the account name for the current work item. The empty string, L"", is returned for the local system account.

After processing the account name, be sure to call **CoTaskMemFree** to free the string.

## Return value

The
**GetAccountInformation** method returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_INVALIDARG** | The arguments are not valid. |
| **E_OUTOFMEMORY** | Not enough memory is available. |
| **SCHED_E_ACCOUNT_INFORMATION_NOT_SET** | The account information has not been set for the work item. |
| **SCHED_E_NO_SECURITY_SERVICES** | Security services are available only on the Windows Server 2003, Windows 2000, and Windows XP operating systems. |

## Remarks

The
**GetAccountInformation** method is for the Windows Server 2003, Windows XP, and Windows 2000 operating systems.

#### Examples

For more information and an example of how to retrieve the account information of a task, see [C/C++ Code Example: Retrieving Task Account Information](https://learn.microsoft.com/windows/desktop/TaskSchd/c-c-code-example-retrieving-task-account-information).

## See also

[IScheduledWorkItem](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-ischeduledworkitem)

[IScheduledWorkItem::SetAccountInformation](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-ischeduledworkitem-setaccountinformation)