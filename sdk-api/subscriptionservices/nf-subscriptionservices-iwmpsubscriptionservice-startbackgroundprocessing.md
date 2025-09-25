# IWMPSubscriptionService::startBackgroundProcessing

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This section describes functionality designed for use by online stores. Use of this functionality outside the context of an online store is not supported.

The **startBackgroundProcessing** method is implemented by the online store to initiate background processing tasks.

## Parameters

### `hwnd` [in]

A handle to a window in which the plug-in can display a user interface.

## Return value

The method returns an **HRESULT**.

## Remarks

Your code should not perform lengthy operations synchronously when Windows Media Player calls this method. Instead, you must perform time-consuming tasks on a separate worker thread.

Windows Media Player calls **startBackgroundProcessing** during idle time after the user selects the online store. This is useful for the online store to acquire play count data or renew expired licenses.

## See also

[IWMPSubscriptionService Interface](https://learn.microsoft.com/windows/desktop/api/subscriptionservices/nn-subscriptionservices-iwmpsubscriptionservice)