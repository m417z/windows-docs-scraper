# IMbnSmsConfiguration::put_ServiceCenterAddress

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

SMS default Service Center address.

This property is read/write.

## Parameters

## Remarks

When setting *scAddress*, the calling application must use either of these formats.

* "+ <International Country Code> <SMS Service Center Number>\0"
* "<SMS Service Center Number>\0"

## See also

[IMbnSmsConfiguration](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsmsconfiguration)