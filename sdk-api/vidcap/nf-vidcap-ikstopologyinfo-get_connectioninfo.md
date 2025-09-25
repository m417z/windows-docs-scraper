# IKsTopologyInfo::get_ConnectionInfo

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `get_ConnectionInfo` method returns information about one node connection in the filter.

## Parameters

### `dwIndex` [in]

Index of the connection. To find the number of connections, call the [IKsTopologyInfo::get_NumConnections](https://learn.microsoft.com/windows/desktop/api/vidcap/nf-vidcap-ikstopologyinfo-get_numconnections) method.

### `pConnectionInfo` [out]

Pointer to a [KSTOPOLOGY_CONNECTION](https://learn.microsoft.com/windows/desktop/DirectShow/kstopology-connection) structure allocated by the caller. The method fills in this structure with the connection information.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IKsTopologyInfo Interface](https://learn.microsoft.com/previous-versions/ms785846(v=vs.85))