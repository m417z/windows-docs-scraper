# IWMDRMWriter2::SetWMDRMNetEncryption

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

[**SetWMDRMNetEncryption** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Microsoft PlayReady](https://www.microsoft.com/PlayReady/).
]

The **SetWMDRMNetEncryption** method configures the writer to receive input samples encoded with Windows Media DRM 10 for Network Devices.

## Parameters

### `fSamplesEncrypted` [in]

Flag that specifies whether the samples sent to the writer will be encoded for Windows Media DRM 10 for Network Devices protocol.

### `pbKeyID` [in]

Address of the key identification in memory.

### `cbKeyID` [in]

The size of the key identification in bytes.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

You must use this method to prepare the writer if you have samples that are already encoded for delivery to a device that supports Windows Media DRM 10 for Network Devices. Call this method before calling [IWMWriter::BeginWriting](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriter-beginwriting).

After configuring the writer to receive encrypted samples, the writer will not accept samples from calls to [IWMWriter::WriteSample](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriter-writesample). Instead, you must use [IWMWriterAdvanced::WriteStreamSample](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriteradvanced-writestreamsample).

This method is intended only to create new files from existing data that is encoded for delivery to devices that support Windows Media DRM 10 for Network Devices. To generate data for streaming to secure devices from an existing DRM-protected ASF file, use the methods of the [IWMDRMTranscryptor](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmdrmtranscryptor) interface.

## See also

[IWMDRMWriter2 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmdrmwriter2)