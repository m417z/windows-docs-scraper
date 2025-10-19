# IBackgroundCopyJob2::SetReplyFileName

## Description

Specifies the name of the file to contain the reply data from the server application. Call this method only if the job's type is **BG_JOB_TYPE_UPLOAD_REPLY**.

## Parameters

### `ReplyFileName` [in]

Null-terminated string that contains the full path to the reply file. BITS generates the file name if *ReplyFileNamePathSpec* is **NULL** or an empty string. You cannot use wildcards in the path or file name, and directories in the path must exist. The path is limited to MAX_PATH, not including the null terminator. The user must have permissions to write to the directory. BITS does not support NTFS streams. Instead of using network drives, which are session specific, use UNC paths (for example, \\server\share\path\file). Do not include the \\? prefix in the path.

## Return value

This method returns the following **HRESULT** values, as well as others.

| Return code | Description |
| --- | --- |
| **S_OK** | Successfully specified the name of the file to contain the reply data. |
| **BG_E_INVALID_STATE** | You cannot change the reply file name after BITS begins transferring the reply to the client. BITS is transferring the reply to the client if the state is **BG_JOB_STATE_TRANSFERRING** and the **BytesTotal** member of the [BG_JOB_REPLY_PROGRESS](https://learn.microsoft.com/windows/desktop/api/bits1_5/ns-bits1_5-bg_job_reply_progress) structure is not **BG_SIZE_UNKNOWN**. |
| **E_ACCESSDENIED** | User does not have permission to write to the specified directory on the client. |
| **E_INVALIDARG** | The reply file name is invalid or exceeds **MAX_PATH**. |

## Remarks

BITS generates the file name if you do not call the
**SetReplyFileName** method before calling the
[IBackgroundCopyJob::Resume](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-resume) method for the first time.

If BITS generates the file name, the reply file is written to the same directory as the local upload file.

You can call the
**SetReplyFileName** method anytime before BITS begins downloading the reply from the server application; the method fails if the download has begun.

The reply file is available to the client after calling the
[IBackgroundCopyJob::Complete](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-complete) method. To retrieve the reply data before calling the
**Complete** method, call the
[IBackgroundCopyJob2::GetReplyData](https://learn.microsoft.com/windows/desktop/api/bits1_5/nf-bits1_5-ibackgroundcopyjob2-getreplydata) method.

The file is empty if the server application did not provide a reply.

## See also

[IBackgroundCopyJob::GetReplyData](https://learn.microsoft.com/windows/desktop/api/bits1_5/nf-bits1_5-ibackgroundcopyjob2-getreplydata)

[IBackgroundCopyJob::GetReplyFileName](https://learn.microsoft.com/windows/desktop/api/bits1_5/nf-bits1_5-ibackgroundcopyjob2-getreplyfilename)