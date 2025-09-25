# IX509EnrollmentPolicyServer::Initialize

## Description

The **Initialize** method initializes an [IX509EnrollmentPolicyServer](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollmentpolicyserver) object.

## Parameters

### `bstrPolicyServerUrl` [in]

A **BSTR** variable that contains the URL for the certificate enrollment policy server.

### `bstrPolicyServerId` [in]

A **BSTR** variable that contains a unique ID for the certificate enrollment policy server. If this value is not **NULL**, it must match the ID string returned by the CEP response.

### `authFlags` [in]

An [X509EnrollmentAuthFlags](https://learn.microsoft.com/windows/desktop/api/certcli/ne-certcli-x509enrollmentauthflags) enumeration value that specifies the client authentication type. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **X509AuthAnonymous** | Anonymous authentication. |
| **X509AuthKerberos** | Kerberos authentication. |
| **X509AuthUsername** | Clear text user name and password authentication.<br><br>**Note** The user name and password are encrypted before transmission and are stored securely in the credential vault on the CEP server. |
| **X509AuthCertificate** | Client authentication certificate installed on the local computer and used by the server to verify the identity of the client. |

### `fIsUnTrusted` [in]

A Boolean value that specifies whether to allow an untrusted certification authority certificates.

### `context` [in]

An [X509CertificateEnrollmentContext](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-x509certificateenrollmentcontext) enumeration value that specifies the nature of the end entity for which certificate enrollment is intended. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **ContextUser** | The certificate is intended for an end user. |
| **ContextMachine** | The certificate is intended for a computer. |
| **ContextAdministratorForceMachine** | The certificate is being requested by an administrator acting on the behalf of a computer. |

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The *bstrPolicyServerUrl* parameter cannot be an empty string and must represent an HTTPS URL. |
| **E_OUTOFMEMORY** | There was not sufficient memory available for the strings specified in the *bstrPolicyServerUrl* or *bstrPolicyServerId* parameters. |
| **HRESULT_FROM_WIN32(ERROR_ALREADY_INITIALIZED)** | The [IX509EnrollmentPolicyServer](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollmentpolicyserver) object has already been initialized. |
| **HRESULT_FROM_WIN32(ERROR_INVALID_DATA)** | The value specified in the *bstrPolicyServerId* parameter is not **NULL** and does not equal the existing CEP ID value on the CEP server. |

## See also

[IX509EnrollmentPolicyServer](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollmentpolicyserver)