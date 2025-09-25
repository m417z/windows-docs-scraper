# IBackgroundCopyCallback::JobError

## Description

BITS calls your implementation of the
**JobError** method when the state of the job changes to BG_JOB_STATE_ERROR.

## Parameters

### `pJob` [in]

Contains job-related information, such as the number of bytes and files transferred before the error occurred. It also contains the methods to resume and cancel the job. Do not release *pJob*; BITS releases the interface when the **JobError** method returns.

### `pError` [in]

Contains error information, such as the file being processed at the time the fatal error occurred and a description of the error. Do not release *pError*; BITS releases the interface when the **JobError** method returns.

## Return value

This method should return **S_OK**; otherwise, BITS continues to call this method until **S_OK** is returned. For performance reasons, you should limit the number of times you return a value other than **S_OK** to a few times. As an alternative to returning an error code, consider always returning **S_OK** and handling the error internally. The interval at which this method is called is arbitrary.

Note that if this method fails and you called the [IBackgroundCopyJob2::SetNotifyCmdLine](https://learn.microsoft.com/windows/desktop/api/bits1_5/nf-bits1_5-ibackgroundcopyjob2-setnotifycmdline) method, the command line is executed and this method is not called again.

## Remarks

After you determine the cause of the error, perform one of the following options:

* To cancel the job, call the
  [IBackgroundCopyJob::Cancel](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-cancel) method. The cancel request has no effect on upload jobs if the error occurred after the file was successfully uploaded. However, if the job type is BG_JOB_TYPE_UPLOAD_REPLY and the upload was successful, calling the
  **Cancel** method cancels the request for the reply data.
* To accept the portion of the job that transferred successfully before the error occurred, call the
  [IBackgroundCopyJob::Complete](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-complete) method. This option does not apply to upload jobs; you cannot complete a portion of an upload job.
* To finish processing the job, fix the problem, and then call the
  [IBackgroundCopyJob::Resume](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-resume) method.

If the job remains in an error state for 90 days (default [JobInactivityTimeout](https://learn.microsoft.com/windows/desktop/Bits/group-policies) Group Policy), BITS cancels the job and deletes related temporary files; job cancellation does not affect files that have been successfully uploaded.

Transient errors do not generate calls to the
**JobError** method.

To determine whether the upload, reply, or server application portion of an upload reply job failed, call the
[IBackgroundCopyError::GetError](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyerror-geterror) method to retrieve the
[context](https://learn.microsoft.com/windows/win32/api/bits/ne-bits-bg_error_context) in which the error occurred. The server application failed if the context is BG_ERROR_CONTEXT_REMOTE_APPLICATION. The context for upload and reply is BG_ERROR_CONTEXT_REMOTE_FILE. The reply failed if the **BytesTotal** member of the
[BG_JOB_REPLY_PROGRESS](https://learn.microsoft.com/windows/desktop/api/bits1_5/ns-bits1_5-bg_job_reply_progress) structure is not BG_SIZE_UNKNOWN. Otherwise, the upload failed.

**Note** BITS supports up to four simultaneous notifications per user. If one or more applications block all four notifications for a user from returning, an application running as the same user will not receive notifications until one or more of the blocking notifications return. To reduce the chance that your callback blocks other notifications, keep your implementation short.

#### Examples

See the example code for the
[IBackgroundCopyCallback](https://learn.microsoft.com/windows/desktop/api/bits/nn-bits-ibackgroundcopycallback) interface.

## See also

[IBackgroundCopyCallback](https://learn.microsoft.com/windows/desktop/api/bits/nn-bits-ibackgroundcopycallback)

[IBackgroundCopyError](https://learn.microsoft.com/windows/desktop/api/bits/nn-bits-ibackgroundcopyerror)

[IBackgroundCopyJob](https://learn.microsoft.com/windows/desktop/api/bits/nn-bits-ibackgroundcopyjob)

[IBackgroundCopyJob::Cancel](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-cancel)

[IBackgroundCopyJob::Resume](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-resume)