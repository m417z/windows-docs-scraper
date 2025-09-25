# JOBOBJECT_CPU_RATE_CONTROL_INFORMATION structure

## Description

Contains CPU rate control information for a job object. This structure is used by the [SetInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-setinformationjobobject) and [QueryInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-queryinformationjobobject) functions with the **JobObjectCpuRateControlInformation** information class.

## Members

### `ControlFlags`

The scheduling policy for CPU rate control. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **JOB_OBJECT_CPU_RATE_CONTROL_ENABLE**<br><br>0x1 | This flag enables the job's CPU rate to be controlled based on weight or hard cap. You must set this value if you also set **JOB_OBJECT_CPU_RATE_CONTROL_WEIGHT_BASED**, **JOB_OBJECT_CPU_RATE_CONTROL_HARD_CAP**, or **JOB_OBJECT_CPU_RATE_CONTROL_MIN_MAX_RATE**. |
| **JOB_OBJECT_CPU_RATE_CONTROL_WEIGHT_BASED**<br><br>0x2 | The job's CPU rate is calculated based on its relative weight to the weight of other jobs. If this flag is set, the **Weight** member contains more information. If this flag is clear, the **CpuRate** member contains more information.<br><br>If you set **JOB_OBJECT_CPU_RATE_CONTROL_WEIGHT_BASED**, you cannot also set **JOB_OBJECT_CPU_RATE_CONTROL_MIN_MAX_RATE**. |
| **JOB_OBJECT_CPU_RATE_CONTROL_HARD_CAP**<br><br>0x4 | The job's CPU rate is a hard limit. After the job reaches its CPU cycle limit for the current scheduling interval, no threads associated with the job will run until the next interval. <br><br>If you set **JOB_OBJECT_CPU_RATE_CONTROL_HARD_CAP**, you cannot also set **JOB_OBJECT_CPU_RATE_CONTROL_MIN_MAX_RATE**. |
| **JOB_OBJECT_CPU_RATE_CONTROL_NOTIFY**<br><br>0x8 | Sends messages when the CPU rate for the job exceeds the rate limits for the job during the tolerance interval. |
| **JOB_OBJECT_ CPU_RATE_CONTROL_MIN_MAX_RATE**<br><br>0x10 | The CPU rate for the job is limited by minimum and maximum rates that you specify in the **MinRate** and **MaxRate** members.<br><br>If you set **JOB_OBJECT_CPU_RATE_CONTROL_MIN_MAX_RATE**, you can set neither **JOB_OBJECT_CPU_RATE_CONTROL_WEIGHT_BASED** nor **JOB_OBJECT_CPU_RATE_CONTROL_HARD_CAP**. |

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.CpuRate`

Specifies the portion of processor cycles that the threads in a job object can use during each scheduling interval, as the number of cycles per 10,000 cycles. If the **ControlFlags** member specifies **JOB_OBJECT_CPU_RATE_WEIGHT_BASED** or **JOB_OBJECT_CPU_RATE_CONTROL_MIN_MAX_RATE**, this member is not used.

Set **CpuRate** to a percentage times 100. For example, to let the job use 20% of the CPU, set **CpuRate** to 20 times 100, or 2,000.

Do not set **CpuRate** to 0. If **CpuRate** is 0, [SetInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-setinformationjobobject) returns **INVALID_ARGS**.

### `DUMMYUNIONNAME.Weight`

If the **ControlFlags** member specifies **JOB_OBJECT_CPU_RATE_WEIGHT_BASED**, this member specifies the scheduling weight of the job object, which determines the share of processor time given to the job relative to other workloads on the processor.

This member can be a value from 1 through 9, where 1 is the smallest share and 9 is the largest share. The default is 5, which should be used for most workloads.

If the **ControlFlags** member specifies **JOB_OBJECT_CPU_RATE_CONTROL_MIN_MAX_RATE**, this member is not used.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.MinRate`

Specifies the minimum portion of the processor cycles that the threads in a job object can reserve during each scheduling interval. Specify this rate as a percentage times 100. For example, to set a minimum rate of 50%, specify 50 times 100, or 5,000.

For the minimum rates to work correctly, the sum of the minimum rates for all of the job objects in the system cannot exceed 10,000, which is the equivalent of 100%.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.MaxRate`

Specifies the maximum portion of processor cycles that the threads in a job object can use during each scheduling interval. Specify this rate as a percentage times 100. For example, to set a maximum rate of 50%, specify 50 times 100, or 5,000.

After the job reaches this limit for a scheduling interval, no threads associated with the job can run until the next scheduling interval.

## Remarks

You can set CPU rate control for multiple jobs in a hierarchy of nested jobs. When you set CPU rate control for a job object, the settings apply to the job and its child jobs in the hierarchy. When you set CPU rate control for a job in a nested hierarchy, the system calculates the corresponding quotas with respect to the CPU rate control of the immediate parent job for the job. In other words, the rates set for the job represent its portion of the CPU rate that is allocated to its parent job. If a job object does not have a parent with CPU rate control turned on in the chain of its parent jobs, the rate control for the job represents the portion of the CPU for the entire system.

CPU rate control cannot be used by job objects in applications running under [Remote Desktop Services](https://learn.microsoft.com/windows/desktop/TermServ/terminal-services-portal) (formerly Terminal Services) if Dynamic Fair Share Scheduling (DFSS) is in effect.

## See also

[JOBOBJECT_NOTIFICATION_LIMIT_INFORMATION](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-jobobject_notification_limit_information)

[QueryInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-queryinformationjobobject)

[SetInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-setinformationjobobject)