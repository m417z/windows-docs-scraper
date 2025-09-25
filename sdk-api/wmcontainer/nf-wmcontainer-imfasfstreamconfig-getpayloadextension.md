# IMFASFStreamConfig::GetPayloadExtension

## Description

Retrieves information about an existing payload extension.

## Parameters

### `wPayloadExtensionNumber` [in]

The payload extension index. Valid indexes range from 0, to one less than the number of extensions obtained by calling [IMFASFStreamConfig::GetPayloadExtensionCount](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfstreamconfig-getpayloadextensioncount).

### `pguidExtensionSystemID` [out]

Receives a GUID that identifies the payload extension. For a list of predefined payload extensions, see [ASF Payload Extension GUIDs](https://learn.microsoft.com/windows/desktop/medfound/asf-payload-extension-guids). Applications can also define custom payload extensions.

### `pcbExtensionDataSize` [out]

Receives the number of bytes added to each sample for the extension.

### `pbExtensionSystemInfo` [out]

Pointer to a buffer that receives information about this extension system. This information is the same for all samples and is stored in the content header (not in each sample). This parameter can be **NULL**. To find the required size of the buffer, set this parameter to **NULL**; the size is returned in *pcbExtensionSystemInfo*.

### `pcbExtensionSystemInfo` [in, out]

On input, specifies the size of the buffer pointed to by *pbExtensionSystemInfo*. On output, receives the required size of the *pbExtensionSystemInfo* buffer in bytes.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | Invalid argument. |
| **MF_E_BUFFERTOOSMALL** | The buffer specified in *pbExtensionSystemInfo* is too small. |
| **MF_E_INVALIDINDEX** | The *wPayloadExtensionNumber* parameter is out of range. |

## See also

[IMFASFStreamConfig](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfstreamconfig)

[IMFASFStreamConfig::AddPayloadExtension](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfstreamconfig-addpayloadextension)

[IMFASFStreamConfig::GetPayloadExtensionCount](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfstreamconfig-getpayloadextensioncount)