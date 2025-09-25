# IWMPControls::get_currentItem

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **get_currentItem** method retrieves the current media item in a playlist.

## Parameters

### `ppIWMPMedia` [out]

Pointer to a pointer to an **IWMPMedia** interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method works only with items in the current playlist.

## See also

[IWMPControls Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpcontrols)

[IWMPControls::put_currentItem](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcontrols-put_currentitem)

[IWMPMedia Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpmedia)

[IWMPPlaylistCollection::getByName](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpplaylistcollection-getbyname)