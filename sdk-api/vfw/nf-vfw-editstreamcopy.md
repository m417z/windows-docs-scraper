# EditStreamCopy function

## Description

The **EditStreamCopy** function copies an editable stream (or a portion of it) into a temporary stream.

## Parameters

### `pavi`

Handle to the stream being copied.

### `plStart`

Starting position within the stream being copied. The starting position is returned.

### `plLength`

Amount of data to copy from the stream referenced by *pavi*. The length of the copied data is returned.

### `ppResult`

Pointer to a buffer that receives the handle created for the new stream.

## Return value

Returns zero if successful or an error otherwise.

## Remarks

The stream that is copied must be created by the **CreateEditableStream** function or one of the stream editing functions.

The temporary stream can be treated as any other AVI stream.

## See also

[AVIFile Functions](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions)

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)