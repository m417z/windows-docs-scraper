# IWMPContentPartnerCallback::VerifyPermissionComplete

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This section describes functionality designed for use by online stores. Use of this functionality outside the context of an online store is not supported.

The **VerifyPermissionComplete** method notifies Windows Media Player that the online store has finished processing a call to [IWMPContentPartner::VerifyPermission](https://learn.microsoft.com/windows/desktop/api/contentpartner/nf-contentpartner-iwmpcontentpartner-verifypermission).

## Parameters

### `bstrPermission` [in]

A **BSTR** that specifies the action for which permission was requested. Windows Media Player previously requested permission to perform this action by calling [IWMPContentPartner::VerifyPermission](https://learn.microsoft.com/windows/desktop/api/contentpartner/nf-contentpartner-iwmpcontentpartner-verifypermission). See Remarks for a list of possible values.

### `pContext` [in]

A pointer to a **VARIANT** that contains information related to the notification. See Remarks.

### `hrPermission` [in]

An **HRESULT** that indicates whether permission is granted. Any success code indicates that permission is granted. Any failure code indicates that permission is denied.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The following list gives the possible values for *bstrPermission* and the corresponding meanings of *pContext*.

g_szVerifyPermissionSync

Windows Media Player previously requested permission to synchronize the content on a portable device by calling **IWMPContentPartner::VerifyPermission**. In that call, Windows Media Player supplied the canonical device name in the *pContext* parameter. The online store supplies that same canonical device name in the *pContext* parameter of **VerifyPermissionComplete**.

## See also

[IWMPContentPartner::VerifyPermission](https://learn.microsoft.com/windows/desktop/api/contentpartner/nf-contentpartner-iwmpcontentpartner-verifypermission)

[IWMPContentPartnerCallback Interface](https://learn.microsoft.com/windows/desktop/api/contentpartner/nn-contentpartner-iwmpcontentpartnercallback)