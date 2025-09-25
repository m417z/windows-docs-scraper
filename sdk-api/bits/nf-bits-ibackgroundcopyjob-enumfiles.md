# IBackgroundCopyJob::EnumFiles

## Description

Retrieves an
[IEnumBackgroundCopyFiles](https://learn.microsoft.com/windows/desktop/api/bits/nn-bits-ienumbackgroundcopyfiles) interface pointer that you use to
[enumerate the files](https://learn.microsoft.com/windows/desktop/Bits/enumerating-files-in-a-job) in a job.

## Parameters

### `pEnum` [out]

[IEnumBackgroundCopyFiles](https://learn.microsoft.com/windows/desktop/api/bits/nn-bits-ienumbackgroundcopyfiles) interface pointer that you use to enumerate the files in the job. Release *ppEnumFiles* when done.

## Return value

This method returns **S_OK** on success or one of the standard COM **HRESULT** values on error.

## See also

[IBackgroundCopyManager::EnumJobs](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopymanager-enumjobs)

[IEnumBackgroundCopyFiles](https://learn.microsoft.com/windows/desktop/api/bits/nn-bits-ienumbackgroundcopyfiles)