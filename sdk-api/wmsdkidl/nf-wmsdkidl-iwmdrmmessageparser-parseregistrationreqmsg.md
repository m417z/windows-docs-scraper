# IWMDRMMessageParser::ParseRegistrationReqMsg

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

[**ParseRegistrationReqMsg** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Microsoft PlayReady](https://www.microsoft.com/PlayReady/).
]

The **ParseRegistrationReqMsg** method extracts the device certificate and identifier from a registration message sent by a device.

## Parameters

### `pbRegistrationReqMsg` [in]

Address of the registration message in memory. This is a message received by your application from a device.

### `cbRegistrationReqMsg` [in]

The size of registration message in bytes.

### `ppDeviceCert` [out]

Address of a variable that receives the address of the [INSSBuffer](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsbuffer/nn-wmsbuffer-inssbuffer) interface of the buffer object that contains the device certificate.

### `pDeviceSerialNumber` [out]

Address of a [DRM_VAL16](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsdkidl/ns-wmsdkidl-drm_val16) structure that receives the device identifier.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The *pbRegistrationMsg* parameter is **NULL**, or the *cbRegistrationMsg* parameter is 0. |

## Remarks

Registration request messages are sent by devices when they are connected to a network shared by the computer running your application. When your application receives the message, it must first parse the message by using this method to retrieve the device certificate and device identifier. The combination of device certificate and device identifier uniquely identifies the device.

After parsing the message with this method, you can search the device database to determine whether the device is already registered, or you can try to register the device. Both of these actions use the methods of the [IWMDeviceRegistration](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmdeviceregistration) interface.

## See also

[IWMDRMMessageParser Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmdrmmessageparser)