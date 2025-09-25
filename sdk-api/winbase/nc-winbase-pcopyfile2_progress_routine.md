# PCOPYFILE2_PROGRESS_ROUTINE callback function

## Description

An application-defined callback function used with the
[CopyFile2](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-copyfile2) function. It is called when a portion of
a copy or move operation is completed. The **PCOPYFILE2_PROGRESS_ROUTINE** type defines a
pointer to this callback function.
**CopyFile2ProgressRoutine** is a placeholder for the
application-defined function name.

## Parameters

### `pMessage` [in]

Pointer to a [COPYFILE2_MESSAGE](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-copyfile2_message) structure.

### `pvCallbackContext` [in, optional]

Copy of value passed in the **pvCallbackContext** member of the
[COPYFILE2_EXTENDED_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-copyfile2_extended_parameters) structure
passed to [CopyFile2](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-copyfile2).

## Return value

Value from the [COPYFILE2_MESSAGE_ACTION](https://learn.microsoft.com/windows/desktop/api/winbase/ne-winbase-copyfile2_message_action)
enumeration indicating what action should be taken.

| Return code/value | Description |
| --- | --- |
| **COPYFILE2_PROGRESS_CONTINUE**<br><br>0 | Continue the copy operation. |
| **COPYFILE2_PROGRESS_CANCEL**<br><br>1 | Cancel the copy operation. The [CopyFile2](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-copyfile2) function will fail, return `HRESULT_FROM_WIN32(ERROR_REQUEST_ABORTED)` and any partially copied fragments will be deleted. |
| **COPYFILE2_PROGRESS_STOP**<br><br>2 | Stop the copy operation. The [CopyFile2](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-copyfile2) function will fail, return `HRESULT_FROM_WIN32(ERROR_REQUEST_ABORTED)` and any partially copied fragments will be left intact. The operation can be restarted using the **COPY_FILE_RESUME_FROM_PAUSE** flag only if **COPY_FILE_RESTARTABLE** was set in the **dwCopyFlags** member of the [COPYFILE2_EXTENDED_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-copyfile2_extended_parameters) structure passed to the **CopyFile2** function. |
| **COPYFILE2_PROGRESS_QUIET**<br><br>3 | Continue the copy operation but do not call the [CopyFile2ProgressRoutine](https://learn.microsoft.com/windows/desktop/api/winbase/nc-winbase-pcopyfile2_progress_routine) callback function again for this operation. |
| **COPYFILE2_PROGRESS_PAUSE**<br><br>4 | Pause the copy operation. In most cases the [CopyFile2](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-copyfile2) function will fail and return `HRESULT_FROM_WIN32(ERROR_REQUEST_PAUSED)` and any partially copied fragments will be left intact (except for the header written that is used to resume the copy operation later.) In case the copy operation was complete at the time the pause request is processed the **CopyFile2** call will complete successfully and no resume header will be written. |

## Remarks

The **COPYFILE2_CALLBACK_STREAM_FINISHED** message is the last message for a paused
copy. If **COPYFILE2_PROGRESS_PAUSE** is returned in response to a
**COPYFILE2_CALLBACK_STREAM_FINISHED** message then no further callbacks will be sent.

To compile an application that uses the **PCOPYFILE2_PROGRESS_ROUTINE**
function pointer type, define the **_WIN32_WINNT** macro as 0x0601 or later. For more
information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

In Windows 8 and Windows Server 2012, this function is supported by the following technologies.

| Technology | Supported |
| --- | --- |
| Server Message Block (SMB) 3.0 protocol | Yes |
| SMB 3.0 Transparent Failover (TFO) | Yes |
| SMB 3.0 with Scale-out File Shares (SO) | Yes |
| Cluster Shared Volume File System (CsvFS) | Yes |
| Resilient File System (ReFS) | Yes |