# IWMPSubscriptionService::allowCDBurn

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This section describes functionality designed for use by online stores. Use of this functionality outside the context of an online store is not supported.

The **allowCDBurn** method is implemented by the online store's plug-in to manage permission for Windows Media Player to copy content to a CD.

## Parameters

### `hwnd` [in]

A handle to a window in which the plug-in can display a user interface.

### `pPlaylist` [in, out]

Pointer to a playlist object. The plug-in must remove from the playlist any media item that does not have a current license that includes burn rights.

### `pfAllowBurn` [out]

Pointer to a **BOOL**. If true, copying to CD is allowed for the media items that remain in the playlist.

## Return value

The method returns an **HRESULT**.

## Remarks

The situations in which Windows Media Player calls **allowCDBurn** differ between versions of Windows Media Player.

Windows Media Player 9 Series and Windows Media Player 10 call **allowCDBurn** automatically when the user attempts to burn a list of media items to a CD, and the Player passes the entire list in the *pPlaylist* parameter. The **allowCDBurn** method removes from the playlist any media items that do not have a current license. Then the **allowCDBurn** method can initiate license renewal, on a background thread, for media items that do not have current licenses. The **allowCDBurn** method must not wait for the background thread to complete the license renewal. Instead, it must return as soon as it has initiated the renewal.

Windows Media Player 11 never calls **allowCDBurn** automatically. That is, Windows Media Player 11 calls **allowCDBurn** only when the user explicitly requests burn rights. When the user attempts to burn a list of media items to a CD, Windows Media Player checks to see whether those items have current licenses that include burn rights. For each item that does not have a current license, the Player displays an information icon, which has a context menu. The context menu lets the user request burn rights for the individual media item or for all media items in the basket from the same online store that do not already have burn rights. If the user requests burn rights by choosing a command from the context menu, the Player calls **allowCDBurn**, passing a playlist that contains the media items for which the user is requesting rights. The **allowCDBurn** method can then initiate license renewal on a background thread. The **allowCDBurn** method must not wait for the background thread to complete the license renewal. Instead, it must return as soon as it has initiated the renewal.

Note that Windows Media Player 11 ignores the playlist and the Boolean value that **allowCDBurn** returns in the *pPlaylist* and *pfAllowBurn* parameters. Also note that because of the way Windows Media Player 11 handles burn rights, you must not rely on **allowCDBurn** being called each time a track is burned to a CD.

Regardless of the Player version, there is no callback mechanism that the background thread can use to notify Windows Media Player that a license renewal is complete. However, if the license renewal for a media item succeeds, then the next time the user attempts to copy the item to a CD, the copy will succeed.

## See also

[IWMPSubscriptionService Interface](https://learn.microsoft.com/windows/desktop/api/subscriptionservices/nn-subscriptionservices-iwmpsubscriptionservice)