# WindowsMediaLibrarySharingDeviceAuthorizationStatus enumeration

## Description

\[The feature associated with this page, [Windows Media Library Sharing Services](https://learn.microsoft.com/previous-versions/windows/desktop/wmlss/windowsmedialibrarysharingservicesportal), is a legacy feature. It has been superseded by [Media Casting](https://learn.microsoft.com/windows/uwp/audio-video-camera/media-casting). Media Casting has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use Media Casting instead of #FEATURENAMENOLINK#, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WindowsMediaLibrarySharingDeviceAuthorizationStatus** enumeration defines constants that indicate whether a media device is authorized to have access to a media library.

## Constants

### `DEVICE_AUTHORIZATION_UNKNOWN:0`

It is not known whether the device is authorized to have access to the media library.

### `DEVICE_AUTHORIZATION_ALLOWED:1`

The device is authorized to have access to the media library.

### `DEVICE_AUTHORIZATION_DENIED:2`

The device is not authorized to have access to the media library.

## See also

[Windows Media Library Sharing Services](https://learn.microsoft.com/previous-versions/windows/desktop/wmlss/windowsmedialibrarysharingservicesportal)