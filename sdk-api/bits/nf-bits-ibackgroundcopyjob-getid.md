# IBackgroundCopyJob::GetId

## Description

Retrieves the identifier used to identify the job in the queue.

## Parameters

### `pVal` [out]

GUID that identifies the job within the BITS queue.

## Return value

This method returns **S_OK** on success or one of the standard COM **HRESULT** values on error.

## Remarks

The service generates the identifier when you
[create](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopymanager-createjob) the job. To use the identifier to retrieve an
[IBackgroundCopyJob](https://learn.microsoft.com/windows/desktop/api/bits/nn-bits-ibackgroundcopyjob) interface pointer for the job, call the
[IBackgroundCopyManager::GetJob](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopymanager-getjob) method.

## See also

[IBackgroundCopyManager::CreateJob](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopymanager-createjob)

[IBackgroundCopyManager::GetJob](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopymanager-getjob)