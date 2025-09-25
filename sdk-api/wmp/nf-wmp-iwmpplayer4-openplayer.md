# IWMPPlayer4::openPlayer

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **openPlayer** method opens Windows Media Player using the specified URL.

## Parameters

### `bstrURL` [in]

**BSTR** containing the URL of the media item to play.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method launches Windows Media Player with the specified URL set as the current media item. If the Player was previously closed in skin mode it will open using the skin last chosen by the user. Otherwise, the Player opens in full mode.

If this method is called from a Windows Media Player ActiveX control embedded in remote mode, its behavior is identical to the **IWMPPlayerAppication::switchToPlayerApplication** method.

**Windows Media Player 10 Mobile:** This method always returns E_NOTIMPL.

## See also

[IWMPPlayer4 Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpplayer4)

[IWMPPlayerAppication::switchToPlayerApplication](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmp/nf-wmp-iwmpplayerapplication-switchtoplayerapplication)