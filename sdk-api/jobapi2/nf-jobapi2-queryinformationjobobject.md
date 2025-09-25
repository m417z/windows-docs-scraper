# QueryInformationJobObject function

## Description

Retrieves limit and job state information from the job object.

## Parameters

### `hJob` [in, optional]

A handle to the job whose information is being queried. The
[CreateJobObject](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createjobobjecta) or
[OpenJobObject](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openjobobjecta) function returns this handle. The handle must have the **JOB_OBJECT_QUERY** access right. For more information, see
[Job Object Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/job-object-security-and-access-rights).

If this value is NULL and the calling process is associated with a job, the job associated with the calling process is used. If the job is nested, the immediate job of the calling process is used.

### `JobObjectInformationClass` [in]

The information class for the limits to be queried. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **JobObjectBasicAccountingInformation**<br><br>1 | The *lpJobObjectInfo* parameter is a pointer to a [JOBOBJECT_BASIC_ACCOUNTING_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-jobobject_basic_accounting_information) structure. |
| **JobObjectBasicAndIoAccountingInformation**<br><br>8 | The *lpJobObjectInfo* parameter is a pointer to a [JOBOBJECT_BASIC_AND_IO_ACCOUNTING_INFORMATION](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-jobobject_basic_and_io_accounting_information) structure. |
| **JobObjectBasicLimitInformation**<br><br>2 | The *lpJobObjectInfo* parameter is a pointer to a [JOBOBJECT_BASIC_LIMIT_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-jobobject_basic_limit_information) structure. |
| **JobObjectBasicProcessIdList**<br><br>3 | The *lpJobObjectInfo* parameter is a pointer to a [JOBOBJECT_BASIC_PROCESS_ID_LIST](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-jobobject_basic_process_id_list) structure. |
| **JobObjectBasicUIRestrictions**<br><br>4 | The *lpJobObjectInfo* parameter is a pointer to a [JOBOBJECT_BASIC_UI_RESTRICTIONS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-jobobject_basic_ui_restrictions) structure. |
| **JobObjectCpuRateControlInformation**<br><br>15 | The *lpJobObjectInfo* parameter is a pointer to a [JOBOBJECT_CPU_RATE_CONTROL_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-jobobject_cpu_rate_control_information) structure. <br><br>**Windows 7, Windows Server 2008 R2, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This flag is not supported. |
| **JobObjectEndOfJobTimeInformation**<br><br>6 | The *lpJobObjectInfo* parameter is a pointer to a [JOBOBJECT_END_OF_JOB_TIME_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-jobobject_end_of_job_time_information) structure. |
| **JobObjectExtendedLimitInformation**<br><br>9 | The *lpJobObjectInfo* parameter is a pointer to a [JOBOBJECT_EXTENDED_LIMIT_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-jobobject_extended_limit_information) structure. |
| **JobObjectGroupInformation**<br><br>11 | The *lpJobObjectInfo* parameter is a pointer to a buffer that receives the list of [processor groups](https://learn.microsoft.com/windows/desktop/ProcThread/processor-groups) to which the job is currently assigned. The variable pointed to by the *lpReturnLength* parameter is set to the size of the group data. Divide this value by `sizeof(USHORT)` to determine the number of groups.<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This flag is not supported. |
| **JobObjectGroupInformationEx**<br><br>14 | The *lpJobObjectInfo* parameter is a pointer to a buffer that receives an array of [GROUP_AFFINITY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-group_affinity) structures that indicate the affinity of the job in the [processor groups](https://learn.microsoft.com/windows/desktop/ProcThread/processor-groups) to which the job is currently assigned. The variable pointed to by the *lpReturnLength* parameter is set to the size of the group affinity data. Divide this value by `sizeof(GROUP_AFFINITY)` to determine the number of groups.<br><br>**Windows 7, Windows Server 2008 R2, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This flag is not supported. |
| **JobObjectLimitViolationInformation**<br><br>13 | The *lpJobObjectInfo* parameter is a pointer to a [JOBOBJECT_LIMIT_VIOLATION_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-jobobject_limit_violation_information) structure. <br><br>**Windows 7, Windows Server 2008 R2, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This flag is not supported. |
| **JobObjectLimitViolationInformation2**<br><br>34 | The *lpJobObjectInfo* parameter is a pointer to a [JOBOBJECT_LIMIT_VIOLATION_INFORMATION_2](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-jobobject_limit_violation_information_2) structure.<br><br>**Windows 8.1, Windows Server 2012 R2, Windows 8, Windows Server 2012, Windows 7, Windows Server 2008 R2, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This flag is not supported. |
| **JobObjectNetRateControlInformation**<br><br>32 | The *lpJobObjectInfo* parameter is a pointer to a [JOBOBJECT_NET_RATE_CONTROL_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-jobobject_net_rate_control_information) structure.<br><br>**Windows 8.1, Windows Server 2012 R2, Windows 8, Windows Server 2012, Windows 7, Windows Server 2008 R2, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This flag is not supported. |
| **JobObjectNotificationLimitInformation**<br><br>12 | The *lpJobObjectInfo* parameter is a pointer to a [JOBOBJECT_NOTIFICATION_LIMIT_INFORMATION](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-jobobject_notification_limit_information) structure. <br><br>**Windows 7, Windows Server 2008 R2, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This flag is not supported. |
| **JobObjectNotificationLimitInformation2**<br><br>33 | The *lpJobObjectInfo* parameter is a pointer to a [JOBOBJECT_NOTIFICATION_LIMIT_INFORMATION_2](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-jobobject_notification_limit_information) structure.<br><br>**Windows 8.1, Windows Server 2012 R2, Windows 8, Windows Server 2012, Windows 7, Windows Server 2008 R2, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This flag is not supported. |
| **JobObjectSecurityLimitInformation**<br><br>5 | This flag is not supported. Applications must set security limits individually for each process. **Windows Server 2003 and Windows XP:** The *lpJobObjectInfo* parameter is a pointer to a [JOBOBJECT_SECURITY_LIMIT_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-jobobject_security_limit_information) structure. |

### `lpJobObjectInformation` [out]

The limit or job state information. The format of this data depends on the value of the *JobObjectInfoClass* parameter.

### `cbJobObjectInformationLength` [in]

The count of the job information being queried, in bytes. This value depends on the value of the *JobObjectInfoClass* parameter.

### `lpReturnLength` [out, optional]

A pointer to a variable that receives the length of data written to the structure pointed to by the *lpJobObjectInfo* parameter. Specify **NULL** to not receive this information.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Use
**QueryInformationJobObject** to obtain the current limits and modify them. Use the
[SetInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-setinformationjobobject) function to set new limits.

To compile an application that uses this function, define **_WIN32_WINNT** as 0x0500 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## See also

[JOBOBJECT_BASIC_ACCOUNTING_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-jobobject_basic_accounting_information)

[JOBOBJECT_BASIC_AND_IO_ACCOUNTING_INFORMATION](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-jobobject_basic_and_io_accounting_information)

[JOBOBJECT_BASIC_LIMIT_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-jobobject_basic_limit_information)

[JOBOBJECT_BASIC_PROCESS_ID_LIST](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-jobobject_basic_process_id_list)

[JOBOBJECT_BASIC_UI_RESTRICTIONS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-jobobject_basic_ui_restrictions)

[JOBOBJECT_CPU_RATE_CONTROL_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-jobobject_cpu_rate_control_information)

[JOBOBJECT_END_OF_JOB_TIME_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-jobobject_end_of_job_time_information)

[JOBOBJECT_EXTENDED_LIMIT_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-jobobject_extended_limit_information)

[JOBOBJECT_LIMIT_VIOLATION_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-jobobject_limit_violation_information)

[JOBOBJECT_LIMIT_VIOLATION_INFORMATION_2](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-jobobject_limit_violation_information_2)

[JOBOBJECT_NET_RATE_CONTROL_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-jobobject_net_rate_control_information)

[JOBOBJECT_NOTIFICATION_LIMIT_INFORMATION](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-jobobject_notification_limit_information)

[JOBOBJECT_NOTIFICATION_LIMIT_INFORMATION_2](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-jobobject_notification_limit_information)

[JOBOBJECT_SECURITY_LIMIT_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-jobobject_security_limit_information)

[Job Objects](https://learn.microsoft.com/windows/desktop/ProcThread/job-objects)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)

[SetInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-setinformationjobobject)