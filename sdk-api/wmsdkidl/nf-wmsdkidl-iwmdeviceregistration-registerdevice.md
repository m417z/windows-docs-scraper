# IWMDeviceRegistration::RegisterDevice

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

[**RegisterDevice** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Microsoft PlayReady](https://www.microsoft.com/PlayReady/).
]

The **RegisterDevice** method adds a device to the device list.

## Parameters

### `dwRegisterType` [in]

The type of the device to register. Devices that support Windows Media DRM 10 for Network Devices use DRM_DEVICE_REGISTER_TYPE_STREAMING. To register a device that does not use Windows Media DRM 10 for Network Devices, set this parameter to 0.

### `pbCertificate` [in]

Address of the device certificate in memory.

### `cbCertificate` [in]

The size of the certificate data in bytes.

### `SerialNumber` [in]

128-bit device identifier, stored in a [DRM_VAL16](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsdkidl/ns-wmsdkidl-drm_val16) structure.

### `ppDevice` [out]

Address of a variable that receives a pointer to the [IWMRegisteredDevice](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmregistereddevice) interface of the newly registered device.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The *pbCertificate* parameter is **NULL**, but the *cbCertificate* parameter is greater than zero.<br><br>OR<br><br>The *dwRegisterType* parameter is set to DRM_DEVICE_REGISTER_TYPE_STREAMING, but no certificate is provided. |
| **E_OUTOFMEMORY** | The method could not allocate memory for an internal variable. |

## Remarks

Registration is triggered by a registration request message sent to your application by the device. When you receive this message, you must first extract the certificate and device identifier from it by calling [IWMDRMMessageParser::ParseRegistrationReqMsg](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmdrmmessageparser-parseregistrationreqmsg). After parsing the message, pass the certificate and device identifier to this method.

After you register a device, you must perform proximity detection before sending any protected media data to it.

The DRM_DEVICE_REGISTER_TYPE_STORAGE register type is defined, but is not used in this release.

## See also

[IWMDeviceRegistration Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmdeviceregistration)

[IWMProximityDetection Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmproximitydetection)