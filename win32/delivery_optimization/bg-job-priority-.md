# BG_JOB_PRIORITY enumeration

The **BG_JOB_PRIORITY** enumeration defines the constant values that specify the priority level of a job.

## Constants

**BG_JOB_PRIORITY_FOREGROUND**

Transfers the job in the foreground. Foreground transfers compete for network bandwidth with other applications, which can impede the user's network experience. This is the highest priority level.

**BG_JOB_PRIORITY_HIGH**

Transfers the job in the background. Background transfers use a small percentage of network bandwidth.

**BG_JOB_PRIORITY_NORMAL**

Delivery Optimization behavior is same for all non foreground job. See comments in BG_JOB_PRIORITY_HIGH for details.

**BG_JOB_PRIORITY_LOW**

Delivery Optimization behavior is same for all non foreground job. See comments in BG_JOB_PRIORITY_HIGH for details.

## Remarks

Multiple foreground and background transfers can take place simultaneously.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 10, version 1709 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server, version 1709 \[desktop apps only\]<br> |
| Header<br> | Deliveryoptimization.h |

## See also

[**IBackgroundCopyJob::GetPriority**](https://learn.microsoft.com/windows/win32/delivery_optimization/ibackgroundcopyjob-getpriority)

[**IBackgroundCopyJob::SetPriority**](https://learn.microsoft.com/windows/win32/delivery_optimization/ibackgroundcopyjob-setpriority)

