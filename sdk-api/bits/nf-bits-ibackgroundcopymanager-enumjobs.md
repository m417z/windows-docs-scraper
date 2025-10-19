# IBackgroundCopyManager::EnumJobs

## Description

Retrieves an interface pointer to an enumerator object that you use to
[enumerate the jobs](https://learn.microsoft.com/windows/desktop/Bits/enumerating-jobs-in-the-transfer-queue) in the transfer queue. The order of the jobs in the enumerator is arbitrary.

## Parameters

### `dwFlags` [in]

Specifies whose jobs to include in the enumeration. If *dwFlags* is set to 0, the user receives all jobs that they own in the transfer queue. The following table lists the enumeration options.

| Option | Meaning |
| --- | --- |
| **BG_JOB_ENUM_ALL_USERS** | Includes all jobs in the transfer queue—those owned by the user and those owned by others. The user must be an administrator to use this flag. |

### `ppEnum` [out]

An
[IEnumBackgroundCopyJobs](https://learn.microsoft.com/windows/desktop/api/bits/nn-bits-ienumbackgroundcopyjobs) interface pointer that you use to enumerate the jobs in the transfer queue. The contents of the enumerator depend on the value of *dwFlags*. Release *ppEnumJobs* when done.

## Return value

This method returns the following **HRESULT** values, as well as others.

| Return code | Description |
| --- | --- |
| **S_OK** | Successfully generated enumerator object. |
| **E_ACCESSDENIED** | The user must be an administrator or belong to an administrator group to enumerate jobs owned by another user. |

## See also

[IBackgroundCopyJob::EnumFiles](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-enumfiles)

[IBackgroundCopyManager::GetJob](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopymanager-getjob)

[IEnumBackgroundCopyJobs](https://learn.microsoft.com/windows/desktop/api/bits/nn-bits-ienumbackgroundcopyjobs)