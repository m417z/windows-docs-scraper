# IWMPContentPartner::Notify

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This section describes functionality designed for use by online stores. Use of this functionality outside the context of an online store is not supported.

The **Notify** method provides the content partner plug-in with event notifications from Windows Media Player.

## Parameters

### `type` [in]

The notification type, specified as a member of the [WMPPartnerNotification](https://learn.microsoft.com/windows/desktop/api/contentpartner/ne-contentpartner-wmppartnernotification) enumeration.

### `pContext` [in]

Pointer to a **VARIANT** that contains notification data.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The data type for *pContext* is **VT_EMPTY** for all notifications except wmpsnCatalogDownloadFailure. In the case of a catalog download failure, the data type is **VT_ERROR** and the variable contains an **HRESULT** error code.

## See also

[IWMPContentPartner Interface](https://learn.microsoft.com/windows/desktop/api/contentpartner/nn-contentpartner-iwmpcontentpartner)

[WMPPartnerNotification](https://learn.microsoft.com/windows/desktop/api/contentpartner/ne-contentpartner-wmppartnernotification)