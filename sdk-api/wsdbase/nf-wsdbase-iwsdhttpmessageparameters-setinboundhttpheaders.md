# IWSDHttpMessageParameters::SetInboundHttpHeaders

## Description

Sets the HTTP headers used for inbound SOAP-over-HTTP transmissions.

## Parameters

### `pszHeaders` [in]

The HTTP headers to be set.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_INVALIDARG** | The length in characters of *pszHeaders* exceeds WSD_MAX_TEXT_LENGTH (8192). |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |

## See also

[IWSDHttpMessageParameters](https://learn.microsoft.com/windows/desktop/api/wsdbase/nn-wsdbase-iwsdhttpmessageparameters)