# IBackgroundCopyManager::CreateJob

## Description

Creates a job.

## Parameters

### `DisplayName` [in]

Null-terminated string that contains a display name for the job. Typically, the display name is used to identify the job in a user interface. Note that more than one job may have the same display name. Must not be **NULL**. The name is limited to 256 characters, not including the null terminator.

### `Type` [in]

Type of transfer job, such as BG_JOB_TYPE_DOWNLOAD. For a list of transfer types, see the
[BG_JOB_TYPE](https://learn.microsoft.com/windows/desktop/api/bits/ne-bits-bg_job_type) enumeration.

### `pJobId` [out]

Uniquely identifies your job in the queue. Use this identifier when you call the
[IBackgroundCopyManager::GetJob](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopymanager-getjob) method to get a job from the queue.

### `ppJob` [out]

An
[IBackgroundCopyJob](https://learn.microsoft.com/windows/desktop/api/bits/nn-bits-ibackgroundcopyjob) interface pointer that you use to modify the job's properties and specify the files to be transferred. To activate the job in the queue, call the
[IBackgroundCopyJob::Resume](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-resume) method. Release *ppJob* when done.

## Return value

This method returns the following **HRESULT** values, as well as others.

| Return code | Description |
| --- | --- |
| **S_OK** | Successfully generated the new job. |
| **E_INVALIDARG** | The display name is too long. |
| **BG_E_TOO_MANY_JOBS_PER_MACHINE** | The MaxJobsPerMachine Group Policy setting determines how many jobs can be created on the computer. Adding this job exceeds the MaxJobsPerMachine limit. |
| **BG_E_TOO_MANY_JOBS_PER_USER** | The MaxJobsPerUser Group Policy setting determines how many jobs a user can create. Adding this job exceeds the MaxJobsPerUser limit. |

## Remarks

Only the user who creates the job or a user with administrator privileges can [add files to the job](https://learn.microsoft.com/windows/desktop/Bits/adding-files-to-a-job) and [change the job's properties](https://learn.microsoft.com/windows/desktop/Bits/setting-and-retrieving-the-properties-of-a-job).

By default, BITS supports a maximum of 300 jobs at one time. A single user can create a maximum of 60 jobs at one time. The user limit does not apply to administrators or service accounts. To change these defaults, set the **MaxJobsPerMachine** and **MaxJobsPerUser** group policies, respectively.

**Prior to Windows Vista:** There is no limit on the number of jobs that BITS supports or that a user can create.

For scalability concerns, see [Best Practices When Using BITS](https://learn.microsoft.com/windows/desktop/Bits/best-practices-when-using-bits).

#### Examples

For an example that creates a new job, see
[Creating a Job](https://learn.microsoft.com/windows/desktop/Bits/creating-a-job).

## See also

[Creating a Job](https://learn.microsoft.com/windows/desktop/Bits/creating-a-job)

[IBackgroundCopyJob](https://learn.microsoft.com/windows/desktop/api/bits/nn-bits-ibackgroundcopyjob)

[IBackgroundCopyJob::Resume](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-resume)