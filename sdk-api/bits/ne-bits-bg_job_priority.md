# BG_JOB_PRIORITY enumeration

## Description

Defines constants that specify the priority level of a job.

## Constants

### `BG_JOB_PRIORITY_FOREGROUND:0`

Transfers the job in the foreground. Foreground transfers compete for network bandwidth with other applications, which can impede the user's network experience. This is the highest priority level.

### `BG_JOB_PRIORITY_HIGH`

Transfers the job in the background with a high priority. Background transfers use idle network bandwidth of the client to transfer files. This is the highest background priority level.

### `BG_JOB_PRIORITY_NORMAL`

Transfers the job in the background with a normal priority. Background transfers use idle network bandwidth of the client to transfer files. This is the default priority level.

### `BG_JOB_PRIORITY_LOW`

Transfers the job in the background with a low priority. Background transfers use idle network bandwidth of the client to transfer files. This is the lowest background priority level.

## Remarks

For a background job, the priority level determines when the job is processed relative to other jobs in the transfer queue. A higher-priority job preempts a lower-priority job. Jobs at the same priority level share transfer time, which prevents a large job from blocking the transfer queue. Lower-priority jobs don't receive transfer time until all higher-priority jobs are transferred, or are in an error state.

Multiple foreground transfers can take place simultaneously. However, multiple files in the same job are transferred sequentially. For example, if you have 5 files that you would like to download concurrently, you may consider creating 5 foreground jobs, one for each transfer.

**BITS 1.5 and earlier:** BITS processes one job at a time. Foreground jobs have the highest priority and run before background jobs.

For more information, see [Best practices when using BITS](https://learn.microsoft.com/windows/desktop/bits/best-practices-when-using-bits).

## See also

* [IBackgroundCopyJob::GetPriority method](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-getpriority)
* [IBackgroundCopyJob::SetPriority method](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-setpriority)