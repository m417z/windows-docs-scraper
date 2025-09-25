# IWindowsMediaLibrarySharingServices::get_userHomeMediaSharingState

## Description

\[The feature associated with this page, [Windows Media Library Sharing Services](https://learn.microsoft.com/previous-versions/windows/desktop/wmlss/windowsmedialibrarysharingservicesportal), is a legacy feature. It has been superseded by [Media Casting](https://learn.microsoft.com/windows/uwp/audio-video-camera/media-casting). Media Casting has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use Media Casting instead of #FEATURENAMENOLINK#, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **get_userHomeMediaSharingState** method retrieves a value that indicates whether the current user's media library is shared on the home network.

## Parameters

### `sharingEnabled` [out]

Pointer to a **VARIANT_BOOL** that receives **VARIANT_TRUE** if the media library is shared and **VARIANT_FALSE** if the media library is not shared.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

If home media sharing is not allowed for the computer, this method retrieves **VARIANT_FALSE** regardless of whether home media sharing is enabled by the current user.

If home media sharing is allowed for the computer and home media sharing is enabled by the current user, this method retrieves **VARIANT_TRUE**.

## See also

[IWindowsMediaLibrarySharingServices](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmlss/nn-wmlss-iwindowsmedialibrarysharingservices)

[IWindowsMediaLibrarySharingServices::get_computerHomeMediaSharingAllowed](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmlss/nf-wmlss-iwindowsmedialibrarysharingservices-get_computerhomemediasharingallowedstate)

[IWindowsMediaLibrarySharingServices::put_userHomeMediaSharingState](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmlss/nf-wmlss-iwindowsmedialibrarysharingservices-put_userhomemediasharingstate)