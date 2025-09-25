# LPPROGRESS_ROUTINE callback function

## Description

An application-defined callback function used with the
[CopyFileEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-copyfileexa),
[MoveFileTransacted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-movefiletransacteda), and
[MoveFileWithProgress](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-movefilewithprogressa) functions. It is
called when a portion of a copy or move operation is completed. The
**LPPROGRESS_ROUTINE** type defines a pointer to this callback function.
**CopyProgressRoutine** is a placeholder for the
application-defined function name.

## Parameters

### `TotalFileSize` [in]

The total size of the file, in bytes.

### `TotalBytesTransferred` [in]

The total number of bytes transferred from the source file to the destination file since the copy operation
began.

### `StreamSize` [in]

The total size of the current file stream, in bytes.

### `StreamBytesTransferred` [in]

The total number of bytes in the current stream that have been transferred from the source file to the
destination file since the copy operation began.

### `dwStreamNumber` [in]

A handle to the current stream. The first time
**CopyProgressRoutine** is called, the stream number
is 1.

### `dwCallbackReason` [in]

The reason that **CopyProgressRoutine** was
called. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CALLBACK_CHUNK_FINISHED**<br><br>0x00000000 | Another part of the data file was copied. |
| **CALLBACK_STREAM_SWITCH**<br><br>0x00000001 | Another stream was created and is about to be copied. This is the callback reason given when the callback routine is first invoked. |

### `hSourceFile` [in]

A handle to the source file.

### `hDestinationFile` [in]

A handle to the destination file

### `lpData` [in, optional]

Argument passed to **CopyProgressRoutine** by
[CopyFileEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-copyfileexa),
[MoveFileTransacted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-movefiletransacteda), or
[MoveFileWithProgress](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-movefilewithprogressa).

## Return value

The **CopyProgressRoutine** function should return
one of the following values.

| Return code/value | Description |
| --- | --- |
| **PROGRESS_CANCEL**<br><br>1 | Cancel the copy operation and delete the destination file. |
| **PROGRESS_CONTINUE**<br><br>0 | Continue the copy operation. |
| **PROGRESS_QUIET**<br><br>3 | Continue the copy operation, but stop invoking [CopyProgressRoutine](https://learn.microsoft.com/windows/desktop/api/winbase/nc-winbase-lpprogress_routine) to report progress. |
| **PROGRESS_STOP**<br><br>2 | Stop the copy operation. It can be restarted at a later time. |

## Remarks

An application can use this information to display a progress bar that shows the total number of bytes copied
as a percent of the total file size.

## See also

[CopyFileEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-copyfileexa)

[File Management Functions](https://learn.microsoft.com/windows/desktop/FileIO/file-management-functions)

[MoveFileTransacted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-movefiletransacteda)

[MoveFileWithProgress](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-movefilewithprogressa)