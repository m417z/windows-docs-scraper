# IVMRDeinterlaceControl9::GetActualDeinterlaceMode

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetActualDeinterlaceMode** method returns the deinterlacing mode that the VMR is using for a specified stream.

## Parameters

### `dwStreamID` [in]

Index of the video stream.

### `lpDeinterlaceMode` [out]

Pointer to a variable that receives a GUID value that identifies the deinterlacing mode. The method returns GUID_NULL if the VMR has not initialized the deinterlacing hardware, or if the VMR determines that this stream should not be deinterlaced.

## Return value

Returns an **HRESULT** value. Possible values include the following:

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid stream number. |
| **E_POINTER** | **NULL** pointer argument. |
| **S_OK** | Success. |
| **VFW_E_VMR_NOT_IN_MIXER_MODE** | The VMR is not in mixer mode. |

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IVMRDeinterlaceControl9 Interface](https://learn.microsoft.com/windows/desktop/api/vmr9/nn-vmr9-ivmrdeinterlacecontrol9)

[Setting Deinterlace Preferences](https://learn.microsoft.com/windows/desktop/DirectShow/setting-deinterlace-preferences)

[Using the Video Mixing Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/using-the-video-mixing-renderer)

[Video Mixing Renderer Filter 9](https://learn.microsoft.com/windows/desktop/DirectShow/video-mixing-renderer-filter-9)