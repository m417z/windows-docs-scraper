# IVMRDeinterlaceControl9::SetDeinterlaceMode

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetDeinterlaceMode** method sets the deinterlacing mode for the specified video stream.

## Parameters

### `dwStreamID` [in]

Index of the video stream to set. To set all streams, use the value 0xFFFFFFFF.

### `lpDeinterlaceMode` [in]

Pointer to a GUID that specifies the deinterlacing mode. To turn off deinterlacing, use the value GUID_NULL.

## Return value

Returns an **HRESULT** value. Possible values include the following:

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid stream number. |
| **E_POINTER** | **NULL** pointer argument. |
| **S_OK** | Success. |
| **VFW_E_VMR_NOT_IN_MIXER_MODE** | The VMR is not in mixer mode. |

## Remarks

If the application does not specify the mode, the VMR defaults to the first mode reported by the driver. In either case, if the VMR cannot use the preferred mode, it falls back to another mode as specified in the [IVMRDeinterlaceControl9::SetDeinterlacePrefs](https://learn.microsoft.com/windows/desktop/api/vmr9/nf-vmr9-ivmrdeinterlacecontrol9-setdeinterlaceprefs) method.

The **SetDeinterlaceMode** method is effective only for new connections made to the VMR. Some deinterlacing mode require that additional reference samples be available; the exact number depends on the mode. The VMR allocates surfaces for these additional samples. The client must set the deinterlace mode before the surfaces have been allocated. Surface allocation occurs after any of the following:

* Pin connections, including dynamic reconnections
* Dynamic format changes (the upstream filter calls [IPin::ReceiveConnection](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ipin-receiveconnection) to specify a new format)
* Resolution changes
* Monitor changes

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IVMRDeinterlaceControl9 Interface](https://learn.microsoft.com/windows/desktop/api/vmr9/nn-vmr9-ivmrdeinterlacecontrol9)

[Setting Deinterlace Preferences](https://learn.microsoft.com/windows/desktop/DirectShow/setting-deinterlace-preferences)

[Using the Video Mixing Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/using-the-video-mixing-renderer)

[Video Mixing Renderer Filter 9](https://learn.microsoft.com/windows/desktop/DirectShow/video-mixing-renderer-filter-9)