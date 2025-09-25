# IWMPContentPartnerCallback::RefreshLicenseComplete

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This section describes functionality designed for use by online stores. Use of this functionality outside the context of an online store is not supported.

The **RefreshLicenseComplete** method notifies Windows Media Player that the online store has finished processing a request to update the license for a media file.

## Parameters

### `dwCookie` [in]

A cookie that represents a request to update a license for a media file. Windows Media Player previously supplied this cookie to the online store's plug-in by calling [IWMPContentPartner::RefreshLicense](https://learn.microsoft.com/windows/desktop/api/contentpartner/nf-contentpartner-iwmpcontentpartner-refreshlicense).

### `contentID` [in]

The content ID of the media file for which the license update was requested.

### `hrRefresh` [in]

An **HRESULT** that indicates whether the license update was successful. Any success code indicates that the update succeeded. Any failure code indicates that the update failed.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Windows Media Player requests a license update by calling the plug-in's [RefreshLicense](https://learn.microsoft.com/windows/desktop/api/contentpartner/nf-contentpartner-iwmpcontentpartner-refreshlicense) method, which initiates the update and returns immediately. When the online store has finished processing the update request, the plug-in calls **RefreshLicenseComplete**.

## See also

[IWMPContentPartner::RefreshLicense](https://learn.microsoft.com/windows/desktop/api/contentpartner/nf-contentpartner-iwmpcontentpartner-refreshlicense)

[IWMPContentPartnerCallback Interface](https://learn.microsoft.com/windows/desktop/api/contentpartner/nn-contentpartner-iwmpcontentpartnercallback)