# IBackgroundCopyJob::AddFile

## Description

Adds a single file to the job.

## Parameters

### `RemoteUrl` [in]

Null-terminated string that contains the name of the file on the server. For information on specifying the remote name, see the **RemoteName** member and Remarks section of the [BG_FILE_INFO](https://learn.microsoft.com/windows/desktop/api/bits/ns-bits-bg_file_info) structure.

### `LocalName` [in]

Null-terminated string that contains the name of the file on the client. For information on specifying the local name, see the **LocalName** member and Remarks section of the [BG_FILE_INFO](https://learn.microsoft.com/windows/desktop/api/bits/ns-bits-bg_file_info) structure.

## Return value

This method returns the following **HRESULT** values, as well as others.

| Return code | Description |
| --- | --- |
| ****S_OK**** | File was successfully added to the job. |
| **BG_E_TOO_MANY_FILES** | Upload jobs can only contain one file; you cannot add another file to the job. |
| **BG_E_TOO_MANY_FILES_IN_JOB** | The MaxFilesPerJob Group Policy setting determines how many files a job can contain. Adding the file to the job exceeds the MaxFilesPerJob limit. |
| **E_INVALIDARG** | You can receive this error for one of the following reasons:<br><br>* The local or remote file name is not valid.<br>* The remote file name uses an unsupported protocol.<br>* The local file name was specified using a relative path. |
| **E_ACCESSDENIED** | User does not have permission to write to the specified directory on the client. |

## Remarks

To add more than one file at a time to a job, call the
[IBackgroundCopyJob::AddFileSet](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-addfileset) method. It is more efficient to call the **AddFileSet** method when adding multiple files to a job than to call the **AddFile** method in a loop. For more information, see [Adding Files to a Job](https://learn.microsoft.com/windows/desktop/Bits/adding-files-to-a-job).

To add a file to a job from which BITS downloads ranges of data from the file, call the [IBackgroundCopyJob3::AddFileWithRanges](https://learn.microsoft.com/windows/desktop/api/bits2_0/nf-bits2_0-ibackgroundcopyjob3-addfilewithranges) method.

Upload jobs can only contain one file. If you add a second file, the method returns BG_E_TOO_MANY_FILES.

For downloads, BITS guarantees that the version of a file (based on file size and date, not content) that it transfers will be consistent; however, it does not guarantee that a set of files will be consistent. For example, if BITS is in the middle of downloading the second of two files in the job at the time that the files are updated on the server, BITS restarts the download of the second file; however, the first file is not downloaded again.

Note that if you own the file being downloaded from the server, you should create a new URL for each new version of the file. If you use the same URL for new versions of the file, some proxy servers may serve stale data from their cache because they do not verify with the original server if the file is stale.

For uploads, BITS generates an error if the local file changes while the file is transferring. The error code is BG_E_FILE_CHANGED and the context is BG_ERROR_CONTEXT_LOCAL_FILE.

BITS transfers the files within a job sequentially. If an error occurs while transferring a file, the job moves to an error state and no more files within the job are processed until the error is resolved.

By default, a user can add up to 200 files to a job. This limit does not apply to administrators or service accounts. To change the default, set the **MaxFilesPerJob** group policies.

**Prior to Windows Vista:** There is no limit on the number of files that a user can add to a job.

For scalability concerns, see [Best Practices When Using BITS](https://learn.microsoft.com/windows/desktop/Bits/best-practices-when-using-bits).

#### Examples

For an example that adds a single file to a job, see
[Adding Files to a Job](https://learn.microsoft.com/windows/desktop/Bits/adding-files-to-a-job).

## See also

[IBackgroundCopyJob3::AddFileWithRanges](https://learn.microsoft.com/windows/desktop/api/bits2_0/nf-bits2_0-ibackgroundcopyjob3-addfilewithranges)

[IBackgroundCopyJob::AddFileSet](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-addfileset)

[IBackgroundCopyJob::EnumFiles](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-enumfiles)

[IBackgroundCopyJob::GetState](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-getstate)

[IBackgroundCopyJob::Resume](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-resume)