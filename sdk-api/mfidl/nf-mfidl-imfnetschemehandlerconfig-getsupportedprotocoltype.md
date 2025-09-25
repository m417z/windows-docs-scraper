# IMFNetSchemeHandlerConfig::GetSupportedProtocolType

## Description

Retrieves a supported protocol by index

## Parameters

### `nProtocolIndex` [in]

Zero-based index of the protocol to retrieve. To get the number of supported protocols, call [IMFNetSchemeHandlerConfig::GetNumberOfSupportedProtocols](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfnetschemehandlerconfig-getnumberofsupportedprotocols).

### `pnProtocolType` [out]

Receives a member of the [MFNETSOURCE_PROTOCOL_TYPE](https://learn.microsoft.com/windows/desktop/api/mfidl/ne-mfidl-mfnetsource_protocol_type) enumeration.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The value passed in the *nProtocolIndex* parameter was greater than the total number of supported protocols, returned by [GetNumberOfSupportedProtocols](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfnetschemehandlerconfig-getnumberofsupportedprotocols). |

## See also

[IMFNetSchemeHandlerConfig](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfnetschemehandlerconfig)