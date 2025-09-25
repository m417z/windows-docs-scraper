# IBackgroundCopyCallback::JobTransferred

## Description

BITS calls your implementation of the
**JobTransferred** method when all of the files in the job have been successfully transferred. For BG_JOB_TYPE_UPLOAD_REPLY jobs, BITS calls the
**JobTransferred** method after the upload file has been transferred to the server and the reply has been transferred to the client.

## Parameters

### `pJob` [in]

Contains job-related information, such as the time the job completed, the number of bytes transferred, and the number of files transferred. Do not release *pJob*; BITS releases the interface when the method returns.

## Return value

This method should return **S_OK**; otherwise, BITS continues to call this method until **S_OK** is returned. For performance reasons, you should limit the number of times you return a value other than **S_OK** to a few times. As an alternative to returning an error code, consider always returning **S_OK** and handling the error internally. The interval at which this method is called is arbitrary.

Note that if this method fails and you called the [IBackgroundCopyJob2::SetNotifyCmdLine](https://learn.microsoft.com/windows/desktop/api/bits1_5/nf-bits1_5-ibackgroundcopyjob2-setnotifycmdline) method, the command line is executed and this method is not called again.

## Remarks

Typically, your implementation should call the
[IBackgroundCopyJob::Complete](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-complete) method to acknowledge that BITS successfully transferred the files. Download files and the reply file are not available on the client until you call the
**Complete** method.

If you do not call the [Complete](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-complete) method or the
[IBackgroundCopyJob::Cancel](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-cancel) method within 90 days (default [JobInactivityTimeout](https://learn.microsoft.com/windows/desktop/Bits/group-policies) Group Policy), BITS cancels the job and deletes the downloaded files and reply file; job cancellation does not affect files that have been successfully uploaded.

If you want to retrieve the reply data in your callback, query *pJob* for the
[IBackgroundCopyJob2](https://learn.microsoft.com/windows/desktop/api/bits1_5/nn-bits1_5-ibackgroundcopyjob2) interface and call its
[GetReplyData](https://learn.microsoft.com/windows/desktop/api/bits1_5/nf-bits1_5-ibackgroundcopyjob2-getreplydata) method. To retrieve the name of the file that contains the reply data, call the
[GetReplyFileName](https://learn.microsoft.com/windows/desktop/api/bits1_5/nf-bits1_5-ibackgroundcopyjob2-getreplyfilename) method.

BITS does not guarantee the integrity of the transferred files against third-party intrusions. Clients can implement integrity checks to validate transferred files before calling the [Complete](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-complete) method. To get notification when a file is transferred, implement the [IBackgroundCopyCallback2::FileTransferred](https://learn.microsoft.com/windows/desktop/api/bits3_0/nf-bits3_0-ibackgroundcopycallback2-filetransferred) method. Inside the callback, call the [IBackgroundCopyFile3::GetTemporaryName](https://learn.microsoft.com/windows/desktop/api/bits3_0/nf-bits3_0-ibackgroundcopyfile3-gettemporaryname) method to get the name of the temporary file that contains the downloaded content. Validate the contents and then call the [IBackgroundCopyFile3::SetValidationState](https://learn.microsoft.com/windows/desktop/api/bits3_0/nf-bits3_0-ibackgroundcopyfile3-setvalidationstate) method to indicate if the content is valid. If the content is not valid and BITS downloaded the file from the origin server, the job goes in the error state. If the job was downloaded from a peer, BITS downloads the file from the origin server.

**Note** BITS supports up to four simultaneous notifications per user. If one or more applications block all four notifications for a user from returning, an application running as the same user will not receive notifications until one or more of the blocking notifications return. To reduce the chance that your callback blocks other notifications, keep your implementation short.

#### Examples

See the example code for the
[IBackgroundCopyCallback](https://learn.microsoft.com/windows/desktop/api/bits/nn-bits-ibackgroundcopycallback) interface.

## See also

[IBackgroundCopyCallback](https://learn.microsoft.com/windows/desktop/api/bits/nn-bits-ibackgroundcopycallback)

[IBackgroundCopyJob](https://learn.microsoft.com/windows/desktop/api/bits/nn-bits-ibackgroundcopyjob)

[IBackgroundCopyJob::Cancel](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-cancel)

[IBackgroundCopyJob::Complete](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-complete)