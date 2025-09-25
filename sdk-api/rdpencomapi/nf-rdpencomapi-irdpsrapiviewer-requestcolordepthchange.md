# IRDPSRAPIViewer::RequestColorDepthChange

## Description

[The [IRDPSRAPIViewer](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nn-rdpencomapi-irdpsrapiviewer) interface is no longer available for use for UWP applications as of Windows 10, version 1709. It is still supported for Desktop apps.]

Requests a color depth change on the sharer Winlogon user session.

## Parameters

### `Bpp` [in]

Type: **long**

Specifies the color depth of the session in bits per pixel. Possible values are 16 and 24. If you specify a value of 8, the color depth is set to 16 bits per pixel.

**Windows Server 2008 and Windows Vista:** Possible values are 8, 16, and 24.

## Return value

Type: **HRESULT**

If the method succeeds, the return value is **S_OK**. Otherwise, the return value is an error code.

## See also

[IRDPSRAPIViewer](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nn-rdpencomapi-irdpsrapiviewer)