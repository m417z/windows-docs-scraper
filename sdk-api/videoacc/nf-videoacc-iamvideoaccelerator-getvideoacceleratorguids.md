# IAMVideoAccelerator::GetVideoAcceleratorGUIDs

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetVideoAcceleratorGUIDs** method gets a list of DirectX Video Acceleration (DXVA) profiles supported by the display driver.

## Parameters

### `pdwNumGuidsSupported` [in, out]

On input, specifies the number of elements in the *pGuidsSupported* array.
If *pGuidsSupported* is **NULL**, the value of `*pdwNumGuidsSupported` must be zero.

On output, if *pGuidsSupported* is **NULL**, *pdwNumGuidsSupported* receives the number of restricted-mode DXVA profiles. Otherwise, *pdwNumGuidsSupported* receives the actual number of GUIDs copied to the *pGuidsSupported* array.

### `pGuidsSupported` [in, out]

Address of an array of GUIDs, or **NULL**. If the value is non-**NULL**, the array receives a list of GUIDs that specify restricted-mode DXVA profiles. These GUIDs are defined in the header file dxva.h, and are documented in the [DXVA 1.0 specification](https://learn.microsoft.com/windows-hardware/drivers/display/directx-video-acceleration).

## Return value

Returns an **HRESULT** value that depends on the implementation of the interface. **HRESULT** can include one of the following standard constants, or other values not listed.

| Return code | Description |
| --- | --- |
| **E_FAIL** | Failure. |
| **E_INVALIDARG** | Argument is invalid. |
| **E_NOTIMPL** | The method is not supported. |
| **E_POINTER** | **NULL** pointer argument. |
| **S_OK** | Success. |
| **VFW_E_WRONG_STATE** | Invalid state. The video renderer has not created the Direct3D or DirectDraw device. |

## Remarks

Call this method twice. On the first call, set *pGuidsSupported* to **NULL**. The *pdwNumGuidsSupported* parameter receives the number of DXVA profile GUIDs. Allocate an array of GUIDs with the required size and call the method again. This time, set *pGuidsSupported* to the address of the array. The method fills the array with the list of DXVA profile GUIDs.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[How Decoders Use IAMVideoAccelerator](https://learn.microsoft.com/windows/desktop/DirectShow/how-decoders-use-iamvideoaccelerator)

[IAMVideoAccelerator Interface](https://learn.microsoft.com/windows/desktop/api/videoacc/nn-videoacc-iamvideoaccelerator)