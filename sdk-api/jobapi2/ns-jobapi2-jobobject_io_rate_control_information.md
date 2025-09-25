## Description

**Windows 10, version 1607, and newer: This structure is not supported.**

Contains information used to control the I/O rate for a job. This structure is used by the [SetIoRateControlInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-setioratecontrolinformationjobobject) and [QueryIoRateControlInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-queryioratecontrolinformationjobobject) functions.

## Members

### `MaxIops`

The maximum limit for the I/O rate in I/O operations per second (IOPS). Set to 0 if to specify no limit.

When you set both **MaxIops** and **MaxBandwith**, the operating system enforces the first limit that the I/O rate reaches.

### `MaxBandwidth`

The maximum limit for the I/O rate in bytes per second. Set to 0 to specify no limit.

When you set both **MaxBandwith** and **MaxIops**, the operating system enforces the first limit that the I/O rate reaches.

### `ReservationIops`

Sets a minimum I/O rate which the operating system reserves for the job. To make no reservation for the job, set this value to 0.

The operating system allows the job to perform I/O operations at this rate, if possible. If the sum of the minimum rates for all jobs exceeds the capacity of the operating system, the rate at which the operating system allows each job to perform I/O operations is proportional to the reservation for the job.

### `VolumeName`

The NT device name for the volume to which you want to apply the policy for the I/O rate. For information about NT device names, see [NT Device Names](https://learn.microsoft.com/windows-hardware/drivers/kernel/nt-device-names).

If this member is **NULL**, the policy for the I/O rate applies to all of the volumes for the operating system. For example, if this member is **NULL** and the **MaxIops** member is 100, the maximum limit for the I/O rate for each volume is set to 100 IOPS, instead of setting an aggregate limit for the I/O rate across all volumes of 100 IOPS.

### `BaseIoSize`

The base size of the normalized I/O unit, in bytes. For example, if the **BaseIoSize** member is 8,000, every 8,000 bytes counts as one I/O unit. 4,000 bytes is also one I/O unit in this example, while 8,001 bytes is two I/O units.

You can set the value of this base I/O size by using the **StorageBaseIOSize** value of the **HKEY_LOCAL_MACHINE**\**SYSTEM**\**CurrentControlSet**\**Control**\**QoS** registry key.

The value of the **BaseIoSize** member is subject to the following constraints:

* The [SetIoRateControlInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-setioratecontrolinformationjobobject) function requires that the **BaseIoSize** member of the **JOBOBJECT_IO_RATE_CONTROL_INFORMATION** structure that you pass to the function is 0.
* The [QueryIoRateControlInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-queryioratecontrolinformationjobobject) method sets the **BaseIoSize** member of this structure to 0 if the volume that the **VolumeName** member specifies does not support the control of the I/O rate.
* The [QueryIoRateControlInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-queryioratecontrolinformationjobobject) method sets the **BaseIoSize** member of this structure to the base size of the normalized I/O unit if the volume that the **VolumeName** member specifies does support the control of the I/O rate.

To query for the base size of the normalized I/O unit without creating a job, call [QueryIoRateControlInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-queryioratecontrolinformationjobobject) with the *hJob* parameter set to **NULL** from a process that is not associated with a job.

### `ControlFlags`

The policy for control of the I/O rate. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **JOB_OBJECT_IO_RATE_CONTROL_ENABLE**<br><br>0x1 | Turns on control of the I/O rate for the job when this structure is passed to the [SetIoRateControlInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-setioratecontrolinformationjobobject) function. Indicates that control of the I/O rate for the job is turned on when this structure is used with the [QueryIoRateControlInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-queryioratecontrolinformationjobobject) function. |

## Remarks

You can only set one I/O rate control for a job in a hierarchy of nested jobs. The settings that you specify apply to that job and the child jobs in the hierarchy for that job. The settings do not apply to the chain of jobs from the parent job up to the top of the hierarchy. You still can change the settings for the original job in the hierarchy on which you set I/O rate control. However, attempts to set values for the control of the I/O rate for any other jobs in the hierarchy, including the parent jobs, fail.

## See also

[QueryIoRateControlInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-queryioratecontrolinformationjobobject)

[SetIoRateControlInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-setioratecontrolinformationjobobject)