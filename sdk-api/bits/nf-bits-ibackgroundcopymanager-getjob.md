# IBackgroundCopyManager::GetJob

## Description

Retrieves a specified job from the transfer queue. Typically, your application persists the job identifier, so you can later retrieve the job from the queue.

## Parameters

### `jobID` [in]

Identifies the job to retrieve from the transfer queue. The
[CreateJob](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopymanager-createjob) method returns the job identifier.

### `ppJob` [out]

An
[IBackgroundCopyJob](https://learn.microsoft.com/windows/desktop/api/bits/nn-bits-ibackgroundcopyjob) interface pointer to the job specified by *JobID*. When done, release *ppJob*.

## Return value

This method returns the following **HRESULT** values, as well as others.

| Return code | Description |
| --- | --- |
| **S_OK** | Job was successfully retrieved from the transfer queue. |
| **BG_E_NOT_FOUND** | The job was not found in the queue. |
| **E_ACCESSDENIED** | User does not have permission to retrieve the job. |

## See also

[IBackgroundCopyJob](https://learn.microsoft.com/windows/desktop/api/bits/nn-bits-ibackgroundcopyjob)

[IBackgroundCopyJob::GetId](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-getid)

[IBackgroundCopyManager::CreateJob](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopymanager-createjob)

[IBackgroundCopyManager::EnumJobs](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopymanager-enumjobs)