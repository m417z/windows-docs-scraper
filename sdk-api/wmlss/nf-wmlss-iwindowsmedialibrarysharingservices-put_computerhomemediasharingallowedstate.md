# IWindowsMediaLibrarySharingServices::put_computerHomeMediaSharingAllowedState

## Description

\[The feature associated with this page, [Windows Media Library Sharing Services](https://learn.microsoft.com/previous-versions/windows/desktop/wmlss/windowsmedialibrarysharingservicesportal), is a legacy feature. It has been superseded by [Media Casting](https://learn.microsoft.com/windows/uwp/audio-video-camera/media-casting). Media Casting has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use Media Casting instead of #FEATURENAMENOLINK#, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **put_computerHomeMediaSharingAllowedState** method specifies whether media libraries on the computer are allowed to be shared on the home network.

## Parameters

### `sharingAllowed`

A **VARIANT_BOOL** that specifies VARIANT_TRUE if media libraries are allowed to be shared or **VARIANT_FALSE** if media libraries are not allowed to be shared.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method must be called by code running under elevated privileges.

If home media sharing is not allowed for the computer, none of the users' media libraries are shared on the home network, regardless of whether individual users have enabled home media sharing.

If home media sharing is allowed for the computer and a particular user has enabled media sharing, then that user's media library is shared on the home network.

**Warning**Each call to **put_computerHomeMediaSharingAllowedState** with the *sharingAllowed* parameter set to **VARIANT_TRUE** updates the access control list (ACL) and last changed time of each file in the computer's Public Music, Public Pictures, and Public Videos folders. This behavior might change in future versions of Windows.

## See also

[IWindowsMediaLibrarySharingServices](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmlss/nn-wmlss-iwindowsmedialibrarysharingservices)

[IWindowsMediaLibrarySharingServices::get_computerHomeMediaSharingAllowedState](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmlss/nf-wmlss-iwindowsmedialibrarysharingservices-get_computerhomemediasharingallowedstate)