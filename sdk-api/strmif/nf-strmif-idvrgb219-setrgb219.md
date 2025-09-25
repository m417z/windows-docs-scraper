# IDVRGB219::SetRGB219

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetRGB219` method controls the dynamic range for DV encoding and decoding.

The DV video format has a dynamic range of 16–235. By default, when the DV Video Decoder decodes to 24-bit or 32-bit RGB, it stretches the color range to 0–255. Similarly, the DV Video Encoder compresses 24-bit RGB into the 16-235 range. In RGB-219 mode, the decoder does not stretch the color range, and the encoder does not compress the color range. Use the `SetRGB219` method to toggle between the default mode and RGB-219 mode.

## Parameters

### `bState` [in]

Boolean value that specifies the filter's encoding or decoder behavior.

| Value | Description |
| --- | --- |
| **TRUE** | Enable RGB-219 mode. |
| **FALSE** | Disable RGB-219 mode. Use the default mode. |

## Return value

Returns S_OK if successful. Otherwise, returns an **HRESULT** failure code.

## Remarks

For the encoder, this method has no effect unless the input type is RGB-24. For the decoder, it has no effect unless the output type is RGB-24 or RGB-32.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDVRGB219 Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvrgb219)