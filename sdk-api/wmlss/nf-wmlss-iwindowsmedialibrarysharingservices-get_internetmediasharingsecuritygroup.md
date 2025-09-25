# IWindowsMediaLibrarySharingServices::get_internetMediaSharingSecurityGroup

## Description

\[The feature associated with this page, [Windows Media Library Sharing Services](https://learn.microsoft.com/previous-versions/windows/desktop/wmlss/windowsmedialibrarysharingservicesportal), is a legacy feature. It has been superseded by [Media Casting](https://learn.microsoft.com/windows/uwp/audio-video-camera/media-casting). Media Casting has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use Media Casting instead of #FEATURENAMENOLINK#, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **get_internetMediaSharingSecurityGroup** method retrieves the name of the security group that is used to authenticate connections coming in over the Internet.

## Parameters

### `securityGroup` [out]

A pointer to a **BSTR** that receives the name of the security group.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The Internet media sharing security group applies only to Windows Home Server. Applications running on other versions of Windows can call [put_internetMediaSharingSecurityGroup](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmlss/nf-wmlss-iwindowsmedialibrarysharingservices-put_internetmediasharingsecuritygroup) and **get_internetMediaSharingSecurityGroup**, but the calls will have no effect.