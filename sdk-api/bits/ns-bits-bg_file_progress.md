# BG_FILE_PROGRESS structure

## Description

Provides file-related progress information, such as the number of bytes transferred.

## Members

### `BytesTotal`

Size of the file in bytes. If BITS cannot determine the size of the file (for example, if the file or server does not exist), the value is BG_SIZE_UNKNOWN.

If you are downloading ranges from a file, **BytesTotal** reflects the total number of bytes you want to download from the file.

### `BytesTransferred`

Number of bytes transferred.

### `Completed`

For downloads, the value is **TRUE** if the file is available to the user; otherwise, the value is **FALSE**. Files are available to the user after calling the [IBackgroundCopyJob::Complete](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-complete) method. If the **Complete** method generates a transient error, those files processed before the error occurred are available to the user; the others are not. Use the **Completed** member to determine if the file is available to the user when
**Complete** fails.

For uploads, the value is **TRUE** when the file upload is complete; otherwise, the value is **FALSE**.

## Remarks

To determine if BITS transferred the file, you can:

* Compare **BytesTransferred** to **BytesTotal**.
* Implement the [IBackgroundCopyCallback2::FileTransferred](https://learn.microsoft.com/windows/desktop/api/bits3_0/nf-bits3_0-ibackgroundcopycallback2-filetransferred) callback.

Note that the progress values will be set back to zero if the time stamp of the URL changes.

## See also

[BG_JOB_PROGRESS](https://learn.microsoft.com/windows/desktop/api/bits/ns-bits-bg_job_progress)

[BG_JOB_REPLY_PROGRESS](https://learn.microsoft.com/windows/desktop/api/bits1_5/ns-bits1_5-bg_job_reply_progress)

[IBackgroundCopyFile::GetProgress](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyfile-getprogress)

[IBackgroundCopyJob3::AddFileWithRanges](https://learn.microsoft.com/windows/desktop/api/bits2_0/nf-bits2_0-ibackgroundcopyjob3-addfilewithranges)