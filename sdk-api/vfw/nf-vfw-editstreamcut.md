# EditStreamCut function

## Description

The **EditStreamCut** function deletes all or part of an editable stream and creates a temporary editable stream from the deleted portion of the stream.

## Parameters

### `pavi`

Handle to the stream being edited.

### `plStart`

Starting position of the data to cut from the stream referenced by *pavi*.

### `plLength`

Amount of data to cut from the stream referenced by *pavi*.

### `ppResult`

Pointer to the handle created for the new stream.

## Return value

Returns zero if successful or an error otherwise.

## Remarks

The stream being edited must have been created by the **CreateEditableStream** function or one of the stream editing functions.

The temporary stream is an editable stream and can be treated as any other AVI stream. An application must release the temporary stream to free the resources associated with it.

## See also

[AVIFile Functions](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions)

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)