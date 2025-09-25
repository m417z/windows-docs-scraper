# IBackgroundCopyFile3::GetTemporaryName

## Description

Gets the full path of the temporary file that contains the content of the download.

## Parameters

### `pFilename` [out]

Null-terminated string that contains the full path of the temporary file. Call the
[CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function to free *ppFileName* when done.

## Return value

The method returns the following return values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success |

## Remarks

Applications can use this method to gain access to the data before the job is complete. Open the file for shared write access (FILE_SHARE_WRITE). To determine how many bytes have been transferred and are available for reading, call the [IBackgroundCopyFile::GetProgress](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyfile-getprogress) method. Note that the progress information will be set back to zero if the time stamp of the URL changes.

Do not open the file for reading until BITS begins transferring the file; otherwise, the job will go into the transient error state.

 The temporary file is available until the application calls the [IBackgroundCopyJob::Complete](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-complete) or [IBackgroundCopyJob::Cancel](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-cancel) method, or the JobInactivityTimeout group policy expires. You must release your handle to the temporary file before calling the **Complete** or **Cancel** method.

The ACL for the temporary file is the same as that of the final file when [Complete](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-complete) is called (the ACL is inherited from the folder).

To determine if BITS finished transferring the file, you can:

* Call the [IBackgroundCopyFile::GetProgress](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyfile-getprogress) method and compare **BytesTransferred** to **BytesTotal**.
* Implement the [IBackgroundCopyCallback2::FileTransferred](https://learn.microsoft.com/windows/desktop/api/bits3_0/nf-bits3_0-ibackgroundcopycallback2-filetransferred) callback.

## See also

[IBackgroundCopyCallback2::FileTransferred](https://learn.microsoft.com/windows/desktop/api/bits3_0/nf-bits3_0-ibackgroundcopycallback2-filetransferred)

[IBackgroundCopyFile3](https://learn.microsoft.com/windows/desktop/api/bits3_0/nn-bits3_0-ibackgroundcopyfile3)