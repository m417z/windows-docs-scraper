# IAMVideoAccelerator::GetBuffer

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetBuffer** method gets a pointer to a compressed or uncompressed surface that was allocated for DirectX Video Acceleration (DXVA) decoding.

## Parameters

### `dwTypeIndex` [in]

Specifies the surface type:

* To get a pointer to a compressed surface, specify one of the DXVA surface types defined in dxva.h.
* To get a pointer to an uncompressed output surface, set this parameter to 0xFFFFFFFF.

The value 0xFFFFFFFF is valid only between calls to [IAMVideoAccelerator::BeginFrame](https://learn.microsoft.com/windows/desktop/api/videoacc/nf-videoacc-iamvideoaccelerator-beginframe) and [IAMVideoAccelerator::EndFrame](https://learn.microsoft.com/windows/desktop/api/videoacc/nf-videoacc-iamvideoaccelerator-endframe).

### `dwBufferIndex` [in]

The zero-based index of the surface, within the pool of surfaces that were allocated for the specified surface type.

* Compressed surfaces: To get the number of allocated surfaces for each surface type, call [IAMVideoAccelerator::GetInternalCompBufferInfo](https://learn.microsoft.com/windows/desktop/api/videoacc/nf-videoacc-iamvideoaccelerator-getinternalcompbufferinfo).
* Uncompressed surfaces: The buffer index must equal the **dwDestSurfaceIndex** member of the [AMVABeginFrameInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/amva/ns-amva-amvabeginframeinfo) structure that was passed to the most recent [IAMVideoAccelerator::BeginFrame](https://learn.microsoft.com/windows/desktop/api/videoacc/nf-videoacc-iamvideoaccelerator-beginframe) call.

### `bReadOnly` [in]

Specifies whether the decoder will write to the surface memory. For read-only access, specify **TRUE**. This might allow faster access to reference frames that are currently in use.

### `ppBuffer` [out]

Receives a pointer to the surface memory. To get the size of the buffer in bytes, call the [IAMVideoAccelerator::GetInternalCompBufferInfo](https://learn.microsoft.com/windows/desktop/api/videoacc/nf-videoacc-iamvideoaccelerator-getinternalcompbufferinfo) method. The size is given in the **dwBytesToAllocate** member of the [AMVACompBufferInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/amva/ns-amva-amvacompbufferinfo) structure that corresponds to *dwTypeIndex*.

### `lpStride` [out]

Receives the surface stride, in bytes.

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

If the filter's pins are not connected, the method returns **VFW_E_NOT_CONNECTED**.

This method locks and obtains access to a single buffer. Buffers are identified by type and by index within that type. The [IAMVideoAccelerator::GetInternalCompBufferInfo](https://learn.microsoft.com/windows/desktop/api/videoacc/nf-videoacc-iamvideoaccelerator-getinternalcompbufferinfo) method returns the number of surface types in its *pdwNumTypesCompBuffers* parameter. This number defines the valid range for *dwTypeIndex*. For each type, the **dwNumCompBuffers** member of the [AMVACompBufferInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/amva/ns-amva-amvacompbufferinfo) structure gives the number of buffers, which defines the valid range for *dwBufferIndex*.

To release the buffer, call [IAMVideoAccelerator::ReleaseBuffer](https://learn.microsoft.com/windows/desktop/api/videoacc/nf-videoacc-iamvideoaccelerator-releasebuffer).

Until all compressed buffers are released, it is possible that the calling thread will hold the Win16 lock or the DirectDraw lock.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[How Decoders Use IAMVideoAccelerator](https://learn.microsoft.com/windows/desktop/DirectShow/how-decoders-use-iamvideoaccelerator)

[IAMVideoAccelerator Interface](https://learn.microsoft.com/windows/desktop/api/videoacc/nn-videoacc-iamvideoaccelerator)