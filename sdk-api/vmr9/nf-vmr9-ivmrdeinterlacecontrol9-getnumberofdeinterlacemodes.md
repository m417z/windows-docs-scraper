# IVMRDeinterlaceControl9::GetNumberOfDeinterlaceModes

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetNumberOfDeinterlaceModes** method retrieves the deinterlacing modes available to the VMR for the specified video format.

## Parameters

### `lpVideoDescription` [in]

Pointer to a [VMR9VideoDesc](https://learn.microsoft.com/previous-versions/windows/desktop/api/vmr9/ns-vmr9-vmr9videodesc) structure that describes the video.

### `lpdwNumDeinterlaceModes` [in, out]

Pointer to a **DWORD** value. On input, this value specifies the size of the array given in *lpDeinterlaceModes*. On output, it receives number of GUIDs the method copied into the array.

### `lpDeinterlaceModes` [out]

Address of an array allocated by caller. The method fills the array with GUID values. To determine the size of the array that is needed, set this parameter to **NULL** and check the value returned in *lpdwNumDeinterlaceModes*.

## Return value

Returns an **HRESULT** value. Possible values include the following:

| Return code | Description |
| --- | --- |
| **E_POINTER** | **NULL** pointer argument. |
| **S_OK** | Success |
| **VFW_E_VMR_NOT_IN_MIXER_MODE** | The VMR is not in mixer mode. |
| **VFW_E_DDRAW_CAPS_NOT_SUITABLE** | The video card does not support hardware deinterlacing. |

## Remarks

This method returns an array of GUIDs, where each GUID represents a deinterlacing mode that is supported in hardware by the graphics device driver. The array is sorted by quality, so the first entry represents the best quality, the second entry represents the next best quality, and so forth.

All drivers are required to support the following mode:

| **GUID** | Description |
| --- | --- |
| DXVA_DeinterlaceBobDevice | Bob mode |

Drivers can support additional modes and should define their own GUIDs to identify them. For each returned mode, call the [IVMRDeinterlaceControl9::GetDeinterlaceModeCaps](https://learn.microsoft.com/windows/desktop/api/vmr9/nf-vmr9-ivmrdeinterlacecontrol9-getdeinterlacemodecaps) method to get information about that mode.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IVMRDeinterlaceControl9 Interface](https://learn.microsoft.com/windows/desktop/api/vmr9/nn-vmr9-ivmrdeinterlacecontrol9)

[Setting Deinterlace Preferences](https://learn.microsoft.com/windows/desktop/DirectShow/setting-deinterlace-preferences)

[Using the Video Mixing Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/using-the-video-mixing-renderer)

[Video Mixing Renderer Filter 9](https://learn.microsoft.com/windows/desktop/DirectShow/video-mixing-renderer-filter-9)