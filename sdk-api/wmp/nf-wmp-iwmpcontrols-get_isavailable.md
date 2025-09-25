# IWMPControls::get_isAvailable

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **get_isAvailable** method indicates whether a specified type of information is available or a specified action can be performed.

## Parameters

### `bstrItem` [in]

**BSTR** containing one of the following values.

| Value | Description |
| --- | --- |
| currentItem | Determines whether the user can set the **IWMPControls::put_currentItem** method. |
| currentMarker | Determines whether the user can seek to a specific marker. |
| currentPosition | Determines whether the user can seek to a specific position in the file. Some files do not support seeking. |
| fastForward | Determines whether the file supports fast forwarding and whether that functionality can be invoked. Many file types (or live streams) do not support fastForward. |
| fastReverse | Determines whether the file supports fastReverse and whether that functionality can be invoked. Many file types (or live streams) do not support fastReverse. |
| next | Determines whether the user can seek to the next entry in a playlist. |
| pause | Determines whether the **IWMPControls::pause** method is available. |
| play | Determines whether the **IWMPControls::play** method is available. |
| previous | Determines whether the user can seek to the previous entry in a playlist. |
| step | Determines whether the **IWMPControls2::step** method is available during playback. |
| stop | Determines whether the **IWMPControls::stop** method is available. |

### `pIsAvailable` [out]

Pointer to a **VARIANT_BOOL** indicating whether a specified type of information is available or a specified action can be performed.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IWMPControls Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpcontrols)

[IWMPControls2::step](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcontrols2-step)

[IWMPControls::pause](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcontrols-pause)

[IWMPControls::play](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcontrols-play)

[IWMPControls::put_currentItem](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcontrols-put_currentitem)

[IWMPControls::stop](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcontrols-stop)