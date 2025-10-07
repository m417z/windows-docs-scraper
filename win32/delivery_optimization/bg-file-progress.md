# BG_FILE_PROGRESS structure

The **BG_FILE_PROGRESS** structure provides file-related progress information, such as the number of bytes transferred.

## Members

**BytesTotal**

Size of the file in bytes. If Delivery Optimization cannot determine the size of the file (for example, if the file or server does not exist), the value is DO_UNKNOWN_FILE_SIZE.

If you are downloading ranges from a file, **BytesTotal** reflects the total number of bytes you want to download from the file.

**BytesTransferred**

Number of bytes transferred.

**Completed**

For downloads, the value is **TRUE** if the file is available to the user; otherwise, the value is **FALSE**. Files are available to the user after calling the [**IBackgroundCopyJob::Complete**](https://learn.microsoft.com/windows/win32/delivery_optimization/ibackgroundcopyjob-complete) method. If the **Complete** method generates a transient error, those files processed before the error occurred are available to the user; the others are not. Use the **Completed** member to determine if the file is available to the user when **Complete** fails.

## Remarks

To determine if Delivery Optimization transferred the file, you can:

- Compare **BytesTransferred** to **BytesTotal**.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 10, version 1709 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server, version 1709 \[desktop apps only\]<br> |
| Header<br> | Deliveryoptimization.h |

## See also

[**BG_JOB_PROGRESS**](https://learn.microsoft.com/windows/win32/delivery_optimization/bg-job-progress)

[**IBackgroundCopyFile::GetProgress**](https://learn.microsoft.com/windows/win32/delivery_optimization/ibackgroundcopyfile-getprogress-method)

