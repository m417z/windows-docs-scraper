# ICCompressorChoose function

## Description

The **ICCompressorChoose** function displays a dialog box in which a user can select a compressor. This function can display all registered compressors or list only the compressors that support a specific format.

## Parameters

### `hwnd`

Handle to a parent window for the dialog box.

### `uiFlags`

Applicable flags. The following values are defined.

| Value | Meaning |
| --- | --- |
| ICMF_CHOOSE_ALLCOMPRESSORS | All compressors should appear in the selection list. If this flag is not specified, only the compressors that can handle the input format appear in the selection list. |
| ICMF_CHOOSE_DATARATE | Displays a check box and edit box to enter the data rate for the movie. |
| ICMF_CHOOSE_KEYFRAME | Displays a check box and edit box to enter the frequency of key frames. |
| ICMF_CHOOSE_PREVIEW | Displays a button to expand the dialog box to include a preview window. The preview window shows how frames of your movie will appear when compressed with the current settings. |

### `pvIn`

Uncompressed data input format. Only compressors that support the specified data input format are included in the compressor list. This parameter is optional.

### `lpData`

Pointer to an AVI stream interface to use in the preview window. You must specify a video stream. This parameter is optional.

### `pc`

Pointer to a [COMPVARS](https://learn.microsoft.com/windows/desktop/api/vfw/ns-vfw-compvars) structure. The information returned initializes the structure for use with other functions.

### `lpszTitle`

Pointer to a null-terminated string containing a title for the dialog box. This parameter is optional.

## Return value

Returns **TRUE** if the user chooses a compressor and presses OK. Returns **FALSE** on error or if the user presses CANCEL.

## Remarks

Before using this function, set the **cbSize** member of the [COMPVARS](https://learn.microsoft.com/windows/desktop/api/vfw/ns-vfw-compvars) structure to the size of the structure. Initialize the rest of the structure to zeros unless you want to specify some valid defaults for the dialog box. If specifying defaults, set the *dwFlags* member to ICMF_COMPVARS_VALID and initialize the other members of the structure. For more information about initializing the structure, see the [ICSeqCompressFrameStart](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-icseqcompressframestart) function and **COMPVARS**.

## See also

[Video Compression Functions](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-functions)

[Video Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-manager)