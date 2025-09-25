# IWMRegisteredDevice::GetDeviceType

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetDeviceType** method retrieves the device type associated with the device.

## Parameters

### `pdwType` [out]

Address of a variable that receives the device type.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Devices that support Windows Media DRM 10 for Network Devices use the DRM_DEVICE_REGISTER_TYPE_STREAMING register type. To determine whether the device supports Windows Media DRM 10 for Network Devices, call [IsWmdrmCompliant](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmregistereddevice-iswmdrmcompliant).

The DRM_DEVICE_REGISTER_TYPE_STORAGE register type is defined, but is not used in this release.

## See also

[IWMRegisteredDevice Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmregistereddevice)