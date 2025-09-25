# IWMPMedia::get_duration

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **get_duration** method retrieves the duration in seconds of the current media item..

## Parameters

### `pDuration` [out]

Pointer to a **double** containing the duration.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

If this method is used with a media item other than the one specified in **IWMPCore::get_currentMedia**, it may not contain a valid value.

To retrieve the duration for files that are not in the user's library, you must wait for Windows Media Player to open the file; that is, the current OpenState must equal MediaOpen. You can verify this by handling the **IWMPEvents::OpenStateChange** event or by periodically checking the value of **IWMPCore::get_openState**.

For playlists, the duration of each media item can be retrieved when the individual media item is opened, rather than the when the playlist is opened.

Before calling this method, you must have read access to the library. For more information, see [Library Access](https://learn.microsoft.com/windows/desktop/WMP/library-access).

## See also

[IWMPCore::get_currentMedia](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcore-get_currentmedia)

[IWMPCore::get_openState](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcore-get_openstate)

[IWMPEvents::OpenStateChange](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpevents-openstatechange)

[IWMPMedia Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpmedia)

[IWMPMedia::get_durationString](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpmedia-get_durationstring)