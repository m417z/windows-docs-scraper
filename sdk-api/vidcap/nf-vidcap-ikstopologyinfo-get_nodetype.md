# IKsTopologyInfo::get_NodeType

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `get_NodeType` method returns the node type for a given node.

## Parameters

### `dwNodeId` [in]

Index of the node. To find the number of nodes, call the [IKsTopologyInfo::get_NumNodes](https://learn.microsoft.com/windows/desktop/api/vidcap/nf-vidcap-ikstopologyinfo-get_numnodes) method.

### `pNodeType` [out]

Receives a GUID that defines the node type. For a list of node types, see [KS Node Types](https://learn.microsoft.com/windows/desktop/DirectShow/ks-node-types).

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IKsTopologyInfo Interface](https://learn.microsoft.com/previous-versions/ms785846(v=vs.85))