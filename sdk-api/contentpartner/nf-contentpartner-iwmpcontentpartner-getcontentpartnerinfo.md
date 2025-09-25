# IWMPContentPartner::GetContentPartnerInfo

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This section describes functionality designed for use by online stores. Use of this functionality outside the context of an online store is not supported.

The **GetContentPartnerInfo** method retrieves specific information about the online store.

## Parameters

### `bstrInfoName` [in]

A **BSTR** that specifies the type of information to retrieve. See Remarks for a list of possible values.

### `pData` [out]

Address of a **VARIANT** that receives the information.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The following list gives the possible values for *bstrInfoName* along with the corresponding values returned in *pData*.

g_szContentPartnerInfo_LoginState

The *pData* parameter receives a **VT_BOOL** that indicates whether the user is currently signed in. VARIANT_TRUE indicates that the user is signed in; VARIANT_FALSE indicates that the user is not signed in.

g_szContentPartnerInfo_MediaPlayerAccountType

The *pData* parameter receives a **WMPAccountType** enumeration value (**VT_UI4**) that indicates the account type. This value is used by Windows Media Player.

g_szContentPartnerInfo_AccountType

The *pData* parameter receives a **VT_BSTR** that contains the account type string for the online store. This value is not used by Windows Media Player but might be displayed to the user.

g_szContentPartnerInfo_HasCachedCredentials

The *pData* parameter receives a **VT_BOOL** that indicates whether the plug-in has cached the user's credentials (user name and password). VARIANT_TRUE indicates that the plug-in has cached the credentials; VARIANT_FALSE indicates that the plug-in has not cached the credentials.

g_szContentPartnerInfo_LicenseRefreshAdvanceWarning

The *pData* parameter receives a **VT_UI4** that indicates the number of days before expiration within which the online store can preemptively renew a license. For example, if the plug-in can support renewing a license for subscription content 5 days before the license expires, *pData* receives the value 5.

g_szContentPartnerInfo_PurchasedTrackRequiresReDownload

The *pData* parameter receives a **VT_BOOL** that indicates whether a track being purchased must be downloaded even though the content was downloaded in the past. VARIANT_TRUE indicates that the track must be downloaded; VARIANT_FALSE indicates that the track does not have to be downloaded.

g_szContentPartnerInfo_MaximumTrackPurchasePerPurchase

The *pData* parameter receives a **VT_UI4** that indicates the maximum number of tracks that the online store can handle in a single call to **IWMPContentPartner::Buy**. If there is no maximum, *pData* receives a value of 0.

g_szContentPartnerInfo_AccountBalance

The *pData* parameter receives a **VT_BSTR** that indicates the user's account balance. Windows Media Player displays this string but does not interpret it.

g_szContentPartnerInfo_UserName

The *pData* parameter receives a **VT_BSTR** that indicates the user name of the user that is currently logged in. Windows Media Player displays this string but does not interpret it.

## See also

[IWMPContentPartner Interface](https://learn.microsoft.com/windows/desktop/api/contentpartner/nn-contentpartner-iwmpcontentpartner)