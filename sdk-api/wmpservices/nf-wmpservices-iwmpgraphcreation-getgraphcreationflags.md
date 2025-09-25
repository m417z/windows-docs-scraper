# IWMPGraphCreation::GetGraphCreationFlags

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

One of the flags documented on this page is available in Windows Media Player 10 and Windows Media Player 11 running on Microsoft Windows XP. It might not be available in subsequent versions.

The **GetGraphCreationFlags** method is called by Windows Media Player to retrieve a value that represents the graph creation preferences.

## Parameters

### `pdwFlags` [out]

Address of a **DWORD** variable that receives a value that represents one or more graph creation flags combined by using bitwise OR operations.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Value | Description |
| --- | --- |
| S_OK | The method succeeded. |

## Remarks

The following table describes the graph creation flags.

| Flag | Value | Description |
| --- | --- | --- |
| WMPGC_FLAGS_ALLOW_PREROLL | 0x1 | Windows Media Player will build the filter graph for the next media item before the current media item finishes playing. |
| WMPGC_FLAGS_SUPPRESS_DIALOGS | 0x2 | Windows Media Player will not display warning dialog boxes when errors occur. |
| WMPGC_FLAGS_IGNORE_AV_SYNC | 0x4 | Windows Media Player will not require audio and video to be synchronized when playing Windows Media-based content (.asf, .wma, or .wmv). Windows Media Player will attempt to play every frame of video. This occurs even when video data is arriving more slowly than audio data.<br><br>**Note** This flag is supported only in Windows Media Player 10 or 11 running on Microsoft Windows XP. |
| WMPGC_FLAGS_DISABLE_PLUGINS | 0x8 | Disables all plug-ins for the current instance of the Windows Media Player control. This includes plug-ins native to Windows Media Player. For example, visualizations will not work when this flag is set. |
| WMPGC_FLAGS_USE_CUSTOM_GRAPH | 0x10 | Windows Media Player will use the application-provided DirectShow graph as-is and not attempt to further render the originally requested URL or file. Plug-ins will still be added to the custom graph unless the **WMPGC_FLAGS_DISABLE_PLUGINS** flag is also set. Set both these flags if you want WMP to use the provided graph without any changes. Requires Windows Media Player 12. |

**Windows Media Player 10 Mobile:** This method is not supported.

## See also

[IWMPGraphCreation Interface](https://learn.microsoft.com/windows/desktop/api/wmpservices/nn-wmpservices-iwmpgraphcreation)