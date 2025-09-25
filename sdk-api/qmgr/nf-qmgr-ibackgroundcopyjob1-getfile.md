# IBackgroundCopyJob1::GetFile

## Description

[**IBackgroundCopyJob1** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use the [BITS interfaces](https://learn.microsoft.com/windows/desktop/Bits/bits-interfaces).]

Use the **GetFile** method to retrieve the remote and local file names for the given file in the job.

## Parameters

### `cFileIndex` [in]

Zero-based index that identifies the file in the job.

### `pFileInfo` [out]

A [FILESETINFO](https://learn.microsoft.com/windows/desktop/api/qmgr/ns-qmgr-filesetinfo) structure that contains the remote and local names of the file.

## Return value

This method returns the following **HRESULT** values, as well as others.

| Return code | Description |
| --- | --- |
| ****S_OK**** | Successfully retrieved the file from the job. |
| **QM_E_ITEM_NOT_FOUND** | The specified index is greater than the number of files in the job. |

## Remarks

Use with [IBackgroundCopyJob1::GetFileCount](https://learn.microsoft.com/windows/desktop/api/qmgr/nf-qmgr-ibackgroundcopyjob1-getfilecount) to iterate through the files of a job.

## See also

[IBackgroundCopyJob1](https://learn.microsoft.com/windows/desktop/api/qmgr/nn-qmgr-ibackgroundcopyjob1)