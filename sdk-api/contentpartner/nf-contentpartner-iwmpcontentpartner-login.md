# IWMPContentPartner::Login

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This section describes functionality designed for use by online stores. Use of this functionality outside the context of an online store is not supported.

The **Login** method logs the user in to the online store.

## Parameters

### `userInfo` [in]

Encrypted **BLOB** containing the user name.

### `pwdInfo` [in]

Encrypted **BLOB** containing the user password.

### `fUsedCachedCreds` [in]

**VARIANT_BOOL** indicating whether the plug-in should try to use cached credentials.

### `fOkToCache` [in]

**VARIANT_BOOL** indicating whether the plug-in is permitted to cache the supplied credentials.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Usually, this method is called in response to a specific request by the user to log in to the online store. Sometimes, the need to log in is implied by other user actions, such as burning a music file that requires an updated license.

The plug-in must call [IWMPContentPartnerCallback::Notify](https://learn.microsoft.com/windows/desktop/api/contentpartner/nf-contentpartner-iwmpcontentpartnercallback-notify) to notify Windows Media Player when the log-in state changes.

To decrypt the user name and password, use the **CryptUnprotectData** function. **CryptUnprotectData** is documented in the Cryptography section of the Platform SDK. You must use the CRYPTPROTECT_UI_FORBIDDEN flag in the *dwFlags* parameter of **CryptUnprotectData**. Set the optional and reserved parameters to **NULL**.

## See also

[IWMPContentPartner Interface](https://learn.microsoft.com/windows/desktop/api/contentpartner/nn-contentpartner-iwmpcontentpartner)

[IWMPContentPartner::Logout](https://learn.microsoft.com/windows/desktop/api/contentpartner/nf-contentpartner-iwmpcontentpartner-logout)