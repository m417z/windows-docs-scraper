# DVINFO structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **DVINFO** structure describes the format of a digital video (DV) stream.

## Members

### `dwDVAAuxSrc`

Specifies the audio auxiliary (AAUX) source pack for the first audio block.

### `dwDVAAuxCtl`

Specifies the AAUX source control Pack for the first audio block.

### `dwDVAAuxSrc1`

Specifies the AAUX source pack for the second audio block.

### `dwDVAAuxCtl1`

Specifies the AAUX source control pack for the second audio block.

### `dwDVVAuxSrc`

Specifies the video auxiliary (VAUX) source pack.

### `dwDVVAuxCtl`

Specifies the VAUX source control pack.

### `dwDVReserved`

Reserved. Set this array to zero.

## Remarks

The AAUX and VAUX packs are defined in IEC 61834-4.

## See also

[DV Data in the AVI File Format](https://learn.microsoft.com/windows/desktop/DirectShow/dv-data-in-the-avi-file-format)

[DVINFO Field Settings in the MSDV Driver](https://learn.microsoft.com/windows/desktop/DirectShow/dvinfo-field-settings-in-the-msdv-driver)

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)