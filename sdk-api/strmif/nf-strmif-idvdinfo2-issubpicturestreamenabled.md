# IDvdInfo2::IsSubpictureStreamEnabled

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `IsSubpictureStreamEnabled` method determines if the specified subpicture stream is enabled in the current title.

## Parameters

### `ulStreamNum` [in]

Subpicture stream number to test.

### `pbEnabled` [out]

Pointer to a variable of type BOOL that receives a value of **TRUE** if the audio stream is enabled, or **FALSE** otherwise.

## Return value

Returns one of the following **HRESULT** values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | Invalid argument. |
| **E_UNEXPECTED** | The [DVD Navigator](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-navigator-filter) is not initialized. |

## Remarks

A DVD can have up to 32 separate subpicture streams, although typically not all the streams will be enabled for each title. Use `IsSubpictureStreamEnabled` to determine whether a particular stream is enabled for the current title, and then call [IDvdControl2::SelectSubpictureStream](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol2-selectsubpicturestream) to select one of the enabled streams.

## See also

[DVD Applications](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-applications)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDvdInfo2 Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdinfo2)