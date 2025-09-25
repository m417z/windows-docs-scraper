# IWindowsMediaLibrarySharingServices::put_allowSharingToAllDevices

## Description

\[The feature associated with this page, [Windows Media Library Sharing Services](https://learn.microsoft.com/previous-versions/windows/desktop/wmlss/windowsmedialibrarysharingservicesportal), is a legacy feature. It has been superseded by [Media Casting](https://learn.microsoft.com/windows/uwp/audio-video-camera/media-casting). Media Casting has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use Media Casting instead of #FEATURENAMENOLINK#, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **put_allowSharingToAllDevices** method allows or disallows sharing of the current user's media library with all devices on the home network.

## Parameters

### `sharingEnabled` [in]

A **VARIANT_BOOL** that specifies whether sharing is allowed (**VARIANT_TRUE**) or not allowed (**VARIANT_FALSE**).

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |