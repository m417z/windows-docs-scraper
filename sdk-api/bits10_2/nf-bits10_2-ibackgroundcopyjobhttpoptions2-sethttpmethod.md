# IBackgroundCopyJobHttpOptions2::SetHttpMethod

## Description

Overrides the default HTTP method used for a BITS transfer.

## Parameters

### `method` [in]

Type: **[LPCWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to a constant null-terminated string of wide characters containing the HTTP method name.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

BITS allows you, as the developer, to choose an HTTP method other than the default method. This increases BITS' ability to interact with servers that don't adhere to the normal BITS requirements for HTTP servers. Bear the following in mind when you choose a different HTTP method from the default one.

* BITS automatically changes the job priority to [BG_JOB_PRIORITY_FOREGROUND](https://learn.microsoft.com/windows/desktop/api/bits/ne-bits-bg_job_priority), and prevents that priority from being changed.
* An error that would ordinarily be resumable (such as loss of connectivity) transitions the job to an ERROR state. You, as the developer, can restart the job by calling [IBackgroundCopyJob::Resume](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-resume), and the job will be restarted from the beginning. See [Life Cycle of a BITS Job](https://learn.microsoft.com/windows/desktop/Bits/life-cycle-of-a-bits-job) for more information on BITS job states.
* BITS doesn’t allow DYNAMIC_CONTENT nor ON_DEMAND_MODE jobs with **SetHttpMethod**.

**SetHttpMethod** does nothing if the method name that you pass matches the default HTTP method for the transfer type. For example, if you set a download job method to "GET" (the default), then the job priority won't be changed. The HTTP method must be set before the first call to [IBackgroundCopyJob::Resume](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-resume) that starts the job.

## See also

[IBackgroundCopyJobHttpOptions2](https://learn.microsoft.com/windows/win32/api/bits10_2/nn-bits10_2-ibackgroundcopyjobhttpoptions2)