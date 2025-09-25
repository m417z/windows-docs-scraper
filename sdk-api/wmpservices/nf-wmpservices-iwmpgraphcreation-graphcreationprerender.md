# IWMPGraphCreation::GraphCreationPreRender

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GraphCreationPreRender** method is called by Windows Media Player before a file is rendered.

## Parameters

### `pFilterGraph` [in]

Pointer to the **IUnknown** interface of the Windows Media Player control's DirectShow filter graph.

### `pReserved` [in]

Reserved for future use.

## Return value

Return a success **HRESULT** to allow playback to continue or a failure code to terminate playback.

## Remarks

You can call **QueryInterface** through *pFilterGraph* to retrieve the DirectShow filter graph interfaces you require.

There is no guarantee that this method will be invoked for all files. Only files rendered with DirectShow will cause this method to be invoked and the WMPGC_FLAGS_USE_CUSTOM_GRAPH flag to be honored. CD, DVD, Image, Flash, Windows Media Format SDK, and Media Foundation playback will not invoke this method.

**Windows Media Player 10 Mobile:** This method is not supported.

## See also

[IWMPGraphCreation Interface](https://learn.microsoft.com/windows/desktop/api/wmpservices/nn-wmpservices-iwmpgraphcreation)