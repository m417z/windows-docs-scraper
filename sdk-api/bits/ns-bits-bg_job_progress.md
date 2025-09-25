## Description

Provides job-related progress information, such as the number of bytes and files transferred. For upload jobs, the progress applies to the upload file, not the reply file. To view reply file progress, see the
[BG_JOB_REPLY_PROGRESS](https://learn.microsoft.com/windows/desktop/api/bits1_5/ns-bits1_5-bg_job_reply_progress) structure.

## Members

### `BytesTotal`

Total number of bytes to transfer for all files in the job. If the value is BG_SIZE_UNKNOWN, the total size of all files in the job has not been determined. BITS does not set this value if it cannot determine the size of one of the files. For example, if the specified file or server does not exist, BITS cannot determine the size of the file.

If you are downloading ranges from the file, **BytesTotal** includes the total number of bytes you want to download from the file.

### `BytesTransferred`

Number of bytes transferred.

### `FilesTotal`

Total number of files to transfer for this job.

### `FilesTransferred`

Number of files transferred.

## See also

[BG_FILE_PROGRESS](https://learn.microsoft.com/windows/desktop/api/bits/ns-bits-bg_file_progress)

[BG_JOB_REPLY_PROGRESS](https://learn.microsoft.com/windows/desktop/api/bits1_5/ns-bits1_5-bg_job_reply_progress)

[IBackgroundCopyJob3::AddFileWithRanges](https://learn.microsoft.com/windows/desktop/api/bits2_0/nf-bits2_0-ibackgroundcopyjob3-addfilewithranges)

[IBackgroundCopyJob::GetProgress](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyjob-getprogress)