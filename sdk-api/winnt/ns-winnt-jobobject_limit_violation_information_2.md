# JOBOBJECT_LIMIT_VIOLATION_INFORMATION_2 structure

## Description

Contains extended information about resource notification limits that have been exceeded for a job object. This structure is used with the [QueryInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-queryinformationjobobject) function with the **JobObjectLimitViolationInformation2** information class.

## Members

### `LimitFlags`

Flags that identify the notification limits in effect for the job. This member is a bitfield that determines whether other structure members are used. This member can be any combination of the following values.

| Value | Meaning |
| --- | --- |
| **JOB_OBJECT_LIMIT_JOB_MEMORY_HIGH**<br><br>0x00000200 | The job has a committed memory notification limit. The **JobHighMemoryLimit** member contains more information. |
| **JOB_OBJECT_LIMIT_JOB_MEMORY_LOW**<br><br>0x00008000 | The job has a committed minimum memory notification limit. The **JobLowMemoryLimit** member contains more information. |
| **JOB_OBJECT_LIMIT_JOB_READ_BYTES**<br><br>0x00010000 | The job has an I/O read bytes notification limit. The **IoReadBytesLimit** member contains more information. |
| **JOB_OBJECT_LIMIT_JOB_WRITE_BYTES**<br><br>0x00020000 | The job has an I/O write bytes notification limit. The **IoWriteBytesLimit** member contains more information. |
| **JOB_OBJECT_LIMIT_JOB_TIME**<br><br>0x00000004 | The job has a user-mode execution time notification limit. The **PerJobUserTimeLimit** member contains more information. |
| **JOB_OBJECT_LIMIT_RATE_CONTROL**<br><br>0x00040000 | The job has notification limit for the extent to which a job can exceed its CPU rate control limit. The **RateControlToleranceLimit** member contains more information. |
| **JOB_OBJECT_LIMIT_CPU_RATE_CONTROL**<br><br>0x00040000 | The job has notification limit for the extent to which a job can exceed its CPU rate control limit. The **CpuRateControlToleranceLimit** member contains more information. |
| **JOB_OBJECT_LIMIT_IO_RATE_CONTROL**<br><br>0x00080000 | The job has notification limit for the extent to which a job can exceed its I/O rate control limit. The **IoRateControlToleranceLimit** member contains more information. |
| **JOB_OBJECT_LIMIT_NET_RATE_CONTROL**<br><br>0x00100000 | The job has notification limit for the extent to which a job can exceed its network rate control limit. The **NetRateControlToleranceLimit** member contains more information. |

### `ViolationLimitFlags`

Flags that identify the notification limits that have been exceeded. This member is a bitfield that determines whether other structure members are used. This member can be any combination of the following values.

| Value | Meaning |
| --- | --- |
| **JOB_OBJECT_LIMIT_JOB_READ_BYTES**<br><br>0x00010000 | The job's I/O read bytes notification limit has been exceeded. The **IoReadBytes** member contains more information. |
| **JOB_OBJECT_LIMIT_JOB_WRITE_BYTES**<br><br>0x00020000 | The job's I/O write bytes notification limit has been exceeded. The **IoWriteBytes** member contains more information. |
| **JOB_OBJECT_LIMIT_JOB_TIME**<br><br>0x00000004 | The job's user-mode execution time notification limit has been exceeded. The **PerJobUserTime** member contains more information. |
| **JOB_OBJECT_LIMIT_JOB_MEMORY_HIGH**<br><br>0x00000200 | The job's committed maximum memory notification limit has been exceeded. The **JobMemory** member contains more information. |
| **JOB_OBJECT_LIMIT_JOB_MEMORY_LOW**<br><br>0x00008000 | The job's committed memory has fallen below its minimum notification limit. The **JobMemory** member contains more information. |
| **JOB_OBJECT_LIMIT_RATE_CONTROL**<br><br>0x00040000 | The job's CPU rate control limit has been exceeded. The **RateControlTolerance** member contains more information. |
| **JOB_OBJECT_LIMIT_CPU_RATE_CONTROL**<br><br>0x00040000 | The job's CPU rate control limit has been exceeded. The **CpuRateControlTolerance** member contains more information. |
| **JOB_OBJECT_LIMIT_IO_RATE_CONTROL**<br><br>0x00080000 | The job's I/O rate control limit has been exceeded. The **IoRateControlTolerance** member contains more information. |
| **JOB_OBJECT_LIMIT_NET_RATE_CONTROL**<br><br>0x00100000 | The job's network rate control limit has been exceeded. The **NetworkRateControlTolerance** member contains more information. |

### `IoReadBytes`

If the **ViolationLimitFlags** member specifies **JOB_OBJECT_LIMIT_JOB_READ_BYTES**, this member contains the total I/O read bytes for all processes in the job at the time the notification was sent.

### `IoReadBytesLimit`

If the **LimitFlags** member specifies **JOB_OBJECT_LIMIT_JOB_READ_BYTES**, this member contains the I/O read bytes notification limit in effect for the job.

### `IoWriteBytes`

If the **ViolationLimitFlags** member specifies **JOB_OBJECT_LIMIT_JOB_WRITE_BYTES**, this member contains the total I/O write bytes for all processes in the job at the time the notification was sent.

### `IoWriteBytesLimit`

If the **LimitFlags** member specifies **JOB_OBJECT_LIMIT_JOB_WRITE_BYTES**, this member contains the I/O write bytes notification limit in effect for the job.

### `PerJobUserTime`

If the **ViolationLimitFlags** member specifies **JOB_OBJECT_LIMIT_JOB_TIME**, this member contains the total user-mode execution time for all processes in the job at the time the notification was sent.

### `PerJobUserTimeLimit`

If the **LimitFlags** member specifies **JOB_OBJECT_LIMIT_JOB_TIME**, this member contains the user-mode execution notification limit in effect for the job.

### `JobMemory`

If the **ViolationLimitFlags** member specifies **JOB_OBJECT_LIMIT_JOB_MEMORY_HIGH** or **JOB_OBJECT_LIMIT_JOB_MEMORY_LOW**, this member contains the committed memory for all processes in the job at the time the notification was sent.

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.JobHighMemoryLimit`

If the **LimitFlags** member specifies **JOB_OBJECT_LIMIT_JOB_MEMORY_HIGH**, this member contains the committed maximum memory limit in effect for the job.

### `DUMMYUNIONNAME.JobMemoryLimit`

If the **LimitFlags** member specifies **JOB_OBJECT_LIMIT_JOB_MEMORY**, this member contains the committed maximum memory limit in effect for the job.

### `DUMMYUNIONNAME2`

### `DUMMYUNIONNAME2.RateControlTolerance`

If the **LimitFlags** member specifies **JOB_OBJECT_LIMIT_RATE_CONTROL**, this member specifies the extent to which the job exceeded its CPU rate control limits at the time the notification was sent. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **ToleranceLow**<br><br>1 | The job exceeded its CPU rate control limits for 20% of the tolerance interval. |
| **ToleranceMedium**<br><br>2 | The job exceeded its CPU rate control limits for 40% of the tolerance interval. |
| **ToleranceHigh**<br><br>3 | The job exceeded its CPU rate control limits for 60% of the tolerance interval. |

### `DUMMYUNIONNAME2.CpuRateControlTolerance`

If the **LimitFlags** member specifies **JOB_OBJECT_LIMIT_CPU_RATE_CONTROL**, this member specifies the extent to which the job exceeded its CPU rate control limits at the time the notification was sent. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **ToleranceLow**<br><br>1 | The job exceeded its CPU rate control limits for 20% of the tolerance interval. |
| **ToleranceMedium**<br><br>2 | The job exceeded its CPU rate control limits for 40% of the tolerance interval. |
| **ToleranceHigh**<br><br>3 | The job exceeded its CPU rate control limits for 60% of the tolerance interval. |

### `DUMMYUNIONNAME3`

### `DUMMYUNIONNAME3.RateControlToleranceLimit`

If the **LimitFlags** member specifies **JOB_OBJECT_LIMIT_RATE_CONTROL**, this member contains the CPU rate control notification limits specified for the job.

| Value | Meaning |
| --- | --- |
| **ToleranceLow**<br><br>1 | The job can exceed its CPU rate control limits for 20% of the tolerance interval. |
| **ToleranceMedium**<br><br>2 | The job can exceed its CPU rate control limits for 40% of the tolerance interval. |
| **ToleranceHigh**<br><br>3 | The job can exceed its CPU rate control limits for 60% of the tolerance interval. |

### `DUMMYUNIONNAME3.CpuRateControlToleranceLimit`

If the *LimitFlags* parameter specifies **JOB_OBJECT_LIMIT_CPU_RATE_CONTROL**, this member contains the CPU rate control notification limits specified for the job.

| Value | Meaning |
| --- | --- |
| **ToleranceLow**<br><br>1 | The job can exceed its CPU rate control limits for 20% of the tolerance interval. |
| **ToleranceMedium**<br><br>2 | The job can exceed its CPU rate control limits for 40% of the tolerance interval. |
| **ToleranceHigh**<br><br>3 | The job can exceed its CPU rate control limits for 60% of the tolerance interval. |

### `JobLowMemoryLimit`

If the **LimitFlags** member specifies **JOB_OBJECT_LIMIT_JOB_MEMORY_LOW**, this member contains the committed minimum memory limit in effect for the job.

### `IoRateControlTolerance`

If the **LimitFlags** member specifies **JOB_OBJECT_LIMIT_IO_RATE_CONTROL**, this member specifies the extent to which the job exceeded its I/O rate control limits at the time the notification was sent. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **ToleranceLow**<br><br>1 | The job exceeded its I/O rate control limits for 20% of the tolerance interval. |
| **ToleranceMedium**<br><br>2 | The job exceeded its I/O rate control limits for 40% of the tolerance interval. |
| **ToleranceHigh**<br><br>3 | The job exceeded its I/O rate control limits for 60% of the tolerance interval. |

### `IoRateControlToleranceLimit`

If the *LimitFlags* parameter specifies **JOB_OBJECT_LIMIT_IO_RATE_CONTROL**, this member contains the I/O rate control notification limits specified for the job.

| Value | Meaning |
| --- | --- |
| **ToleranceLow**<br><br>1 | The job can exceed its I/O rate control limits for 20% of the tolerance interval. |
| **ToleranceMedium**<br><br>2 | The job can exceed its I/O rate control limits for 40% of the tolerance interval. |
| **ToleranceHigh**<br><br>3 | The job can exceed its I/O rate control limits for 60% of the tolerance interval. |

### `NetRateControlTolerance`

If the **LimitFlags** member specifies **JOB_OBJECT_LIMIT_NET_RATE_CONTROL**, this member specifies the extent to which the job exceeded its network rate control limits at the time the notification was sent. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **ToleranceLow**<br><br>1 | The job exceeded its network rate control limits for 20% of the tolerance interval. |
| **ToleranceMedium**<br><br>2 | The job exceeded its network rate control limits for 40% of the tolerance interval. |
| **ToleranceHigh**<br><br>3 | The job exceeded its network rate control limits for 60% of the tolerance interval. |

### `NetRateControlToleranceLimit`

If the *LimitFlags* parameter specifies **JOB_OBJECT_LIMIT_NETWORK_RATE_CONTROL**, this member contains the network rate control notification limits specified for the job.

| Value | Meaning |
| --- | --- |
| **ToleranceLow**<br><br>1 | The job can exceed its network rate control limits for 20% of the tolerance interval. |
| **ToleranceMedium**<br><br>2 | The job can exceed its network rate control limits for 40% of the tolerance interval. |
| **ToleranceHigh**<br><br>3 | The job can exceed its network rate control limits for 60% of the tolerance interval. |

## Remarks

When any notification limit specified in a [JOBOBJECT_NOTIFICATION_LIMIT_INFORMATION_2](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-jobobject_notification_limit_information_2) structure is exceeded, the system sends a **JOB_OBJECT_MSG_NOTIFICATION_LIMIT** message to the I/O completion port associated with the job.

To retrieve information about the limits that were exceeded, the application monitoring the I/O completion port must call the [QueryInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-queryinformationjobobject) function with the **JobObjectLimitViolationInformation2** information class and a pointer to a **JOBOBJECT_LIMIT_VIOLATION_INFORMATION_2** structure.

## See also

[JOBOBJECT_NOTIFICATION_LIMIT_INFORMATION_2](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-jobobject_notification_limit_information_2)

[QueryInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-queryinformationjobobject)

[SetInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-setinformationjobobject)