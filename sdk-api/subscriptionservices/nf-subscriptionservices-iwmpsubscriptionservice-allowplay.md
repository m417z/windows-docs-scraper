# IWMPSubscriptionService::allowPlay

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This section describes functionality designed for use by online stores. Use of this functionality outside the context of an online store is not supported.

The **allowPlay** method is implemented by the online store's plug-in to manage permission for Windows Media Player to play content.

## Parameters

### `hwnd` [in]

A handle to a window in which the plug-in can display a user interface.

### `pMedia` [in]

Pointer to the media object Windows Media Player is attempting to play.

### `pfAllowPlay` [out]

Pointer to a **BOOL**. If **true**, playback is allowed.

## Return value

The method returns an **HRESULT**.

## Remarks

Your code should not perform lengthy operations synchronously when Windows Media Player calls this method. Instead, you must perform time-consuming tasks on a separate worker thread.

Windows Media Player calls **allowPlay** before opening the digital media file. This gives the online store an opportunity to disallow playback of licensed content or to initiate download of a new license if the license has expired.

Because the digital media file is not open when Windows Media Player calls **allowPlay**, calling certain methods on *pMedia* may not work. For instance, attempting to retrieve metadata using [IWMPMedia::getItemInfo](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpmedia-getiteminfo) could fail.

The **allowPlay** method does not circumvent DRM. If the method returns **TRUE** and the license to play has not been renewed, Windows Media Player will not play the content.

The **allowPlay** method is not called when streaming protected content for which the user does not have a license.

## See also

[IWMPSubscriptionService Interface](https://learn.microsoft.com/windows/desktop/api/subscriptionservices/nn-subscriptionservices-iwmpsubscriptionservice)