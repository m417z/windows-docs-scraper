# IGraphConfigCallback::Reconfigure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `Reconfigure` method is a callback method passed to [IGraphConfig::Reconfigure](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-igraphconfig-reconfigure).

## Parameters

### `pvContext`

Value passed in the **IGraphConfig::Reconfigure** method's *pvContext* parameter.

### `dwFlags`

Value passed in the **IGraphConfig::Reconfigure** method's *dwFlags* parameter.

## Return value

Returns S_OK if successful. Otherwise, returns an **HRESULT** value indicating the cause of the error.

## Remarks

If your application or filter calls **IGraphConfig::Reconfigure**, you must implement this method and pass it as a callback. The **IGraphConfig::Reconfigure** method obtains a lock on the filter graph before calling your `Reconfigure` method. Your method then handles all the other details of dynamic graph building.

If this method succeeds, **IGraphConfig::Reconfigure** tries to put all the filters in the graph back into a running state. If the method fails, **IGraphConfig::Reconfigure** returns whatever error code this method returned.

This method allows for specialized graph rebuilding. For a more straightforward approach to dynamic graph building, see [IGraphConfig::Reconnect](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-igraphconfig-reconnect).

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IGraphConfigCallback Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-igraphconfigcallback)