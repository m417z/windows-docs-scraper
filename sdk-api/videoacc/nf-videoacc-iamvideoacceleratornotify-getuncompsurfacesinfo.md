# IAMVideoAcceleratorNotify::GetUncompSurfacesInfo

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetUncompSurfacesInfo** method queries the decoder for the number of uncompressed surfaces to allocate and the pixel format.

## Parameters

### `pGuid` [in]

Pointer to a GUID that specifies the DXVA profile in use.

### `pUncompBufferInfo` [in, out]

Pointer to a [AMVAUncompBufferInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/amva/ns-amva-amvauncompbufferinfo) structure. The decoder fills in this structure with the decoder's requirements for the minimum and maximum number of surfaces and the pixel format.

To get the list of supported pixel formats, the decoder should call [IAMVideoAccelerator::GetUncompFormatsSupported](https://learn.microsoft.com/windows/desktop/api/videoacc/nf-videoacc-iamvideoaccelerator-getuncompformatssupported).

## Return value

Returns an **HRESULT** value that depends on the implementation of the interface. **HRESULT** can include one of the following standard constants, or other values not listed.

| Return code | Description |
| --- | --- |
| **E_FAIL** | Failure. |
| **E_INVALIDARG** | Argument is invalid. |
| **E_NOTIMPL** | Method is not supported. |
| **E_POINTER** | **NULL** pointer argument. |
| **S_OK** | Success. |

## Remarks

After the video renderer allocates the uncompressed surfaces, it calls the decoder's [IAMVideoAcceleratorNotify::SetUncompSurfacesInfo](https://learn.microsoft.com/windows/desktop/api/videoacc/nf-videoacc-iamvideoacceleratornotify-setuncompsurfacesinfo) method.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[How Decoders Use IAMVideoAccelerator](https://learn.microsoft.com/windows/desktop/DirectShow/how-decoders-use-iamvideoaccelerator)

[IAMVideoAcceleratorNotify Interface](https://learn.microsoft.com/windows/desktop/api/videoacc/nn-videoacc-iamvideoacceleratornotify)