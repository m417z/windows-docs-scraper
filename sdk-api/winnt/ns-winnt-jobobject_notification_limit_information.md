# JOBOBJECT_NOTIFICATION_LIMIT_INFORMATION structure

## Description

Contains information about notification limits for a job object. This structure is used by the [SetInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-setinformationjobobject) and [QueryInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-queryinformationjobobject) functions with the **JobObjectNotificationLimitInformation** information class.

## Members

### `IoReadBytesLimit`

If the *LimitFlags* member specifies JOB_OBJECT_LIMIT_JOB_READ_BYTES, this member is the notification limit for total I/O bytes read by all processes in the job. Otherwise, this member is ignored.

### `IoWriteBytesLimit`

If the *LimitFlags* parameter specifies JOB_OBJECT_LIMIT_JOB_WRITE_BYTES, this member is the notification limit for total I/O bytes written by all processes in the job. Otherwise, this member is ignored.

### `PerJobUserTimeLimit`

If the *LimitFlags* parameter specifies JOB_OBJECT_LIMIT_JOB_TIME, this member is the notification limit for per-job user-mode execution time, in 100-nanosecond ticks. Otherwise, this member is ignored.

The system adds the accumulated execution time of processes associated with the job to this limit when the limit is set. For example, if a process associated with the job has already accumulated 5 minutes of user-mode execution time and the limit is set to 1 minute, the limit actually enforced is 6 minutes.

To specify **PerJobUserTimeLimit** as an enforceable limit and terminate processes in jobs that exceed the limit, see the [JOBOBJECT_BASIC_LIMIT_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-jobobject_basic_limit_information) structure.

### `JobMemoryLimit`

If the *LimitFlags* parameter specifies JOB_OBJECT_LIMIT_JOB_MEMORY, this member is the notification limit for total virtual memory that can be committed by all processes in the job, in bytes. Otherwise, this member is ignored.

To specify **JobMemoryLimit** as an enforceable limit and prevent processes in jobs that exceed the limit from continuing to commit memory, see the [JOBOBJECT_EXTENDED_LIMIT_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-jobobject_basic_limit_information) structure.

### `RateControlTolerance`

If the *LimitFlags* parameter specifies JOB_OBJECT_LIMIT_RATE_CONTROL, this member specifies the extent to which a job can exceed its CPU rate control limits during the interval specified by the **RateControlToleranceInterval** member. Otherwise, this member is ignored.

This member can be one of the following values. If no value is specified, **ToleranceHigh** is used.

| Value | Meaning |
| --- | --- |
| **ToleranceLow**<br><br>1 | The job can exceed its CPU rate control limits for 20% of the tolerance interval. |
| **ToleranceMedium**<br><br>2 | The job can exceed its CPU rate control limits for 40% of the tolerance interval. |
| **ToleranceHigh**<br><br>3 | The job can exceed its CPU rate control limits for 60% of the tolerance interval. |

### `RateControlToleranceInterval`

If the *LimitFlags* parameter specifies JOB_OBJECT_LIMIT_RATE_CONTROL, this member specifies the interval during which a job's CPU usage is monitored to determine whether the job has exceeded its CPU rate control limits. Otherwise, this member is ignored.

This member can be one of the following values. If no value is specified, **ToleranceIntervalShort** is used.

| Value | Meaning |
| --- | --- |
| **ToleranceIntervalShort**<br><br>1 | The tolerance interval is 10 seconds. |
| **ToleranceIntervalMedium**<br><br>2 | The tolerance interval is one minute. |
| **ToleranceIntervalLong**<br><br>3 | The tolerance interval is 10 minutes. |

### `LimitFlags`

The limit flags that are in effect. This member is a bitfield that determines whether other structure members are used. Any combination of the following values can be specified.

| Value | Meaning |
| --- | --- |
| **JOB_OBJECT_LIMIT_JOB_MEMORY**<br><br>0x00000200 | Establishes the committed memory limit to the job-wide sum of committed memory for all processes associated with the job. The **JobMemoryLimit** member contains additional information. |
| **JOB_OBJECT_LIMIT_JOB_READ_BYTES**<br><br>0x00010000 | Establishes the I/O read bytes limit to the job-wide sum of I/O bytes read by all processes associated with the job. The **IoReadBytesLimit** member contains more information. |
| **JOB_OBJECT_LIMIT_JOB_WRITE_BYTES**<br><br>0x00020000 | Establishes the I/O write bytes limit to the job-wide sum of I/O bytes written by all processes associated with the job. The **IoWriteBytesLimit** member contains more information. |
| **JOB_OBJECT_LIMIT_JOB_TIME**<br><br>0x00000004 | Establishes the limit for user-mode execution time for the job. The **PerJobUserTimeLimit** member contains additional information. |
| **JOB_OBJECT_LIMIT_RATE_CONTROL**<br><br>0x00040000 | Establishes the notification threshold for the CPU rate control limits established for the job. The **RateControlTolerance** and **RateControlToleranceInterval** members contain additional information.<br><br>CPU rate control limits are established by calling [SetInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-setinformationjobobject) with the **JobObjectCpuRateInformationClass** information class. |

## Remarks

When a notification limit is exceeded, the system sends a JOB_OBJECT_MSG_NOTIFICATION_LIMIT message to the I/O completion port associated with the job. Processes in the job continue to run and can continue to allocate memory or transmit read or write bytes beyond the specified limits.

When the application monitoring the I/O completion port receives a JOB_OBJECT_MSG_NOTIFICATION_LIMIT message, it must call [QueryInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-queryinformationjobobject) with the **JobObjectLimitViolationInformation** information class. Limit violation information is received in a JOBOBJECT_LIMIT_VIOLATION_STRUCTURE that contains information about all notification limits that were exceeded at the time of the query. The system will not send another JOB_OBJECT_MSG_NOTIFICATION_LIMIT message until after **QueryInformationJobObject** is called.

CPU rate control limits for a job are established in a [JOBOBJECT_CPU_RATE_CONTROL_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-jobobject_cpu_rate_control_information) structure. The CPU rate control values in the **JOBOBJECT_NOTIFICATION_LIMIT_INFORMATION** structure specify how much the job can exceed its established CPU rate control limits before notification is sent.

## See also

[JOBOBJECT_CPU_RATE_CONTROL_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-jobobject_cpu_rate_control_information)

[JOBOBJECT_LIMIT_VIOLATION_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-jobobject_limit_violation_information)

[QueryInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-queryinformationjobobject)

[SetInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-setinformationjobobject)