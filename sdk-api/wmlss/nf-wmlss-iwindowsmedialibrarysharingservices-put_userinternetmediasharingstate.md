# IWindowsMediaLibrarySharingServices::put_userInternetMediaSharingState

## Description

\[The feature associated with this page, [Windows Media Library Sharing Services](https://learn.microsoft.com/previous-versions/windows/desktop/wmlss/windowsmedialibrarysharingservicesportal), is a legacy feature. It has been superseded by [Media Casting](https://learn.microsoft.com/windows/uwp/audio-video-camera/media-casting). Media Casting has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use Media Casting instead of #FEATURENAMENOLINK#, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **put_userInternetMediaSharingState** method enables or disables sharing of the current user's media library on the Internet.

## Parameters

### `sharingEnabled`

A **VARIANT_BOOL** that specifies whether sharing on the Internet is enabled (**VARIANT_TRUE**) or disabled (**VARIANT_FALSE**) for the current user.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

If Internet media sharing is not allowed for the computer, users on the Internet will not have access to the current user's media library, regardless of whether Internet media sharing is enabled for the current user.

If Internet media sharing is allowed for the computer and Internet media sharing is enabled for the current user, other users on the Internet will have access to the current user's media library.

## See also

[IWindowsMediaLibrarySharingServices](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmlss/nn-wmlss-iwindowsmedialibrarysharingservices)

[IWindowsMediaLibrarySharingServices::get_userInternetMediaSharingState](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmlss/nf-wmlss-iwindowsmedialibrarysharingservices-get_userinternetmediasharingstate)

[IWindowsMediaLibrarySharingServices::put_computerHomeMediaSharingAllowedState](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmlss/nf-wmlss-iwindowsmedialibrarysharingservices-put_computerhomemediasharingallowedstate)