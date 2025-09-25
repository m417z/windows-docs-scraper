# COPYFILE2_MESSAGE structure

## Description

Passed to the
[CopyFile2ProgressRoutine](https://learn.microsoft.com/windows/desktop/api/winbase/nc-winbase-pcopyfile2_progress_routine) callback function with
information about a pending copy operation.

## Members

### `Type`

Value from the [COPYFILE2_MESSAGE_TYPE](https://learn.microsoft.com/windows/desktop/api/winbase/ne-winbase-copyfile2_message_type)
enumeration used as a discriminant for the **Info** union within this structure.

| Value | Meaning |
| --- | --- |
| **COPYFILE2_CALLBACK_CHUNK_STARTED**<br><br>1 | Indicates a single chunk of a stream has started to be copied. Information is in the **ChunkStarted** structure within the **Info** union. |
| **COPYFILE2_CALLBACK_CHUNK_FINISHED**<br><br>2 | Indicates the copy of a single chunk of a stream has completed. Information is in the **ChunkFinished** structure within the **Info** union. |
| **COPYFILE2_CALLBACK_STREAM_STARTED**<br><br>3 | Indicates both source and destination handles for a stream have been opened and the copy of the stream is about to be started. Information is in the **StreamStarted** structure within the **Info** union. This does not indicate that the copy has started for that stream. |
| **COPYFILE2_CALLBACK_STREAM_FINISHED**<br><br>4 | Indicates the copy operation for a stream have started to be completed, either successfully or due to a **COPYFILE2_PROGRESS_STOP** return from [CopyFile2ProgressRoutine](https://learn.microsoft.com/windows/desktop/api/winbase/nc-winbase-pcopyfile2_progress_routine). Information is in the **StreamFinished** structure within the **Info** union. |
| **COPYFILE2_CALLBACK_POLL_CONTINUE**<br><br>5 | May be sent periodically. Information is in the **PollContinue** structure within the **Info** union. |
| **COPYFILE2_CALLBACK_ERROR**<br><br>6 | An error was encountered during the copy operation. Information is in the **Error** structure within the **Info** union. |

### `dwPadding`

### `Info`

### `Info.ChunkStarted`

This structure is selected if the **Type** member is set to
**COPYFILE2_CALLBACK_CHUNK_STARTED** (1).

### `Info.ChunkStarted.dwStreamNumber`

Indicates which stream within the file is about to be copied. The value used for identifying a stream
within a file will start at one (1) and will always be higher than any previous stream for that file.

### `Info.ChunkStarted.dwReserved`

This member is reserved for internal use.

### `Info.ChunkStarted.hSourceFile`

Handle to the source stream.

### `Info.ChunkStarted.hDestinationFile`

Handle to the destination stream.

### `Info.ChunkStarted.uliChunkNumber`

Indicates which chunk within the current stream is about to be copied. The value used for a chunk will
start at zero (0) and will always be higher than that of any previous chunk for the current stream.

### `Info.ChunkStarted.uliChunkSize`

Size of the copied chunk, in bytes.

### `Info.ChunkStarted.uliStreamSize`

Size of the current stream, in bytes.

### `Info.ChunkStarted.uliTotalFileSize`

Size of all streams for this file, in bytes.

### `Info.ChunkFinished`

This structure is selected if the **Type** member is set to
**COPYFILE2_CALLBACK_CHUNK_FINISHED** (2).

##### ChunkFinished.dwReserved

This member is reserved for internal use.

### `Info.ChunkFinished.dwStreamNumber`

Indicates which stream within the file is about to be copied. The value used for identifying a stream
within a file will start at one (1) and will always be higher than any previous stream for that file.

### `Info.ChunkFinished.dwFlags`

### `Info.ChunkFinished.hSourceFile`

Handle to the source stream.

### `Info.ChunkFinished.hDestinationFile`

Handle to the destination stream.

### `Info.ChunkFinished.uliChunkNumber`

Indicates which chunk within the current stream is in process. The value used for a chunk will start at
zero (0) and will always be higher than that of any previous chunk for the current stream.

### `Info.ChunkFinished.uliChunkSize`

Size of the copied chunk, in bytes.

### `Info.ChunkFinished.uliStreamSize`

Size of the current stream, in bytes.

### `Info.ChunkFinished.uliStreamBytesTransferred`

Total bytes copied for this stream so far.

### `Info.ChunkFinished.uliTotalFileSize`

Size of all streams for this file, in bytes.

### `Info.ChunkFinished.uliTotalBytesTransferred`

Total bytes copied for this file so far.

### `Info.StreamStarted`

This structure is selected if the **Type** member is set to
**COPYFILE2_CALLBACK_STREAM_STARTED** (3).

### `Info.StreamStarted.dwStreamNumber`

Indicates which stream within the file is about to be copied. The value used for identifying a stream
within a file will start at one (1) and will always be higher than any previous stream for that file.

### `Info.StreamStarted.dwReserved`

This member is reserved for internal use.

### `Info.StreamStarted.hSourceFile`

Handle to the source stream.

### `Info.StreamStarted.hDestinationFile`

Handle to the destination stream.

### `Info.StreamStarted.uliStreamSize`

Size of the current stream, in bytes.

### `Info.StreamStarted.uliTotalFileSize`

Size of all streams for this file, in bytes.

### `Info.StreamFinished`

This structure is selected if the **Type** member is set to
**COPYFILE2_CALLBACK_STREAM_FINISHED** (4).

### `Info.StreamFinished.dwStreamNumber`

Indicates which stream within the file is about to be copied. The value used for identifying a stream
within a file will start at one (1) and will always be higher than any previous stream for that file.

### `Info.StreamFinished.dwReserved`

This member is reserved for internal use.

### `Info.StreamFinished.hSourceFile`

Handle to the source stream.

### `Info.StreamFinished.hDestinationFile`

Handle to the destination stream.

### `Info.StreamFinished.uliStreamSize`

Size of the current stream, in bytes.

### `Info.StreamFinished.uliStreamBytesTransferred`

Total bytes copied for this stream so far.

### `Info.StreamFinished.uliTotalFileSize`

Size of all streams for this file, in bytes.

### `Info.StreamFinished.uliTotalBytesTransferred`

Total bytes copied for this file so far.

### `Info.PollContinue`

This structure is selected if the **Type** member is set to
**COPYFILE2_CALLBACK_POLL_CONTNUE** (5).

### `Info.PollContinue.dwReserved`

This member is reserved for internal use.

### `Info.Error`

This structure is selected if the **Type** member is set to
**COPYFILE2_CALLBACK_ERROR** (6).

### `Info.Error.CopyPhase`

Value from the [COPYFILE2_COPY_PHASE](https://learn.microsoft.com/windows/desktop/api/winbase/ne-winbase-copyfile2_copy_phase)
enumeration indicating the current phase of the copy at the time of the error.

### `Info.Error.dwStreamNumber`

The number of the stream that was being processed at the time of the error.

### `Info.Error.hrFailure`

Value indicating the problem.

### `Info.Error.dwReserved`

This member is reserved for internal use.

### `Info.Error.uliChunkNumber`

Indicates which chunk within the current stream was being processed at the time of the error. The value
used for a chunk will start at zero (0) and will always be higher than that of any previous chunk for the
current stream.

### `Info.Error.uliStreamSize`

Size, in bytes, of the stream being processed.

### `Info.Error.uliStreamBytesTransferred`

Number of bytes that had been successfully transferred for the stream being processed.

### `Info.Error.uliTotalFileSize`

Size, in bytes, of the total file being processed.

### `Info.Error.uliTotalBytesTransferred`

Number of bytes that had been successfully transferred for the entire copy operation.

## Remarks

To compile an application that uses the
**COPYFILE2_MESSAGE** structure, define the
**_WIN32_WINNT** macro as 0x0601 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).