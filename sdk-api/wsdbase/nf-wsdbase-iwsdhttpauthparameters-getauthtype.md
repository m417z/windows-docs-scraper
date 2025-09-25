# IWSDHttpAuthParameters::GetAuthType

## Description

The **GetAuthType** method retrieves the HTTP authentication scheme used during the authentication of the client.

## Parameters

### `pAuthType`

Pointer to an [HTTP_REQUEST_AUTH_TYPE](https://learn.microsoft.com/windows/desktop/api/http/ne-http-http_request_auth_type) value that indicates the HTTP authentication scheme used during authentication. Possible values include:

| Value | Meaning |
| --- | --- |
| **WSD_SECURITY_HTTP_AUTH_SCHEME_NEGOTIATE**<br><br>0x1 | Negotiate authentication. |
| **WSD_SECURITY_HTTP_AUTH_SCHEME_NTLM**<br><br>0x2 | NTLM authentication. |

## Return value

This method returns S_OK on success.

## See also

[IWSDHttpAuthParameters](https://learn.microsoft.com/windows/desktop/api/wsdbase/nn-wsdbase-iwsdhttpauthparameters)