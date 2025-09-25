# IAMExtTransport::put_EditStart

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `put_EditStart` method activates the edit control on a capable transport.

This method is not implemented.

## Parameters

### `Value` [in]

Specifies whether to active the edit control.

| Value | Description |
| --- | --- |
| OATRUE | Activates the edit control. |
| OAFALSE | Deactivates the edit control. |

## Return value

When this method succeeds, it returns S_OK. Otherwise it returns an **HRESULT** error code.

## Remarks

Use this method to manually enable edit control. Edit control is defined as the precise enabling of individual, or a set of, record tracks on a VCR; for example, a video-only insert edit, where only the video record head is enabled and a new video signal is recorded—the audio signal is left as is. Use this method to control "on the fly" editing on machines that have this feature.

### DV Implementation

[MSDV](https://learn.microsoft.com/windows/desktop/DirectShow/msdv-driver) does not support this method. It returns E_NOTIMPL.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMExtTransport Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamexttransport)

[IAMExtTransport::get_EditStart](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamexttransport-get_editstart)