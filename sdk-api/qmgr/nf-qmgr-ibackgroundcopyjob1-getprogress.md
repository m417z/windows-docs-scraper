# IBackgroundCopyJob1::GetProgress

## Description

[**IBackgroundCopyJob1** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use the [BITS interfaces](https://learn.microsoft.com/windows/desktop/Bits/bits-interfaces).]

Use the **GetProgress** method to retrieve the job's progress.

## Parameters

### `dwFlags` [in]

Type of progress to retrieve. Specify one of the following flags.

| Value | Meaning |
| --- | --- |
| **QM_PROGRESS_PERCENT_DONE** | Returns the percent of the download that is complete. |
| **QM_PROGRESS_SIZE_DONE** | Returns the number of bytes downloaded. |
| **QM_PROGRESS_TIME_DONE** | Not supported. |

### `pdwProgress` [out]

Progress of the download. The progress represents the number of bytes downloaded or the percent of the download that is complete, depending on *dwFlags*.

## Return value

This method returns the following **HRESULT** values, as well as others.

| Return code | Description |
| --- | --- |
| ****S_OK**** | Successfully retrieved the job's progress. |
| **E_NOTIMPL** | You cannot specify QM_PROGRESS_TIME_DONE for the *dwFlags* parameter. |

## See also

[IBackgroundCopyJob1](https://learn.microsoft.com/windows/desktop/api/qmgr/nn-qmgr-ibackgroundcopyjob1)