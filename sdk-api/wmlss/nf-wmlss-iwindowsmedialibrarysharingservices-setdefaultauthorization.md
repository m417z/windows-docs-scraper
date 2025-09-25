# IWindowsMediaLibrarySharingServices::setDefaultAuthorization

## Description

\[The feature associated with this page, [Windows Media Library Sharing Services](https://learn.microsoft.com/previous-versions/windows/desktop/wmlss/windowsmedialibrarysharingservicesportal), is a legacy feature. It has been superseded by [Media Casting](https://learn.microsoft.com/windows/uwp/audio-video-camera/media-casting). Media Casting has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use Media Casting instead of #FEATURENAMENOLINK#, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **setDefaultAuthorization** method enables or disables access to all users' media libraries by a specified set of devices.

## Parameters

### `MACAddresses` [in]

A **BSTR** that specifies the MAC addresses of the devices for which access will be enabled or disabled. The MAC addresses are delimited by commas.

### `friendlyName` [in]

A **BSTR** that specifies a friendly name that applies to all devices listed in the *MACAddresses* parameter.

### `authorization` [in]

A **VARIANT_BOOL** that specifies whether access by the set of devices is enabled (**VARIANT_TRUE**) or disabled (**VARIANT_FALSE**).

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |