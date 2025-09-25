# COPYFILE2_MESSAGE_ACTION enumeration

## Description

Returned by the
[CopyFile2ProgressRoutine](https://learn.microsoft.com/windows/desktop/api/winbase/nc-winbase-pcopyfile2_progress_routine) callback function to
indicate what action should be taken for the pending copy operation.

## Constants

### `COPYFILE2_PROGRESS_CONTINUE:0`

Continue the copy operation.

### `COPYFILE2_PROGRESS_CANCEL`

Cancel the copy operation. The [CopyFile2](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-copyfile2) call will fail
and return `HRESULT_FROM_WIN32(ERROR_REQUEST_ABORTED)` and
any partially copied fragments will be deleted.

### `COPYFILE2_PROGRESS_STOP`

Stop the copy operation. The [CopyFile2](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-copyfile2) call will fail
and return `HRESULT_FROM_WIN32(ERROR_REQUEST_ABORTED)` and
any partially copied fragments will be left intact. The operation can be restarted using the
**COPY_FILE_RESUME_FROM_PAUSE** flag only if the
**COPY_FILE_RESTARTABLE** flag was set in the **dwCopyFlags**
member of the
[COPYFILE2_EXTENDED_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-copyfile2_extended_parameters) structure
passed to the **CopyFile2** function.

### `COPYFILE2_PROGRESS_QUIET`

Continue the copy operation but do not call the
[CopyFile2ProgressRoutine](https://learn.microsoft.com/windows/desktop/api/winbase/nc-winbase-pcopyfile2_progress_routine) callback function
again for this operation.

### `COPYFILE2_PROGRESS_PAUSE`

Pause the copy operation and write a restart header. This value is not compatible with the
**COPY_FILE_RESTARTABLE** flag for the **dwCopyFlags** member of
the [COPYFILE2_EXTENDED_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-copyfile2_extended_parameters)
structure. In most cases the [CopyFile2](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-copyfile2) call will fail and
return `HRESULT_FROM_WIN32(ERROR_REQUEST_PAUSED)` and any
partially copied fragments will be left intact (except for the header written that is used to resume the copy
operation later.) In case the copy operation was complete at the time the pause request is processed the
**CopyFile2** call will complete successfully and no resume
header will be written. After this value is processed one more callback will be made to the
[CopyFile2ProgressRoutine](https://learn.microsoft.com/windows/desktop/api/winbase/nc-winbase-pcopyfile2_progress_routine) with the message
specifying a **COPYFILE2_CALLBACK_STREAM_FINISHED** (4) value in the
**Type** member of the
[COPYFILE2_MESSAGE](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-copyfile2_message) structure. After the callback has
returned CopyFile2 will fail with
`HRESULT_FROM_WIN32(ERROR_REQUEST_PAUSED)`.

## Remarks

To compile an application that uses this enumeration, define the **_WIN32_WINNT**
macro as 0x0601 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## See also

[CopyFile2](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-copyfile2)

[CopyFile2ProgressRoutine](https://learn.microsoft.com/windows/desktop/api/winbase/nc-winbase-pcopyfile2_progress_routine)

[File Management Enumerations](https://learn.microsoft.com/windows/desktop/FileIO/file-management-enumerations)