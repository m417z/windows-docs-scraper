# EditStreamClone function

## Description

The **EditStreamClone** function creates a duplicate editable stream.

## Parameters

### `pavi`

Handle to an editable stream that will be copied.

### `ppResult`

Pointer to a buffer that receives the new stream handle.

## Return value

Returns zero if successful or an error otherwise.

## Remarks

The editable stream that is being cloned must have been created by the **CreateEditableStream** function or one of the stream editing functions.

The new stream can be treated as any other AVI stream.

## See also

[AVIFile Functions](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions)

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)