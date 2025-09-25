# EditStreamPaste function

## Description

The **EditStreamPaste** function copies a stream (or a portion of it) from one stream and pastes it within another stream at a specified location.

## Parameters

### `pavi`

Handle to an editable stream that will receive the copied stream data.

### `plPos`

Starting position to paste the data within the destination stream (referenced by *pavi*).

### `plLength`

Pointer to a buffer that receives the amount of data pasted in the stream.

### `pstream`

Handle to a stream supplying the data to paste. This stream does not need to be an editable stream.

### `lStart`

Starting position of the data to copy within the source stream.

### `lEnd`

Amount of data to copy from the source stream. If *lLength* is -1, the entire stream referenced by *pstream* is pasted in the other stream.

## Return value

Returns zero if successful or an error otherwise.

## Remarks

The stream referenced by *pavi* must have been created by the **CreateEditableStream** function or one of the stream editing functions.

This function inserts data into the specified stream as a continuous block of data. It opens the specified data stream at the insertion point, pastes the specified stream segment at the insertion point, and appends the stream segment that trails the insertion point to the end of pasted segment.

## See also

[AVIFile Functions](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions)

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)

[Positioning in Streams](https://learn.microsoft.com/windows/desktop/Multimedia/positioning-in-streams)