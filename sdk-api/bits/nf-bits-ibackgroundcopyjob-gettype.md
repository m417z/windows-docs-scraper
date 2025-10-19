# IBackgroundCopyJob::GetType

## Description

Retrieves the type of transfer being performed, such as a file download or upload.

## Parameters

### `pVal` [out]

Type of transfer being performed. For a list of transfer types, see the
[BG_JOB_TYPE](https://learn.microsoft.com/windows/desktop/api/bits/ne-bits-bg_job_type) enumeration.

## Return value

This method returns the following **HRESULT** values, as well as others.

| Return code | Description |
| --- | --- |
| **S_OK** | Transfer type was successfully retrieved. |
| **E_INVALIDARG** | The *pJobType* parameter cannot be **NULL**. |

## Remarks

Specify the type of transfer when you
[create the job](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopymanager-createjob).

## See also

[BG_JOB_TYPE](https://learn.microsoft.com/windows/desktop/api/bits/ne-bits-bg_job_type)

[IBackgroundCopyManager::CreateJob](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopymanager-createjob)