# IWindowsMediaLibrarySharingServices::get_computerInternetMediaSharingAllowedState

## Description

\[The feature associated with this page, [Windows Media Library Sharing Services](https://learn.microsoft.com/previous-versions/windows/desktop/wmlss/windowsmedialibrarysharingservicesportal), is a legacy feature. It has been superseded by [Media Casting](https://learn.microsoft.com/windows/uwp/audio-video-camera/media-casting). Media Casting has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use Media Casting instead of #FEATURENAMENOLINK#, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **get_computerInternetMediaSharingAllowedState** method retrieves a value that indicates whether media libraries on the computer are allowed to be shared on the Internet.

## Parameters

### `sharingAllowed` [out]

Pointer to a **VARIANT_BOOL** that receives **VARIANT_TRUE** if media libraries are allowed to be shared and **VARIANT_FALSE** if media libraries are not allowed to be shared.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

If home media sharing is not allowed for the computer, Internet media sharing is also not allowed for the computer.

If Internet media sharing is not allowed for the computer, none of the users' media libraries are shared on the Internet, regardless of whether individual users have enabled Internet media sharing.

If Internet media sharing is allowed for the computer and a particular user has enabled Internet media sharing, then that user's media library is shared on the Internet.

## See also

[IWindowsMediaLibrarySharingServices](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmlss/nn-wmlss-iwindowsmedialibrarysharingservices)

[IWindowsMediaLibrarySharingServices::put_computerInternetMediaSharingAllowedState](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmlss/nf-wmlss-iwindowsmedialibrarysharingservices-put_computerinternetmediasharingallowedstate)