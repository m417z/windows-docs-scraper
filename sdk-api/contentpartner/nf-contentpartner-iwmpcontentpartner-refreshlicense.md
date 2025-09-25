# IWMPContentPartner::RefreshLicense

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This section describes functionality designed for use by online stores. Use of this functionality outside the context of an online store is not supported.

The **RefreshLicense** method initiates the update of a license for the specified media file.

## Parameters

### `dwCookie` [in]

A cookie that identifies the update request. When the online store has finished updating the license, it passes this cookie to [IWMPContentPartnerCallback::RefreshLicenseComplete](https://learn.microsoft.com/windows/desktop/api/contentpartner/nf-contentpartner-iwmpcontentpartnercallback-refreshlicensecomplete).

### `fLocal` [in]

**VARIANT_BOOL** that specifies whether the media file is located on the user's computer. **VARIANT_TRUE** specifies that the file is on the user's computer. **VARIANT_FALSE** specifies that the file is not currently on the user's computer, but is available from the online store's servers.

### `bstrURL` [in]

**BSTR** containing the URL of the media file on the user's computer. This is **NULL** if the media file is not on the user's computer.

### `type` [in]

A member of the [WMPStreamingType](https://learn.microsoft.com/windows/desktop/api/contentpartner/ne-contentpartner-wmpstreamingtype) enumeration that specifies the type (music, video, or radio) of the media file.

### `contentID` [in]

Content ID of the media file for which the updated license is being requested.

### `bstrRefreshReason` [in]

Reason for refreshing the license. The caller (Windows Media Player) sets this parameter to one of the following values:

g_szRefreshLicensePlay

g_szRefreshLicenseBurn

g_szRefreshLicenseSync

### `pReasonContext` [in]

If refreshing the license for synchronization to a device, this parameter has type **VT_BSTR** and contains the device name. Otherwise, this parameter has type **VT_EMPTY** and supplies no information.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method must not display a user interface.

This method initiates the license update and then returns immediately. When the online store has completed the license update, the online store's plug-in calls **IWMPContentPartnerCallback::RefreshLicenseComplete**.

## See also

[IWMPContentPartner Interface](https://learn.microsoft.com/windows/desktop/api/contentpartner/nn-contentpartner-iwmpcontentpartner)

[IWMPContentPartnerCallback::RefreshLicenseComplete](https://learn.microsoft.com/windows/desktop/api/contentpartner/nf-contentpartner-iwmpcontentpartnercallback-refreshlicensecomplete)