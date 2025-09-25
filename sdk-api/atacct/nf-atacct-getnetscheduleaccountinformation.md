# GetNetScheduleAccountInformation function

## Description

[**GetNetScheduleAccountInformation** is no longer available for use as of Windows 8. Instead, use the  [Task Scheduler 2.0 Interfaces](https://learn.microsoft.com/windows/desktop/TaskSchd/task-scheduler-2-0-interfaces).

]

The **GetNetScheduleAccountInformation** function retrieves the AT Service account name.

## Parameters

### `pwszServerName` [in]

A NULL-terminated wide character string for the name of the computer whose account information is being retrieved.

### `ccAccount` [in]

The number of characters, including the NULL terminator, allocated for *wszAccount*. The maximum allowed length for this value is the maximum domain name length plus the maximum user name length plus 2, expressed as DNLEN + UNLEN + 2. (The last two characters are the "\" character and the NULL terminator.)

### `wszAccount` [out]

An array of wide characters, including the NULL terminator, that receives the account information.

## Return value

The return value is an HRESULT. A value of S_OK indicates the function succeeded, and the account information is returned in *wszAccount*. A value of S_FALSE indicates the function succeeded, and the account is the Local System account (no information will be returned in *wszAccount*). Any other return values indicate an error condition.

## Remarks

To successfully call the **GetNetScheduleAccountInformation** function, the caller should have read access to the task folder which is usually %windir%\tasks or as defined in the following registry setting:

**HKLM\SOFTWARE\Microsoft\SchedulingAgent\TasksFolder\**

## See also

[SetNetScheduleAccountInformation](https://learn.microsoft.com/windows/desktop/api/atacct/nf-atacct-setnetscheduleaccountinformation)