# IAMVideoAccelerator::QueryRenderStatus

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **QueryRenderStatus** method queries the read/write status of a DirectX Video Acceleration (DXVA) decoding surface.

## Parameters

### `dwTypeIndex` [in]

Specifies the type of surface to query:

* For a compressed surface, specify one of the DXVA surface types defined in dxva.h.
* For an uncompressed output surface, set this parameter to 0xFFFFFFFF.

### `dwBufferIndex` [in]

The zero-based index of the surface, within the pool of surfaces that were allocated for the specified surface type.

### `dwFlags` [in]

Specifies the type of query to perform.

| Value | Meaning |
| --- | --- |
| **Zero** | Test whether the surface is safe to use for writing. |
| ****AMVA_QUERYRENDERSTATUSF_READ**** | Test whether the surface is safe to use for reading. |

## Return value

Returns an **HRESULT** value. Possible values include the following:

| Return code | Description |
| --- | --- |
| **E_PENDING** | The operation is still in progress. |
| **S_OK** | The operation is complete. |
| **VFW_E_INVALIDSUBTYPE** | The decoder did not use a DXVA decoding type when it connected to the video renderer. |
| **VFW_E_NOT_CONNECTED** | The pins on the decoder and video renderer filters are not connected. |

## Remarks

If the filter's pins are not connected, the method returns **VFW_E_NOT_CONNECTED**.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[How Decoders Use IAMVideoAccelerator](https://learn.microsoft.com/windows/desktop/DirectShow/how-decoders-use-iamvideoaccelerator)

[IAMVideoAccelerator Interface](https://learn.microsoft.com/windows/desktop/api/videoacc/nn-videoacc-iamvideoaccelerator)