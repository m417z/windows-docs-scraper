# IAMVideoAccelerator::Execute

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **Execute** method performs a DirectX Video Acceleration (DXVA) decoding operation.

## Parameters

### `dwFunction` [in]

Contains one or more
DXVA function numbers.

### `lpPrivateInputData` [in]

Pointer to input data for the decoding operation. The meaning of this data depends on the surface type and function number. For details, refer to the DXVA 1.0 specification.

### `cbPrivateInputData` [in]

Size of the input data, in bytes.

### `lpPrivateOutputDat` [in]

Pointer to a buffer where the video accelerator will write output data.

### `cbPrivateOutputData` [in]

Size of the *lpPrivateOutputData* buffer, in bytes.

### `dwNumBuffers` [in]

Number of elements in the *pamvaBufferInfo* array.

### `pamvaBufferInfo` [in]

Pointer to an array of [AMVABUFFERINFO](https://learn.microsoft.com/previous-versions/windows/desktop/api/amva/ns-amva-amvabufferinfo) structures.

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

The associated buffer list is passed along with a function number (defaulting to zero) and any necessary private data describing the decompression operation. For example, decompressed reference frame information is passed in the buffer list. The buffer list order is important and is defined by the particular decompression operation being performed.

Private data can be passed to and from a driver.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[How Decoders Use IAMVideoAccelerator](https://learn.microsoft.com/windows/desktop/DirectShow/how-decoders-use-iamvideoaccelerator)

[IAMVideoAccelerator Interface](https://learn.microsoft.com/windows/desktop/api/videoacc/nn-videoacc-iamvideoaccelerator)