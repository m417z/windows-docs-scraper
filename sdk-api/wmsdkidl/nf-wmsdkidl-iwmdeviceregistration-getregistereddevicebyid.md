# IWMDeviceRegistration::GetRegisteredDeviceByID

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

[**GetRegisteredDeviceByID** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Microsoft PlayReady](https://www.microsoft.com/PlayReady/).
]

The **GetRegisteredDeviceByID** method retrieves information about a registered device by the device identifier.

## Parameters

### `dwRegisterType` [in]

The type of the device for which to retrieve information. Devices that support Windows Media DRM 10 for Network Devices use the DRM_DEVICE_REGISTER_TYPE_STREAMING register type.

### `pbCertificate` [in]

Address of the device certificate in memory.

### `cbCertificate` [in]

The size of the certificate data in bytes.

### `SerialNumber` [in]

128-bit device identifier, stored in a [DRM_VAL16](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsdkidl/ns-wmsdkidl-drm_val16) structure.

### `ppDevice` [out]

Address of a variable that receives a pointer to an [IWMRegisteredDevice](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmregistereddevice) interface. This interface provides access to information about the registered device in the list that matches the other identifying parameters.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The *ppDevice* parameter is **NULL**.<br><br>OR<br><br>The *pbCertificate* parameter is **NULL**, but the *cbCertificate* parameter is greater than zero. |
| **NS_E_DRM_DEVICE_NOT_REGISTERED** | The specified device is not registered. |

## Remarks

When your application receives messages from a device, you can use the methods of the [IWMDRMMessageParser](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmdrmmessageparser) interface to extract the device certificate and device identifier. You can identify the device by using that data as inputs to this method.

The DRM_DEVICE_REGISTER_TYPE_STORAGE register type is defined, but is not used in this release.

## See also

[IWMDeviceRegistration Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmdeviceregistration)