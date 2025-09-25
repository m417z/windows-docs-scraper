# IScheduledWorkItem::SetAccountInformation

## Description

[[This API may be altered or unavailable in subsequent versions of the operating system or product. Please use the [Task Scheduler 2.0 Interfaces](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-2-0-interfaces) instead.] ]

Sets the account name and password used to run the [work item](https://learn.microsoft.com/windows/desktop/TaskSchd/w).

## Parameters

### `pwszAccountName` [in]

A string that contains the **null**-terminated name of the user account in which the work item will run. To specify the local system account, use the empty string, L"". Do not use any other string to specify the local system account. For more information, see Remarks.

### `pwszPassword` [in]

A string that contains the password for the account specified in *pwszAccountName*.

Set this parameter to **NULL** if the local system account is specified. If you set the TASK_FLAG_RUN_ONLY_IF_LOGGED_ON flag, you may also set *pwszPassword* to **NULL** for local or domain user accounts. Use the [IScheduledWorkItem::SetFlags](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-ischeduledworkitem-setflags) method to set the flag.

Task Scheduler stores account information only once for all tasks that use the same account. If the account password is updated for one task, then all tasks using that same account will use the updated password.

When you have finished using the password, clear the password information by calling the [SecureZeroMemory](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa366877(v=vs.85)) function. For more information about protecting passwords, see [Handling Passwords](https://learn.microsoft.com/windows/desktop/SecBP/handling-passwords).

## Return value

The
**SetAccountInformation** method returns one of the following values. Note that errors from this call may also be returned by the subsequent call to [IPersistFile::Save](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersistfile-save).

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_ACCESSDENIED** | The caller does not have permission to perform the operation. For more information, see Remarks. |
| **E_INVALIDARG** | The arguments are not valid. |
| **E_OUTOFMEMORY** | Not enough memory is available. |
| **SCHED_E_NO_SECURITY_SERVICES** | Security services are available only on the Windows Server 2003, Windows XP, and Windows 2000. |
| **SCHED_E_UNSUPPORTED_ACCOUNT_OPTION** | The *pwszPassword* parameter was set to **NULL**, but the TASK_FLAG_RUN_ONLY_IF_LOGGED_ON flag was not set. |
| **SCHED_E_ACCOUNT_INFORMATION_NOT_SET** | The *pwszPassword* parameter was incorrect. In the Windows Server 2003, Task Scheduler validates the password at the time the job is created (during a call to [IPersistFile::Save](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersistfile-save)). Be aware that if this error occurs, the job file will still be created. |

## Remarks

This method is for the Windows Server 2003, Windows XP, and Windows 2000.

If *pwszAccountName* specifies the local system account, the caller must be an administrator on the local computer or an application running in the local system account. If not, this method will fail.

The password specified in *pwszPassword* is used to log on to the account when the work item is run. An incorrect password will result in an error when the work item is run. In the Windows Server 2003, however, Task Scheduler validates the password at the time the job is created (during a call to [IPersistFile::Save](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersistfile-save)).

Typically, passwords have an expiration date. If you schedule tasks that run indefinitely, you must update the task to reflect the new password.

 Note that errors can be returned by the initial call to
**SetAccountInformation** or the subsequent call to [IPersistFile::Save](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersistfile-save).

The Task Scheduler service must be running for this call to succeed. (**SetAccountInformation** results in a remote procedure call (RPC) to the Task Scheduler service, but the RPC call is not made until [IPersistFile::Save](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersistfile-save) is called.)

The E_ACCESSDENIED return code is returned under the following conditions:

* The caller does not have write access to the file that represents the scheduled work item.
* The local account was specified (*pwszAccountName* was set to L""), but the caller is neither an administrator on the local computer nor an application running in the local system account.
* A **NULL** password was specified in *pwszPassword*, but the caller is neither an administrator on the local computer, nor is running in the local system account.
* The application is running under a different user name than the user named specified in the *pwszAccountName* parameter.

After setting the account information for a work item, be sure to call [IPersistFile::Save](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersistfile-save) to save the modified work item object to disk.

#### Examples

For more information and an example of how to set the account information of a task, see [C/C++ Code Example: Setting Task Account Information](https://learn.microsoft.com/windows/desktop/TaskSchd/c-c-code-example-setting-task-account-information).

## See also

[IScheduledWorkItem](https://learn.microsoft.com/windows/desktop/api/mstask/nn-mstask-ischeduledworkitem)

[IScheduledWorkItem::GetAccountInformation](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-ischeduledworkitem-getaccountinformation)

[IScheduledWorkItem::SetFlags](https://learn.microsoft.com/windows/desktop/api/mstask/nf-mstask-ischeduledworkitem-setflags)