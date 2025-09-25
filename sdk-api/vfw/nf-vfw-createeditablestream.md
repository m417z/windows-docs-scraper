# CreateEditableStream function

## Description

The **CreateEditableStream** function creates an editable stream. Use this function before using other stream editing functions.

## Parameters

### `ppsEditable`

Pointer to a buffer that receives the new stream handle.

### `psSource`

Handle to the stream supplying data for the new stream. Specify **NULL** to create an empty editable string that you can copy and paste data into.

## Return value

Returns zero if successful or an error otherwise.

## Remarks

The stream pointer returned in *ppsEditable* must be used as the source stream in the other stream editing functions.

Internally, this function creates tables to keep track of changes to a stream. The original stream is never changed by the stream editing functions. The stream pointer created by this function can be used in any AVIFile function that accepts stream pointers. You can use this function on the same stream multiple times. A copy of a stream is not affected by changes in another copy.

## See also

[AVIFile Functions](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions)

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)