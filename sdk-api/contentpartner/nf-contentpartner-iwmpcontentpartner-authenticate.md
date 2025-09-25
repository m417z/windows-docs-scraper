# IWMPContentPartner::Authenticate

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This section describes functionality designed for use by online stores. Use of this functionality outside the context of an online store is not supported.

The **Authenticate** method initiates an attempt to authenticate the user.

## Parameters

### `userInfo` [in]

**BLOB** that contains encrypted user information.

### `pwdInfo` [in]

**BLOB** that contains encrypted password information.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Certain links on a discovery page have targets that should be displayed only after the user has been authenticated. The discovery page, Windows Media Player, and the online store's plug-in use the following steps to authenticate the user and display the target webpage:

1. Script on a discovery page calls the [External.authenticate](https://learn.microsoft.com/windows/desktop/WMP/external-authenticate) method.
2. Windows Media Player displays a dialog box to obtain a user name and password.
3. Windows Media Player calls **IWMPContentPartner::Authenticate**, which initiates the authentication attempt and returns immediately.
4. When the authentication attempt is complete, the online store's plug-in calls [IWMPContentPartnerCallback::Notify](https://learn.microsoft.com/windows/desktop/api/contentpartner/nf-contentpartner-iwmpcontentpartnercallback-notify), passing wmpcnAuthResult and a Boolean value that indicates whether the attempt was successful.
5. If the authentication attempt was successful, Windows Media Player calls [IWMPContentPartner::GetItemInfo](https://learn.microsoft.com/windows/desktop/api/contentpartner/nf-contentpartner-iwmpcontentpartner-getiteminfo), passing g_szItemInfo_AuthenticationSuccessURL, to obtain the URL of an authentication-success webpage. In this call, Windows Media Player passes the same index that the discovery page passed to the **External.authenticate** method.
6. Windows Media Player displays the authentication-success webpage.

To decrypt the information supplied in *userInfo* and *pwdInfo*, use the **CryptUnprotectData** function, which is documented in the Cryptography section of the Windows SDK. You must set the CRYPTPROTECT_UI_FORBIDDEN flag in the *dwFlags* parameter. Set the optional and reserved parameters to **NULL**.

## See also

[IWMPContentPartner Interface](https://learn.microsoft.com/windows/desktop/api/contentpartner/nn-contentpartner-iwmpcontentpartner)