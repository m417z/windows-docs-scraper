# IWMDRMTranscryptor::Initialize

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

[**Initialize** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Microsoft PlayReady](https://www.microsoft.com/PlayReady/).
]

The **Initialize** method loads a file into the DRM transcryptor. A file must be loaded before the transcryptor can process any data.

## Parameters

### `bstrFileName` [in]

Name of the file to load. This should be a DRM-encrypted ASF file.

### `pbLicenseRequestMsg` [in]

Address of the license request message in memory. This message is sent to your application by a device.

### `cbLicenseRequestMsg` [in]

The size of the license request message in bytes.

### `ppLicenseResponseMsg` [out]

Address of a variable that receives the address of the license response message. Your application must send this message to the device before sending any encrypted data.

### `pCallback` [in]

Address of the [IWMStatusCallback](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmstatuscallback) implementation that will receive status messages from the transcryptor.

### `pvContext` [in]

Generic pointer, for use by the application. This is passed to the application in calls to the [IWMStatusCallback::OnStatus](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmstatuscallback-onstatus) callback. You can use this parameter to differentiate between messages from different objects when sharing a single status callback. This parameter can be **NULL**.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | One or more of the pointer parameters is **NULL**.<br><br>OR<br><br>The *cbPolicyRequestMsg* parameter is 0. |
| **NS_E_INVALID_REQUEST** | Another transcription is in progress. |
| **E_OUTOFMEMORY** | The method could not allocate memory for an internal object. |

## Remarks

This method is asynchronous. It returns immediately, but processing is not complete until a WMT_TRANSCRYPTOR_INIT message is sent to the **IWMStatusCallback::OnStatus** callback method. The **HRESULT** sent with the message contains the return value for the initialization.

## See also

[IWMDRMTranscryptor Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmdrmtranscryptor)

[IWMDRMTranscryptor::Close](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmdrmtranscryptor-close)

[IWMDRMTranscryptor::Read](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmdrmtranscryptor-read)