# IWMDeviceRegistration::GetFirstRegisteredDevice

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

[**GetFirstRegisteredDevice** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Microsoft PlayReady](https://www.microsoft.com/PlayReady/).
]

The **GetFirstRegisteredDevice** method retrieves information about the first device of a specified type that is in the device registration database.

## Parameters

### `dwRegisterType` [in]

The type of device for which to retrieve information. Devices that support Windows Media DRM 10 for Network Devices use the DRM_DEVICE_REGISTER_TYPE_STREAMING register type.

### `ppDevice` [out]

Address of a variable that receives a pointer to an [IWMRegisteredDevice](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmregistereddevice) interface. This interface provides access to information about the first registered device in the database that matches the type specified by *dwRegisterType*.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The *ppDevice* parameter is **NULL**. |
| **S_FALSE** | There are no registered devices to enumerate. When this value is returned, the address pointed to by *ppDevice* is set to **NULL**. |

## Remarks

To enumerate registered devices of a given type, begin by calling this method to retrieve the first device entry. Then make repeated calls to [GetNextRegisteredDevice](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmdeviceregistration-getnextregistereddevice) to get subsequent device entries from the database.

The DRM_DEVICE_REGISTER_TYPE_STORAGE register type is defined, but is not used in this release.

## See also

[IWMDeviceRegistration Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmdeviceregistration)