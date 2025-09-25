# ICertPropertyEnrollmentPolicyServer::GetAuthentication

## Description

The **GetAuthentication** method retrieves a value that specifies the type of authentication used by the certificate enrollment policy (CEP) server to authenticate a client. This value is set by the [Initialize](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertpropertyenrollmentpolicyserver-initialize) method.

## Parameters

### `pValue` [out, retval]

An [X509EnrollmentAuthFlags](https://learn.microsoft.com/windows/desktop/api/certcli/ne-certcli-x509enrollmentauthflags) enumeration value that specifies the client authentication type. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **X509AuthAnonymous** | Anonymous authentication. |
| **X509AuthKerberos** | Kerberos authentication. |
| **X509AuthUsername** | Clear text user name and password authentication.<br><br>**Note** The user name and password are encrypted before transmission and are stored securely in the credential vault on the CEP server. |
| **X509AuthCertificate** | Client authentication certificate installed on the local computer and used by the server to verify the identity of the client. |

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code/value | Description |
| --- | --- |
| ****E_POINTER**** | The *pValue* parameter cannot be **NULL**. |

## See also

[ICertPropertyEnrollmentPolicyServer](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertyenrollmentpolicyserver)