# IBackgroundCopyJob1::GetFileCount

## Description

[**IBackgroundCopyJob1** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use the [BITS interfaces](https://learn.microsoft.com/windows/desktop/Bits/bits-interfaces).]

Use the **GetFileCount** method to retrieve the number of files in the job.

## Parameters

### `pdwFileCount` [out]

Number of files in the job.

## Return value

This method returns the following **HRESULT** values, as well as others.

| Return code | Description |
| --- | --- |
| ****S_OK**** | Successfully retrieved the number of files in the job. |

## See also

[IBackgroundCopyJob1](https://learn.microsoft.com/windows/desktop/api/qmgr/nn-qmgr-ibackgroundcopyjob1)