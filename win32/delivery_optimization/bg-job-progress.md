# BG_JOB_PROGRESS structure

The **BG_JOB_PROGRESS** structure provides job-related progress information, such as the number of bytes and files transferred. For upload jobs, the progress applies to the upload file, not the reply file.

## Members

**BytesTotal**

Total number of bytes to transfer for all files in the job. If the value is BG_SIZE_UNKNOWN, the total size of all files in the job has not been determined. Delivery Optimization does not set this value if it cannot determine the size of one of the files. For example, if the specified file or server does not exist, Delivery Optimization cannot determine the size of the file.

If you are downloading ranges from the file, **BytesTotal** includes the total number of bytes you want to download from the file.

**BytesTransferred**

Number of bytes transferred.

**FilesTotal**

Total number of files to transfer for this job.

**FilesTransferred**

Number of files transferred.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 10, version 1709 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server, version 1709 \[desktop apps only\]<br> |
| Header<br> | Deliveryoptimization.h |

## See also

[**BG_FILE_PROGRESS**](https://learn.microsoft.com/windows/win32/delivery_optimization/bg-file-progress)

[**IBackgroundCopyJob::GetProgress**](https://learn.microsoft.com/windows/win32/delivery_optimization/ibackgroundcopyjob-getprogress)

