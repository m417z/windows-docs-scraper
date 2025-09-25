# IConfigAsfWriter::ConfigureFilterUsingProfile

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `ConfigureFilterUsingProfile` method sets an ASF profile on the [WM ASF Writer](https://learn.microsoft.com/windows/desktop/DirectShow/wm-asf-writer-filter) filter. This method is the recommended way to set a profile on the WM ASF Writer filter.

## Parameters

### `pProfile` [in]

Pointer to the [IWMProfile](https://learn.microsoft.com/windows/desktop/wmformat/iwmprofile) interface of the profile.

## Return value

Returns one of the following **HRESULT** values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **VFW_E_WRONG_STATE** | The graph is stopped. |
| **E_POINTER** | The [IWMProfile](https://learn.microsoft.com/windows/desktop/wmformat/iwmprofile) interface pointer is invalid. |

## Remarks

The [IWMProfile](https://learn.microsoft.com/windows/desktop/wmformat/iwmprofile) interface is documented in the Windows Media Format SDK.

If successful, this method will cause an [EC_GRAPH_CHANGED](https://learn.microsoft.com/windows/desktop/DirectShow/ec-graph-changed) event to be sent to the application.

## See also

[Creating ASF Files in DirectShow](https://learn.microsoft.com/windows/desktop/DirectShow/creating-asf-files-in-directshow)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IConfigAsfWriter Interface](https://learn.microsoft.com/windows/desktop/api/dshowasf/nn-dshowasf-iconfigasfwriter)