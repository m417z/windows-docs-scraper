# IWindowsMediaLibrarySharingServices::showShareMediaCPL

## Description

\[The feature associated with this page, [Windows Media Library Sharing Services](https://learn.microsoft.com/previous-versions/windows/desktop/wmlss/windowsmedialibrarysharingservicesportal), is a legacy feature. It has been superseded by [Media Casting](https://learn.microsoft.com/windows/uwp/audio-video-camera/media-casting). Media Casting has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use Media Casting instead of #FEATURENAMENOLINK#, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **showShareMediaCPL** method displays the media sharing page in the Control Panel and highlights a specified device.

## Parameters

### `device` [in]

**BSTR**

## Return value

This method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

If *device* is **NULL** or if *device* is an empty **BSTR**, the focus is set to a default dialog box element. Also, if *device* is a non-empty **BSTR** that is not the MAC address of a known device, the focus is set to a default dialog box element.