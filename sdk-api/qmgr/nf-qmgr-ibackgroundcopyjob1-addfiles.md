# IBackgroundCopyJob1::AddFiles

## Description

[**IBackgroundCopyJob1** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use the [BITS interfaces](https://learn.microsoft.com/windows/desktop/Bits/bits-interfaces).]

Use the **AddFiles** method to add one or more files to download to the job.

## Parameters

### `cFileCount` [in]

Number of files in *pFileInfo* to add to the job.

### `ppFileSet` [in]

Array of [FILESETINFO](https://learn.microsoft.com/windows/desktop/api/qmgr/ns-qmgr-filesetinfo) structures that contain the remote and local names of the files to download.

## Return value

This method returns the following **HRESULT** values, as well as others.

| Return code | Description |
| --- | --- |
| ****S_OK**** | Files were successfully added to the job. |
| **E_INVALIDARG** | Local or remote file name is invalid. For example, the remote file name specifies an unsupported protocol. |
| **E_ACCESSDENIED** | User does not have permission to write to the specified directory on the client. |

## See also

[IBackgroundCopyJob1](https://learn.microsoft.com/windows/desktop/api/qmgr/nn-qmgr-ibackgroundcopyjob1)