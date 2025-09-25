# IWMPContentPartner::Buy

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This section describes functionality designed for use by online stores. Use of this functionality outside the context of an online store is not supported.

The **Buy** method initiates the purchase of digital media content.

## Parameters

### `pInfo` [in]

Pointer to a content container list that represents the content to be purchased.

### `cookie` [in]

A cookie used to identify the transaction. You must store this value and pass it to [IWMPContentPartnerCallback::BuyComplete](https://learn.microsoft.com/windows/desktop/api/contentpartner/nf-contentpartner-iwmpcontentpartnercallback-buycomplete) when the purchase transaction is finished.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

You must call **IWMPContentPartnerCallback::BuyComplete** exactly once for each call to **Buy**. Call **BuyComplete** when the transaction is finished, even if it failed for some reason.

If the user has an expired license for content previously purchased, you can simply update the license.

## See also

[IWMPContentPartner Interface](https://learn.microsoft.com/windows/desktop/api/contentpartner/nn-contentpartner-iwmpcontentpartner)