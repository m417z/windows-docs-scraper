# AVISaveOptions function

## Description

The **AVISaveOptions** function retrieves the save options for a file and returns them in a buffer.

## Parameters

### `hwnd`

Handle to the parent window for the Compression Options dialog box.

### `uiFlags`

Flags for displaying the Compression Options dialog box. The following flags are defined.

| Value | Meaning |
| --- | --- |
| ICMF_CHOOSE_KEYFRAME | Displays a Key Frame Every dialog box for the video options. This is the same flag used in the [ICCompressorChoose](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-iccompressorchoose) function. |
| ICMF_CHOOSE_DATARATE | Displays a Data Rate dialog box for the video options. This is the same flag used in [ICCompressorChoose](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-iccompressorchoose). |
| ICMF_CHOOSE_PREVIEW | Displays a Preview button for the video options. This button previews the compression by using a frame from the stream. This is the same flag used in [ICCompressorChoose](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-iccompressorchoose). |

### `nStreams`

Number of streams that have their options set by the dialog box.

### `ppavi`

Pointer to an array of stream interface pointers. The *nStreams* parameter indicates the number of pointers in the array.

### `plpOptions`

Pointer to an array of pointers to [AVICOMPRESSOPTIONS](https://learn.microsoft.com/windows/desktop/api/vfw/ns-vfw-avicompressoptions) structures. These structures hold the compression options set by the dialog box. The *nStreams* parameter indicates the number of pointers in the array.

## Return value

Returns **TRUE** if the user pressed OK, **FALSE** for CANCEL, or an error otherwise.

## Remarks

This function presents a standard Compression Options dialog box using *hwnd* as the parent window handle. When the user is finished selecting the compression options for each stream, the options are returned in the [AVICOMPRESSOPTIONS](https://learn.microsoft.com/windows/desktop/api/vfw/ns-vfw-avicompressoptions) structure in the array referenced by *plpOptions*. The calling application must pass the interface pointers for the streams in the array referenced by *ppavi*.

An application must allocate memory for the [AVICOMPRESSOPTIONS](https://learn.microsoft.com/windows/desktop/api/vfw/ns-vfw-avicompressoptions) structures and the array of pointers to these structures.

The argument *ppavi* contains the address of a pointer to an [IAVIStream](https://learn.microsoft.com/windows/desktop/api/vfw/nn-vfw-iavistream) interface.

## See also

[AVIFile Functions](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions)

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)