# IWMPContentPartnerCallback::BuyComplete

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This section describes functionality designed for use by online stores. Use of this functionality outside the context of an online store is not supported.

The **BuyComplete** method notifies Windows Media Player that a purchase transaction has been completed.

## Parameters

### `hrResult` [in]

**HRESULT** return code indicating the success or failure of the transaction.

### `dwBuyCookie` [in]

The cookie that represents the purchase transaction. This value was provided when the Player called [IWMPContentPartner::Buy](https://learn.microsoft.com/windows/desktop/api/contentpartner/nf-contentpartner-iwmpcontentpartner-buy).

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

You must call **BuyComplete** exactly once for each call to [IWMPContentPartner::Buy](https://learn.microsoft.com/windows/desktop/api/contentpartner/nf-contentpartner-iwmpcontentpartner-buy). Call **BuyComplete** when the transaction is finished, even if it failed for some reason.

Return a success code only after all licenses related to the purchase have been delivered.

## See also

[IWMPContentPartnerCallback Interface](https://learn.microsoft.com/windows/desktop/api/contentpartner/nn-contentpartner-iwmpcontentpartnercallback)