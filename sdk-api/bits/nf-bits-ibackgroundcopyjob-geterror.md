# IBackgroundCopyJob::GetError

## Description

Retrieves the error interface after an error occurs.

BITS generates an error object when the state of the job is
[BG_JOB_STATE_ERROR](https://learn.microsoft.com/windows/desktop/api/bits/ne-bits-bg_job_state) or BG_JOB_STATE_TRANSIENT_ERROR. The service does not create an error object when a call to an **IBackgroundCopyXXXX** interface method fails. The error object is available until BITS begins transferring data (the state of the job changes to BG_JOB_STATE_TRANSFERRING) for the job or until your application exits.

## Parameters

### `ppError` [out]

Error interface that provides the error code, a description of the error, and the context in which the error occurred. This parameter also identifies the file being transferred at the time the error occurred. Release *ppError* when done.

## Return value

This method returns the following **HRESULT** values, as well as others.

| Return code | Description |
| --- | --- |
| ****S_OK**** | Successfully generated the error object. |
| **BG_E_ERROR_INFORMATION_UNAVAILABLE** | The error interface is available only after an error occurs (BG_JOB_STATE_ERROR or BG_JOB_STATE_TRANSIENT_ERROR) and before BITS begins transferring data (BG_JOB_STATE_TRANSFERRING). |

## Remarks

The job is placed in an error state on fatal errors or after the
no-progress-timeout period expires for transient errors (this period is retrieved from the [GetNoProgressTimeout](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-getprogress) method). Use one of the following options to determine if the job is in error:

* To poll for the state of the job, call the
  [IBackgroundCopyJob::GetState](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-getstate) method. The job is in error if the state is BG_JOB_STATE_ERROR.
* To receive notification when an error occurs, implement the
  [IBackgroundCopyCallback](https://learn.microsoft.com/windows/desktop/api/bits/nn-bits-ibackgroundcopycallback) interface (specifically, the
  [JobError](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopycallback-joberror) method). Then, call the
  [IBackgroundCopyJob::SetNotifyInterface](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-setnotifyinterface) method to register the callback and the
  [IBackgroundCopyJob::SetNotifyFlags](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-setnotifyflags) method to set the BG_NOTIFY_JOB_ERROR flag.

The
[IBackgroundCopyError](https://learn.microsoft.com/windows/desktop/api/bits/nn-bits-ibackgroundcopyerror) interface contains information that you use to determine the cause of the error and if the transfer process can proceed. After you determine the cause of the error, perform one of the following options:

* To cancel the job, call the
  [IBackgroundCopyJob::Cancel](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-cancel) method.
* To save those files that transferred successfully before the error occurred, call the
  [IBackgroundCopyJob::Complete](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-complete) method.
* To finish processing the job, fix the problem, and then call the
  [IBackgroundCopyJob::Resume](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-resume) method.

If the job remains in an error state for 90 days (default [JobInactivityTimeout](https://learn.microsoft.com/windows/desktop/Bits/group-policies) Group Policy), the service removes the job from the queue and deletes the temporary files on the client; job deletion does not affect files that have been successfully uploaded.

To determine whether the upload, reply, or server application portion of an upload-reply job failed, call the
[IBackgroundCopyError::GetError](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyerror-geterror) method to retrieve the
[context](https://learn.microsoft.com/windows/win32/api/bits/ne-bits-bg_error_context) in which the error occurred. The server application failed if the context is BG_ERROR_CONTEXT_REMOTE_APPLICATION. If the error is with the upload or reply, the context is BG_ERROR_CONTEXT_REMOTE_FILE. The upload failed if the **BytesTotal** member of the
[BG_JOB_REPLY_PROGRESS](https://learn.microsoft.com/windows/desktop/api/bits1_5/ns-bits1_5-bg_job_reply_progress) structure is BG_SIZE_UNKNOWN. Otherwise, the reply failed.

#### Examples

See the example code in the
[Handling Errors](https://learn.microsoft.com/windows/desktop/Bits/handling-errors) topic.

## See also

[IBackgroundCopyCallback::JobError](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopycallback-joberror)

[IBackgroundCopyError](https://learn.microsoft.com/windows/desktop/api/bits/nn-bits-ibackgroundcopyerror)

[IBackgroundCopyJob::GetState](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-getstate)