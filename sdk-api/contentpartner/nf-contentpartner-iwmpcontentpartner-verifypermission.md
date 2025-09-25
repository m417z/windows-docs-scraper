# IWMPContentPartner::VerifyPermission

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This section describes functionality designed for use by online stores. Use of this functionality outside the context of an online store is not supported.

The **VerifyPermission** method initiates the process of verifying permission for Windows Media Player to perform an action.

## Parameters

### `bstrPermission` [in]

A **BSTR** that specifies the action for which permission is being requested. See Remarks for a list of possible values.

### `pContext` [in]

A pointer to a **VARIANT** that contains information related to the request. See Remarks.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The **VerifyPermission** method initiates a permission verification and then returns immediately. When the online store has completed the verification, it calls [IWMPContentPartnerCallback::VerifyPermissionComplete](https://learn.microsoft.com/windows/desktop/api/contentpartner/nf-contentpartner-iwmpcontentpartnercallback-verifypermissioncomplete) to notify Windows Media Player that permission has been granted or denied.

The following list gives the possible values for *bstrPermission* along with the corresponding meanings of *pContext*.

g_szVerifyPermissionSync

Windows Media Player is requesting permission from the online store to synchronize the content on a portable device. The *pContext* parameter is a **VT_BSTR** that specifies the canonical device name.

## See also

[IWMPContentPartner Interface](https://learn.microsoft.com/windows/desktop/api/contentpartner/nn-contentpartner-iwmpcontentpartner)

[IWMPContentPartnerCallback::VerifyPermissionComplete](https://learn.microsoft.com/windows/desktop/api/contentpartner/nf-contentpartner-iwmpcontentpartnercallback-verifypermissioncomplete)