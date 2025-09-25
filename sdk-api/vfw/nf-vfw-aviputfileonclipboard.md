# AVIPutFileOnClipboard function

## Description

The **AVIPutFileOnClipboard** function copies an AVI file to the clipboard.

## Parameters

### `pf`

Handle to an open AVI file.

## Return value

Returns zero if successful or an error otherwise.

## Remarks

This function also copies data with the CF_DIB, CF_PALETTE, and CF_WAVE clipboard flags onto the clipboard using the first frame of the first video stream of the file as a DIB and using the audio stream as CF_WAVE.

The argument pf is a pointer to an [IAVIFile](https://learn.microsoft.com/windows/desktop/api/vfw/nn-vfw-iavifile) interface.

## See also

[AVIFile Functions](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions)

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)