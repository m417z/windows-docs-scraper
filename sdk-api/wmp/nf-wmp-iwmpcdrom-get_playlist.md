# IWMPCdrom::get_playlist

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **get_playlist** method retrieves a pointer to an **IWMPPlaylist** interface representing the tracks on the CD currently in the CD drive or the root-level title entries for a DVD.

## Parameters

### `ppPlaylist` [out]

Pointer to a pointer to an **IWMPPlaylist** interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Typically, DVD-based content organized into titles. Each title contains one or more chapters. Each DVD is authored differently, so how titles and chapters are used is up to the content author.

For a DVD, this method retrieves a playlist that contains as the first item a pointer to an **IWMPMedia** interface named "DVD". This interface represents the DVD media. Playing the item results in the DVD playing from the beginning if it is the first play after inserting a new DVD, or resuming playback if the DVD is the same as the last DVD viewed. Setting this item as the current item during playback results in the DVD playing from the beginning.

Additional items (**IWMPMedia** objects) in the playlist are DVD titles that are represented by nested playlists. When you specify a value for the **IWMPControls::put_currentItem** method to equal one of these nested playlist items, Windows Media Player automatically sets the nested playlist as the current playlist after chapter playback begins. You can then use the **IWMPPlaylist** interface methods and associated events to work with DVD chapters, which are also playlist items.

To retrieve the value of this property, read access to the library is required. For more information, see [Library Access](https://learn.microsoft.com/windows/desktop/WMP/library-access).

**Windows Media Player 10 Mobile:** This method is not supported.

## See also

[IWMPCdrom Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpcdrom)

[IWMPMedia Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpmedia)

[IWMPPlaylist Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpplaylist)

[IWMPSettings2::get_mediaAccessRights](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpsettings2-get_mediaaccessrights)

[IWMPSettings2::requestMediaAccessRights](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpsettings2-requestmediaaccessrights)