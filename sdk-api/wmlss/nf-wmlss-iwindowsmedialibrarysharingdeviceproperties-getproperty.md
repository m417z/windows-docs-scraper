# IWindowsMediaLibrarySharingDeviceProperties::GetProperty

## Description

\[The feature associated with this page, [Windows Media Library Sharing Services](https://learn.microsoft.com/previous-versions/windows/desktop/wmlss/windowsmedialibrarysharingservicesportal), is a legacy feature. It has been superseded by [Media Casting](https://learn.microsoft.com/windows/uwp/audio-video-camera/media-casting). Media Casting has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use Media Casting instead of #FEATURENAMENOLINK#, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetProperty** method retrieves an [IWindowsMediaLibrarySharingDeviceProperty](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmlss/nn-wmlss-iwindowsmedialibrarysharingdeviceproperty) interface that represents an individual property for a media device.

## Parameters

### `name` [in]

A **BSTR** that specifies the name of the property.

### `property` [out]

A pointer to a variable that receives a pointer to the [IWindowsMediaLibrarySharingDeviceProperty](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmlss/nn-wmlss-iwindowsmedialibrarysharingdeviceproperty) interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |