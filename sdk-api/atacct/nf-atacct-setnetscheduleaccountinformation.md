# SetNetScheduleAccountInformation function

## Description

[**SetNetScheduleAccountInformation** is no longer available for use as of Windows 8. Instead, use the  [Task Scheduler 2.0 Interfaces](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-2-0-interfaces).

]

The **SetNetScheduleAccountInformation** function sets the AT Service account name and password. The AT Service account name and password are used as the credentials for scheduled jobs created with [NetScheduleJobAdd](https://learn.microsoft.com/windows/desktop/api/lmat/nf-lmat-netschedulejobadd).

## Parameters

### `pwszServerName` [in]

A NULL-terminated wide character string for the name of the computer whose account information is being set.

### `pwszAccount` [in]

A pointer to a NULL-terminated wide character string for the account. To specify the local system account, set this parameter to **NULL**.

### `pwszPassword` [in]

A pointer to a NULL-terminated wide character string for the password. For information about securing password information, see [Handling Passwords](https://learn.microsoft.com/windows/desktop/SecBP/handling-passwords).

## Return value

The return value is an HRESULT. A value of S_OK indicates the account name and password were successfully set. Any other value indicates an error condition.

If the function fails, some of the possible return values are listed below.

| Return code/value | Description |
| --- | --- |
| **E_ACCESSDENIED**<br><br>0x080070005 | Access was denied. This error is returned if the caller was not a member of the Administrators group. This error is also returned if the *pwszAccount* parameter was not **NULL** indicating a named account not the local system account and the *pwszPassword* parameter was incorrect for the account specified in the *pwszAccount* parameter. |
| **HRESULT_FROM_WIN32(ERROR_INVALID_DATA)**<br><br>0x08007000d | The data is invalid. This error is returned if the *pwszPassword* parameter was **NULL** or the length of *pwszPassword* parameter string was too long. |
| **SCHED_E_ACCOUNT_NAME_NOT_FOUND**<br><br>0x80041310 | Unable to establish existence of the account specified. This error is returned if the *pwszAccount* parameter was not **NULL** indicating a named account not the local system account and the *pwszAccount* parameter could not be found. |

## Remarks

The **SetNetScheduleAccountInformation** impersonates the caller. Only members of the local Administrators group on the computer where the schedule account information is being set can successfully execute this function. Note that **NULL** passwords are not allowed.

## See also

[GetNetScheduleAccountInformation](https://learn.microsoft.com/windows/desktop/api/atacct/nf-atacct-getnetscheduleaccountinformation)