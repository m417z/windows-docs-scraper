# IWindowsMediaLibrarySharingDevice::put_Authorization

## Description

\[The feature associated with this page, [Windows Media Library Sharing Services](https://learn.microsoft.com/previous-versions/windows/desktop/wmlss/windowsmedialibrarysharingservicesportal), is a legacy feature. It has been superseded by [Media Casting](https://learn.microsoft.com/windows/uwp/audio-video-camera/media-casting). Media Casting has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use Media Casting instead of #FEATURENAMENOLINK#, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **put_Authorization** method authorizes or unauthorizes the device to have access to the current user's media library.

## Parameters

### `authorization` [in]

An element of the [WindowsMediaLibrarySharingDeviceAuthorizationStatus](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmlss/ne-wmlss-windowsmedialibrarysharingdeviceauthorizationstatus) enumeration that specifies whether the device is authorized (**DEVICE_AUTHORIZATION_ALLOWED**) or unauthorized (**DEVICE_AUTHORIZATION_DENIED**) to have access to the current user's media library.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |