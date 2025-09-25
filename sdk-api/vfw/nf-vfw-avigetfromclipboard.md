# AVIGetFromClipboard function

## Description

The **AVIGetFromClipboard** function copies an AVI file from the clipboard.

## Parameters

### `lppf`

Pointer to the location used to return the handle created for the AVI file.

## Return value

Returns zero if successful or an error otherwise.

## Remarks

If the clipboard does not contain an AVI file, **AVIGetFromClipboard** also can copy data with the CF_DIB or CF_WAVE clipboard flags to an AVI file. In this case, the function creates an AVI file with one DIB stream and one waveform-audio stream, and fills each stream with the data from the clipboard.

The argument *lppf* is the address of a pointer to an [IAVIFile](https://learn.microsoft.com/windows/desktop/api/vfw/nn-vfw-iavifile) interface.

## See also

[AVIFile Functions](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions)

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)