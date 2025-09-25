# IWSDHttpMessageParameters::GetInboundHttpHeaders

## Description

Retrieves the current HTTP headers used for inbound SOAP-over-HTTP transmissions.

## Parameters

### `ppszHeaders` [out]

Pointer used to receive the current HTTP headers in use. Do not deallocate this pointer.

## Return value

This method can return one of these values.

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_INVALIDARG** | *ppszHeaders* is **NULL**. |
| **E_FAIL** | There are no headers available. |

## See also

[IWSDHttpMessageParameters](https://learn.microsoft.com/windows/desktop/api/wsdbase/nn-wsdbase-iwsdhttpmessageparameters)