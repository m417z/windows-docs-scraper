# SetInformationJobObject function

## Description

Sets limits for a job object.

## Parameters

### `hJob` [in]

A handle to the job whose limits are being set. The
[CreateJobObject](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createjobobjecta) or
[OpenJobObject](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openjobobjecta) function returns this handle. The handle
must have the **JOB_OBJECT_SET_ATTRIBUTES** access right. For more information, see
[Job Object Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/job-object-security-and-access-rights).

### `JobObjectInformationClass` [in]

The information class for the limits to be set. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **JobObjectAssociateCompletionPortInformation**<br><br>7 | The *lpJobObjectInfo* parameter is a pointer to a [JOBOBJECT_ASSOCIATE_COMPLETION_PORT](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-jobobject_associate_completion_port) structure. |
| **JobObjectBasicLimitInformation**<br><br>2 | The *lpJobObjectInfo* parameter is a pointer to a [JOBOBJECT_BASIC_LIMIT_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-jobobject_basic_limit_information) structure. |
| **JobObjectBasicUIRestrictions**<br><br>4 | The *lpJobObjectInfo* parameter is a pointer to a [JOBOBJECT_BASIC_UI_RESTRICTIONS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-jobobject_basic_ui_restrictions) structure. |
| **JobObjectCpuRateControlInformation**<br><br>15 | The *lpJobObjectInfo* parameter is a pointer to a [JOBOBJECT_CPU_RATE_CONTROL_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-jobobject_cpu_rate_control_information) structure.<br><br>**Windows 7, Windows Server 2008 R2, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This flag is not supported.<br><br>If Dynamic Fair Share Scheduling (DFSS) is enabled, the CPU rate cannot be set and SetInformationJobObject will fail with error code 50 ("The request is not supported"). |
| **JobObjectEndOfJobTimeInformation**<br><br>6 | The *lpJobObjectInfo* parameter is a pointer to a [JOBOBJECT_END_OF_JOB_TIME_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-jobobject_end_of_job_time_information) structure. |
| **JobObjectExtendedLimitInformation**<br><br>9 | The *lpJobObjectInfo* parameter is a pointer to a [JOBOBJECT_EXTENDED_LIMIT_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-jobobject_extended_limit_information) structure. |
| **JobObjectGroupInformation**<br><br>11 | The *lpJobObjectInfo* parameter is a pointer to a **USHORT** value that specifies the list of [processor groups](https://learn.microsoft.com/windows/desktop/ProcThread/processor-groups) to assign the job to. The *cbJobObjectInfoLength* parameter is set to the size of the group data. Divide this value by `sizeof(USHORT)` to determine the number of groups.<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This flag is not supported. |
| **JobObjectGroupInformationEx**<br><br>14 | The *lpJobObjectInfo* parameter is a pointer to a buffer that contains an array of [GROUP_AFFINITY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-group_affinity) structures that specify the affinity of the job for the [processor groups](https://learn.microsoft.com/windows/desktop/ProcThread/processor-groups) to which the job is currently assigned. The *cbJobObjectInfoLength* parameter is set to the size of the group affinity data. Divide this value by `sizeof(GROUP_AFFINITY)` to determine the number of groups.<br><br>**Windows 7, Windows Server 2008 R2, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This flag is not supported. |
| **JobObjectLimitViolationInformation2**<br><br>34 | The *lpJobObjectInfo* parameter is a pointer to a [JOBOBJECT_LIMIT_VIOLATION_INFORMATION_2](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-jobobject_limit_violation_information_2) structure.<br><br>**Windows 8.1, Windows Server 2012 R2, Windows 8, Windows Server 2012, Windows 7, Windows Server 2008 R2, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This flag is not supported. |
| **JobObjectNetRateControlInformation**<br><br>32 | The *lpJobObjectInfo* parameter is a pointer to a [JOBOBJECT_NET_RATE_CONTROL_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-jobobject_net_rate_control_information) structure.<br><br>**Windows 8.1, Windows Server 2012 R2, Windows 8, Windows Server 2012, Windows 7, Windows Server 2008 R2, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This flag is not supported. |
| **JobObjectNotificationLimitInformation**<br><br>12 | The *lpJobObjectInfo* parameter is a pointer to a [JOBOBJECT_NOTIFICATION_LIMIT_INFORMATION](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-jobobject_notification_limit_information) structure.<br><br>**Windows 7, Windows Server 2008 R2, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This flag is not supported. |
| **JobObjectNotificationLimitInformation2**<br><br>33 | The *lpJobObjectInfo* parameter is a pointer to a [JOBOBJECT_NOTIFICATION_LIMIT_INFORMATION_2](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-jobobject_notification_limit_information_2) structure.<br><br>**Windows 8.1, Windows Server 2012 R2, Windows 8, Windows Server 2012, Windows 7, Windows Server 2008 R2, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This flag is not supported. |
| **JobObjectSecurityLimitInformation**<br><br>5 | This flag is not supported. Applications must set security limitations individually for each process.<br><br>**Windows Server 2003 and Windows XP:** The *lpJobObjectInfo* parameter is a pointer to a [JOBOBJECT_SECURITY_LIMIT_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-jobobject_security_limit_information) structure. The *hJob* handle must have the **JOB_OBJECT_SET_SECURITY_ATTRIBUTES** access right associated with it. |

### `lpJobObjectInformation` [in]

The limits or job state to be set for the job. The format of this data depends on the value of *JobObjectInfoClass*.

### `cbJobObjectInformationLength` [in]

The size of the job information being set, in bytes.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Use the **SetInformationJobObject**
function to set several limits in a single call. To establish the limits one at a time or change a
subset of the limits, call the
[QueryInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-queryinformationjobobject) function to obtain
the current limits, modify these limits, and then call
**SetInformationJobObject**.

You must set security limits individually for each process associated with a job object, rather than setting
them for the job object itself. For information, see
[Process Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/process-security-and-access-rights).

**Windows Server 2003 and Windows XP:** Use the **SetInformationJobObject**
function to set security limits for the job object.

To compile an application that uses this function, define _WIN32_WINNT as 0x0500 or later. For more
information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## See also

[JOBOBJECT_ASSOCIATE_COMPLETION_PORT](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-jobobject_associate_completion_port)

[JOBOBJECT_BASIC_LIMIT_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-jobobject_basic_limit_information)

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

[Process Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/process-security-and-access-rights)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)

[QueryInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-queryinformationjobobject)