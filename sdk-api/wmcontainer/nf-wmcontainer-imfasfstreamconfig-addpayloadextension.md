# IMFASFStreamConfig::AddPayloadExtension

## Description

Configures a payload extension for the stream.

## Parameters

### `guidExtensionSystemID` [in]

Pointer to a GUID that identifies the payload extension. For a list of predefined payload extensions, see [ASF Payload Extension GUIDs](https://learn.microsoft.com/windows/desktop/medfound/asf-payload-extension-guids). Applications can also define custom payload extensions.

### `cbExtensionDataSize` [in]

Number of bytes added to each sample for the extension.

### `pbExtensionSystemInfo` [in]

A pointer to a buffer that contains information about this extension system. This information is the same for all samples and is stored in the content header (not with each sample). This parameter can be **NULL** if *cbExtensionSystemInfo* is 0.

### `cbExtensionSystemInfo` [in]

Amount of data, in bytes, that describes this extension system. If this value is 0, then *pbExtensionSystemInfo* can be **NULL**.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IMFASFStreamConfig](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfstreamconfig)

[IMFASFStreamConfig::GetPayloadExtension](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfstreamconfig-getpayloadextension)