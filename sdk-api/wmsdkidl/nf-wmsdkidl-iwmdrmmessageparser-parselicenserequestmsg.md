# IWMDRMMessageParser::ParseLicenseRequestMsg

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

[**ParseLicenseRequestMsg** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Microsoft PlayReady](https://www.microsoft.com/PlayReady/).
]

The **ParseLicenseRequestMsg** method extracts the device identification and requested action from a policy request message.

## Parameters

### `pbLicenseRequestMsg` [in]

Address of the license request message in memory. This is a message received by your application from a device.

### `cbLicenseRequestMsg` [in]

The size of license request message in bytes.

### `ppDeviceCert` [out]

Address of a variable that receives the address of the [INSSBuffer](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsbuffer/nn-wmsbuffer-inssbuffer) interface of the buffer object that contains the device certificate.

### `pDeviceSerialNumber` [out]

Address of a [DRM_VAL16](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsdkidl/ns-wmsdkidl-drm_val16) structure that receives the device identifier.

### `pbstrAction` [out]

Address of a variable that receives the string containing the requested action. The supported actions correspond to rights associates with DRM licenses. The only action string currently supported is "Play".

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The *pbLicenseRequestMsg* parameter is **NULL**, or the *cbLicenseRequestMsg* parameter is 0. |

## Remarks

The license request message sent by the device determines the action that your application should take. After parsing a message with the "Play" action, you can begin processing the file with the methods of the [IWMDRMTranscryptor](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmdrmtranscryptor) interface.

## See also

[IWMDRMMessageParser Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmdrmmessageparser)