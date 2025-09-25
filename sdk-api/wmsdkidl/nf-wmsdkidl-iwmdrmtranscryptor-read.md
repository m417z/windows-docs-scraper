# IWMDRMTranscryptor::Read

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

[**Read** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Microsoft PlayReady](https://www.microsoft.com/PlayReady/).
]

The **Read** method reads data from the file loaded in the transcryptor and encrypts it for streaming to devices that support Windows Media DRM 10 for Network Devices.

## Parameters

### `pbData` [in]

Address of a buffer that receives the data.

### `pcbData` [in, out]

Address of a variable containing the size of the data buffer pointed to by *pbData*. On input, set to the size of the buffer.On output, the value is changed to the number of bytes actually read.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **NS_E_INVALID_REQUEST** | The transcryptor is not ready for reading.<br><br>OR<br><br>Another read is in progress. |

## Remarks

This method is asynchronous. It returns immediately, but processing is not complete until a WMT_TRANSCRYPTOR_READ message is sent to the [IWMStatusCallback::OnStatus](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmstatuscallback-onstatus) callback method. Neither the buffer referenced by *pbData* nor the buffer length referenced by *pcbData* are updated until the WMT_TRANSCRYPTOR_READ message is sent.

The **HRESULT** sent with the WMT_TRANSCRYPTOR_READ message contains the return value for the read operation. A special success code, NS_S_TRANSCRYPTOR_EOF, is sent to indicate that the data from this read operation includes the end of the file.

## See also

[IWMDRMTranscryptor Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmdrmtranscryptor)

[IWMDRMTranscryptor::Close](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmdrmtranscryptor-close)

[IWMDRMTranscryptor::Initialize](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmdrmtranscryptor-initialize)

[IWMDRMTranscryptor::Seek](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmdrmtranscryptor-seek)