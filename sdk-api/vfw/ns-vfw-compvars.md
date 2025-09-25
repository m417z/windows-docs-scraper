# COMPVARS structure

## Description

The **COMPVARS** structure describes compressor settings for functions such as [ICCompressorChoose](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-iccompressorchoose), [ICSeqCompressFrame](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-icseqcompressframe), and [ICCompressorFree](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-iccompressorfree).

## Members

### `cbSize`

Size, in bytes, of this structure. This member must be set to validate the structure before calling any function using this structure.

### `dwFlags`

Applicable flags. The following value is defined:

| Name | Description |
| --- | --- |
| **ICMF_COMPVARS_VALID** | Data in this structure is valid and has been manually entered. Set this flag before you call any function if you fill this structure manually. Do not set this flag if you let [ICCompressorChoose](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-iccompressorchoose) initialize this structure. |

### `hic`

Handle to the compressor to use. You can open a compressor and obtain a handle of it by using the [ICOpen](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-icopen) function. You can also choose a compressor by using [ICCompressorChoose](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-iccompressorchoose). **ICCompressorChoose** opens the chosen compressor and returns the handle of the compressor in this member. You can close the compressor by using [ICCompressorFree](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-iccompressorfree).

### `fccType`

Type of compressor used. Currently only **ICTYPE_VIDEO** (VIDC) is supported. This member can be set to zero.

### `fccHandler`

Four-character code of the compressor. Specify **NULL** to indicate the data is not to be recompressed. Specify "DIB" to indicate the data is an uncompressed, full frame. You can use this member to specify which compressor is selected by default when the dialog box is displayed.

### `lpbiIn`

Reserved; do not use.

### `lpbiOut`

Pointer to a [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure containing the image output format. You can specify a specific format to use or you can specify **NULL** to use the default compressor associated with the input format. You can also set the image output format by using [ICCompressorChoose](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-iccompressorchoose).

### `lpBitsOut`

Reserved; do not use.

### `lpBitsPrev`

Reserved; do not use.

### `lFrame`

Reserved; do not use.

### `lKey`

Key-frame rate. Specify an integer to indicate the frequency that key frames are to occur in the compressed sequence or zero to not use key frames. You can also let [ICCompressorChoose](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-iccompressorchoose) set the key-frame rate selected in the dialog box. The [ICSeqCompressFrameStart](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-icseqcompressframestart) function uses the value of this member for making key frames.

### `lDataRate`

Data rate, in kilobytes per second. [ICCompressorChoose](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-iccompressorchoose) copies the selected data rate from the dialog box to this member.

### `lQ`

Quality setting. Specify a quality setting of 1 to 10,000 or specify **ICQUALITY_DEFAULT** to use the default quality setting. You can also let [ICCompressorChoose](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-iccompressorchoose) set the quality value selected in the dialog box. [ICSeqCompressFrameStart](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-icseqcompressframestart) uses the value of this member as its quality setting.

### `lKeyCount`

Reserved; do not use.

### `lpState`

Reserved; do not use.

### `cbState`

Reserved; do not use.

## Remarks

You can let [ICCompressorChoose](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-iccompressorchoose) fill the contents of this structure or you can do it manually. If you manually fill the structure, you must provide information for the following members: **cbSize**, **hic**, **lpbiOut**, **lKey**, and **lQ**. Also, you must set the **ICMF_COMPVARS_VALID** flag in the **dwFlags** member.

## See also

[ICCompressorChoose](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-iccompressorchoose)

[ICCompressorFree](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-iccompressorfree)

[ICSeqCompressFrame](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-icseqcompressframe)

[ICSeqCompressFrameStart](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-icseqcompressframestart)

Video Compression Manager

[Video Compression Structures](https://learn.microsoft.com/windows/desktop/Multimedia/video-compression-structures)