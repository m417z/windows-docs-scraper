# IBackgroundCopyJob::Complete

## Description

Ends the job and saves the transferred files on the client.

## Return value

This method returns the following **HRESULT** values. The method can also return errors related to renaming the temporary copies of the transferred files to their given names.

| Return code | Description |
| --- | --- |
| ****S_OK**** | All files transferred successfully. |
| **BG_S_PARTIAL_COMPLETE** | A subset of the files transferred successfully. |
| **BG_S_UNABLE_TO_DELETE_FILES** | Job was successfully completed; however, the service was unable to delete the temporary files associated with the job. |
| **BG_E_INVALID_STATE** | For downloads, the state of the job cannot be BG_JOB_STATE_CANCELLED or BG_JOB_STATE_ACKNOWLEDGED. <br><br>For uploads, the state of the job must be BG_JOB_STATE_TRANSFERRED. |

## Remarks

Download files are not available until you call the
**Complete** method. Call the
**Complete** method after BITS successfully transfers the files. The
method renames the temporary download files to their final destination names and removes the job from the queue. Note that BITS renames the temporary upload file when the server receives the last fragment, which is why download jobs require network connectivity and upload jobs do not.

All of the files have been successfully transferred if the job's state is **BG_JOB_STATE_TRANSFERRED**. To check the state of the job, call the
[IBackgroundCopyJob::GetState](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-getstate) method. You can also implement the
[IBackgroundCopyCallback](https://learn.microsoft.com/windows/desktop/api/bits/nn-bits-ibackgroundcopycallback) interface to receive notification when all of the files have been transferred to the client.

If you do not call the
**Complete** method or the
[IBackgroundCopyJob::Cancel](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-cancel) method within 90 days (default [JobInactivityTimeout](https://learn.microsoft.com/windows/desktop/Bits/group-policies) Group Policy), the service cancels the job. If the service cancels the job, the downloaded files and the reply file are not available to the client; job cancellation does not affect files that have been successfully uploaded.

BITS removes the job from the transfer queue if the HRESULT is **S_OK** or BG_S_PARTIAL_COMPLETE. The job remains in the transfer queue if BITS was unable to rename all of the temporary files. Files that were renamed successfully are available to the user. The job remains in the queue (the state is **BG_JOB_STATE_TRANSFERRED**) until the application is able to fix the problem and calls either the
**Complete** method again or the
[IBackgroundCopyJob::Cancel](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-cancel) method to cancel the job. To determine which files were not renamed for download jobs, see the **Completed** member of the
[BG_FILE_PROGRESS](https://learn.microsoft.com/windows/desktop/api/bits/ns-bits-bg_file_progress) structure.

For download jobs, you can call the
**Complete** method at anytime during the transfer process; however, only files that were successfully transferred to the client before calling this method are saved. For example, if you call the
**Complete** method while BITS is processing the third of five files, only the first two files are saved. To determine which files have been transferred, call the
[IBackgroundCopyFile::GetProgress](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyfile-getprogress) method and compare the **BytesTransferred** member to the **BytesTotal** member of the
[BG_FILE_PROGRESS](https://learn.microsoft.com/windows/desktop/api/bits/ns-bits-bg_file_progress) structure.

For upload jobs, you can call the
**Complete** method only when the job's state is **BG_JOB_STATE_TRANSFERRED**.

BITS does not guarantee the integrity of the transferred files against third-party intrusions. Clients can implement integrity checks to validate transferred files after calling the
**Complete** method.

The owner of the file is the user who made the call. For example, if an administrator completes someone else's job, the administrator—not the owner of the job—owns the file.

**BITS 1.2 and earlier:** The owner of the file is the owner of the job, regardless of who called the **Complete** method.

## See also

[Completing and Canceling a Job](https://learn.microsoft.com/windows/desktop/Bits/completing-and-canceling-a-job)

[IBackgroundCopyCallback::JobTransferred](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopycallback-jobtransferred)

[IBackgroundCopyJob::Cancel](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-cancel)

[IBackgroundCopyJob::GetState](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-getstate)