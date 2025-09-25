# IAMVideoAccelerator::GetInternalCompBufferInfo

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetInternalCompBufferInfo** method gets information about the compressed buffers used for DirectX Video Acceleration (DXVA) decoding.

Call this method after the decoder has connected to the video renderer's input pin. During the pin connection process, use the [IAMVideoAccelerator::GetCompBufferInfo](https://learn.microsoft.com/windows/desktop/api/videoacc/nf-videoacc-iamvideoaccelerator-getcompbufferinfo) method instead.

## Parameters

### `pdwNumTypesCompBuffers` [in, out]

On input, specifies the number of elements in the *pamvaCompBufferInfo* array.
If *pamvaCompBufferInfo* is **NULL**, the value of `*pdwNumTypesCompBuffers` must be zero.

On output, if *pamvaCompBufferInfo* is **NULL**, *pdwNumTypesCompBuffers* receives the size of array to allocate. Otherwise, *pdwNumTypesCompBuffers* receives the actual number of elements copied to the *pamvaCompBufferInfo* array.

### `pamvaCompBufferInfo` [out]

Address of an array of [AMVACompBufferInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/amva/ns-amva-amvacompbufferinfo) structures, or **NULL**. If the value is non-**NULL**, the method copies a list of **AMVACompBufferInfo** structures to this array. Each structure corresponds to one type of compressed data buffer used by the video accelerator.

Set all of the array elements to zero before calling this method.

Each array index corresponds to one of the DXVA surface types defined in dxva.h. The video accelerator will return a list of up to **DXVA_NUM_TYPES_COMP_BUFFERS** array entries. For details, refer to the [DXVA 1.0 specification](https://learn.microsoft.com/windows-hardware/drivers/display/directx-video-acceleration), section 3.4, "Buffer Description List." If a particular buffer type is not used by the DXVA profile in question, the entry at that index contains zeroes for all values.

## Return value

Returns an **HRESULT** value that depends on the implementation of the interface. **HRESULT** can include one of the following standard constants, or other values not listed.

| Return code | Description |
| --- | --- |
| **E_FAIL** | Failure. |
| **E_INVALIDARG** | Argument is invalid. |
| **E_NOTIMPL** | Method is not supported. |
| **E_POINTER** | **NULL** pointer argument. |
| **S_OK** | Success. |
| **VFW_E_INVALIDSUBTYPE** | The decoder did not use a DXVA decoding type when it connected to the video renderer. |
| **VFW_E_NOT_CONNECTED** | The pins on the decoder and video renderer filters are not connected. |

## Remarks

The [AMVACompBufferInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/amva/ns-amva-amvacompbufferinfo) structure contains information that is needed for the [IAMVideoAccelerator::GetBuffer](https://learn.microsoft.com/windows/desktop/api/videoacc/nf-videoacc-iamvideoaccelerator-getbuffer) method.

## See also

[AMVACompBufferInfo Structure](https://learn.microsoft.com/previous-versions/windows/desktop/api/amva/ns-amva-amvacompbufferinfo)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[How Decoders Use IAMVideoAccelerator](https://learn.microsoft.com/windows/desktop/DirectShow/how-decoders-use-iamvideoaccelerator)

[IAMVideoAccelerator Interface](https://learn.microsoft.com/windows/desktop/api/videoacc/nn-videoacc-iamvideoaccelerator)