# COPYFILE2_MESSAGE_TYPE enumeration

## Description

Indicates the type of message passed in the
[COPYFILE2_MESSAGE](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-copyfile2_message) structure to the
[CopyFile2ProgressRoutine](https://learn.microsoft.com/windows/desktop/api/winbase/nc-winbase-pcopyfile2_progress_routine) callback
function.

## Constants

### `COPYFILE2_CALLBACK_NONE:0`

Not a valid value.

### `COPYFILE2_CALLBACK_CHUNK_STARTED`

Indicates a single chunk of a stream has started to be copied.

### `COPYFILE2_CALLBACK_CHUNK_FINISHED`

Indicates the copy of a single chunk of a stream has completed.

### `COPYFILE2_CALLBACK_STREAM_STARTED`

Indicates both source and destination handles for a stream have been opened and the copy of the stream is
about to be started.

### `COPYFILE2_CALLBACK_STREAM_FINISHED`

Indicates the copy operation for a stream have started to be completed.

### `COPYFILE2_CALLBACK_POLL_CONTINUE`

May be sent periodically.

### `COPYFILE2_CALLBACK_ERROR`

### `COPYFILE2_CALLBACK_MAX`

An error was encountered during the copy operation.

## Remarks

To compile an application that uses this enumeration, define the **_WIN32_WINNT**
macro as 0x0601 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## See also

[File Management Enumerations](https://learn.microsoft.com/windows/desktop/FileIO/file-management-enumerations)