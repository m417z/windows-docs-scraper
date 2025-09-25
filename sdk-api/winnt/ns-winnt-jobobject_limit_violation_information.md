# JOBOBJECT_LIMIT_VIOLATION_INFORMATION structure

## Description

Contains information about resource notification limits that have been exceeded for a job object. This structure is used with the [QueryInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-queryinformationjobobject) function with the **JobObjectLimitViolationInformation** information class.

## Members

### `LimitFlags`

Flags that identify the notification limits in effect for the job. This member is a bitfield that determines whether other structure members are used. This member can be any combination of the following values.

| Value | Meaning |
| --- | --- |
| **JOB_OBJECT_LIMIT_JOB_MEMORY**<br><br>0x00000200 | The job has a committed memory notification limit. The **JobMemoryLimit** member contains more information. |
| **JOB_OBJECT_LIMIT_JOB_READ_BYTES**<br><br>0x00010000 | The job has an I/O read bytes notification limit. The **IoReadBytesLimit** member contains more information. |
| **JOB_OBJECT_LIMIT_JOB_TIME**<br><br>0x00000004 | The job has a user-mode execution time notification limit. The **PerJobUserTimeLimit** member contains more information. |
| **JOB_OBJECT_LIMIT_JOB_WRITE_BYTES**<br><br>0x00020000 | The job has an I/O write bytes notification limit. The **IoWriteBytesLimit** member contains more information. |
| **JOB_OBJECT_LIMIT_RATE_CONTROL**<br><br>0x00040000 | The extent to which a job can exceed its CPU rate control limit. The **RateControlToleranceLimit** member contains more information. |

### `ViolationLimitFlags`

Flags that identify the notification limits that have been exceeded. This member is a bitfield that determines whether other structure members are used. This member can be any combination of the following values.

| Value | Meaning |
| --- | --- |
| **JOB_OBJECT_LIMIT_READ_BYTES**<br><br>0x00010000 | The job's I/O read bytes notification limit has been exceeded. The **IoReadBytes** member contains more information. |
| **JOB_OBJECT_LIMIT_WRITE_BYTES**<br><br>0x00020000 | The job's I/O write bytes notification limit has been exceeded. The **IoWriteBytes** member contains more information. |
| **JOB_OBJECT_LIMIT_JOB_TIME**<br><br>0x00000004 | The job's user-mode execution time notification limit has been exceeded. The **PerJobUserTime** member contains more information. |
| **JOB_OBJECT_LIMIT_JOB_MEMORY**<br><br>0x00000200 | The job's committed memory notification limit has been exceeded. The **JobMemory** member contains more information. |
| **JOB_OBJECT_LIMIT_RATE_CONTROL**<br><br>0x00040000 | The job's CPU rate control limit has been exceeded. The **RateControlTolerance** member contains more information. |

### `IoReadBytes`

If the ViolationLimitFlags member specifies JOB_OBJECT_LIMIT_READ_BYTES, this member contains the total I/O read bytes for all processes in the job at the time the notification was sent.

### `IoReadBytesLimit`

If the LimitFlags member specifies JOB_OBJECT_LIMIT_READ_BYTES, this member contains the I/O read bytes notification limit in effect for the job.

### `IoWriteBytes`

If the ViolationLimitFlags member specifies JOB_OBJECT_LIMIT_WRITE_BYTES, this member contains the total I/O write bytes for all processes in the job at the time the notification was sent.

### `IoWriteBytesLimit`

If the LimitFlags member specifies JOB_OBJECT_LIMIT_WRITE_BYTES, this member contains the I/O write bytes notification limit in effect for the job.

### `PerJobUserTime`

If the ViolationLimitFlags member specifies JOB_OBJECT_LIMIT_JOB_TIME, this member contains the total user-mode execution time for all processes in the job at the time the notification was sent.

### `PerJobUserTimeLimit`

If the LimitFlags member specifies JOB_OBJECT_LIMIT_JOB_TIME, this member contains the user-mode execution notification limit in effect for the job.

### `JobMemory`

If the ViolationLimitFlags member specifies JOB_OBJECT_LIMIT_JOB_MEMORY, this member contains the committed memory for all processes in the job at the time the notification was sent.

### `JobMemoryLimit`

If the LimitFlags member specifies JOB_OBJECT_LIMIT_JOB_MEMORY, this member contains the committed memory limit in effect for the job.

### `RateControlTolerance`

If the *LimitFlags* parameter specifies JOB_OBJECT_LIMIT_RATE_CONTROL, this member specifies the extent to which the job exceeded its CPU rate control limits at the time the notification was sent. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **ToleranceLow**<br><br>1 | The job exceeded its CPU rate control limits for 20% of the tolerance interval. |
| **ToleranceMedium**<br><br>2 | The job exceeded its CPU rate control limits for 40% of the tolerance interval. |
| **ToleranceHigh**<br><br>3 | The job exceeded its CPU rate control limits for 60% of the tolerance interval. |

### `RateControlToleranceLimit`

If the *LimitFlags* parameter specifies JOB_OBJECT_LIMIT_RATE_CONTROL, this member contains the CPU rate control notification limits specified for the job.

| Value | Meaning |
| --- | --- |
| **ToleranceIntervalShort**<br><br>1 | The tolerance interval is 10 seconds. |
| **ToleranceIntervalMedium**<br><br>2 | The tolerance interval is one minute. |
| **ToleranceIntervalLong**<br><br>3 | The tolerance interval is 10 minutes. |

## Remarks

When any notification limit specified in a JOBOBJECT_NOTIFICATION_LIMIT_INFORMATION structure is exceeded, the system sends a JOB_OBJECT_MSG_NOTIFICATION_LIMIT message to the I/O completion port associated with the job.

To retrieve information about the limits that were exceeded, the application monitoring the I/O completion port must call the [QueryInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-queryinformationjobobject) function with the **JobObjectLimitViolationInformation** information class and a pointer to a **JOBOBJECT_LIMIT_VIOLATION_INFORMATION** structure.

## See also

[QueryInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-queryinformationjobobject)

[SetInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-setinformationjobobject)