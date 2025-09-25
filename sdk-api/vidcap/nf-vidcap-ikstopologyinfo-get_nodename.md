# IKsTopologyInfo::get_NodeName

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `get_NodeName` method returns the name of the node.

## Parameters

### `dwNodeId` [in]

Index of the node. To find the number of nodes, call the [IKsTopologyInfo::get_NumNodes](https://learn.microsoft.com/windows/desktop/api/vidcap/nf-vidcap-ikstopologyinfo-get_numnodes) method.

### `pwchNodeName` [out]

Pointer to a wide-character array that receives the name. To find the required buffer size, set this parameter to **NULL**. The size is returned in the *pdwNameLen* parameter.

### `dwBufSize` [in]

Size of the *pwchNodeName* array, in bytes.

### `pdwNameLen` [out]

Receives the buffer size required to hold the name, in bytes. This parameter cannot be **NULL**.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **WIN32_FROM_HRESULT(ERROR_MORE_DATA)** | The buffer is not large enough. |

## Remarks

To find the buffer size for the name, call the method once with **NULL** for the *pwchNodeName* parameter and zero for the *dwBufSize* parameter. The method returns the buffer size in *pdwNameLen*. The method's return value, in this case, is HRESULT_FROM_WIN32(ERROR_MORE_DATA). Then allocate the array and call the method again.

#### Examples

```cpp

// pKsTopo is an IKsTopologyInfo pointer.
// iNode is the index of a node.
DWORD cbName = 0;
hr = pKsTopo->get_NodeName(iNode, NULL, 0, &cbName);
if (hr == HRESULT_FROM_WIN32(ERROR_MORE_DATA))
{
    if (cbName > sizeof(WCHAR))
    {
        WCHAR *nodeName = new WCHAR[cbName / sizeof(WCHAR)];
        if (nodeName == NULL)
        {
            hr = E_OUTOFMEMORY;
        }
        else
        {
            hr = pKsTopo->get_NodeName(iNode, nodeName, cbName, &cbName);
            /* ... */
            delete [] nodeName;
        }
    }
}

```

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IKsTopologyInfo Interface](https://learn.microsoft.com/previous-versions/ms785846(v=vs.85))