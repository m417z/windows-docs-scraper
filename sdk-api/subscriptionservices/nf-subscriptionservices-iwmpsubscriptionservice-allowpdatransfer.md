# IWMPSubscriptionService::allowPDATransfer

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This section describes functionality designed for use by online stores. Use of this functionality outside the context of an online store is not supported.

The **allowPDATransfer** method is implemented by the online store's plug-in to manage permission for Windows Media Player to synchronize content with a device.

## Parameters

### `hwnd` [in]

A handle to a window in which the plug-in can display a user interface.

### `pPlaylist` [in, out]

Pointer to a playlist object.

### `pfAllowTransfer` [out]

Pointer to a **BOOL**. If true, copying to a device is allowed.

## Return value

The method returns an **HRESULT**.

## Remarks

Your code should not perform lengthy operations synchronously when Windows Media Player calls this method.

When Windows Media Player calls your plug-in's **allowPDATransfer** method, it passes a pointer to a playlist, which contains items from your online store. Your **allowPDATransfer** method must remove any items from the playlist that should not be synchronized with a device.

The situations in which Windows Media Player calls **allowPDATranfer** differ between versions of Windows Media Player.

Windows Media Player 9 Series and Windows Media Player 10 call **allowPDATransfer** automatically in certain situations. For example, if the user attempts to synchronize a list of tracks with a device, and some of those tracks do not have permission to be synchronized, Windows Media Player calls **allowPDATransfer**.

Windows Media Player 11 never calls **allowPDATransfer** automatically. That is, Windows Media Player 11 calls **allowPDATransfer** only when the user explicitly requests synchronization rights. For example, the user might request a synchronization rights by choosing a command from the context menu of an information icon.

Do not rely on **allowPDATransfer** being called each time a track is synchronized with a device. Instead, implement [IWMPSubscriptionService2::prepareForSync](https://learn.microsoft.com/windows/desktop/api/subscriptionservices/nf-subscriptionservices-iwmpsubscriptionservice2-prepareforsync).

## See also

[IWMPSubscriptionService Interface](https://learn.microsoft.com/windows/desktop/api/subscriptionservices/nn-subscriptionservices-iwmpsubscriptionservice)