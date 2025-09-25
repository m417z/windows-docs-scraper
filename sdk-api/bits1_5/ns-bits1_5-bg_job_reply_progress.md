# BG_JOB_REPLY_PROGRESS structure

## Description

Provides progress information related to the reply portion of an upload-reply job.

## Members

### `BytesTotal`

Size of the file in bytes. The value is **BG_SIZE_UNKNOWN** if the reply has not begun.

### `BytesTransferred`

Number of bytes transferred.

## See also

[IBackgroundCopyJob2::GetReplyProgress](https://learn.microsoft.com/windows/desktop/api/bits1_5/nf-bits1_5-ibackgroundcopyjob2-getreplyprogress)