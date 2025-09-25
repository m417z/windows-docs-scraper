# ICertPropertyEnrollmentPolicyServer::Initialize

## Description

The **Initialize** method initializes an [ICertPropertyEnrollmentPolicyServer](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertyenrollmentpolicyserver) object.

## Parameters

### `PropertyFlags` [in]

An [EnrollmentPolicyServerPropertyFlags](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-enrollmentpolicyserverpropertyflags) enumeration value that specifies the default certificate enrollment policy (CEP) server. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **DefaultNone** | No default policy server URL has been specified. |
| **DefaultPolicyServer** | The policy server URL returned by [GetPolicyServerUrl](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertpropertyenrollmentpolicyserver-getpolicyserverurl) is the default value when an URL has not been specified. |

### `AuthFlags` [in]

An [X509EnrollmentAuthFlags](https://learn.microsoft.com/windows/desktop/api/certcli/ne-certcli-x509enrollmentauthflags) enumeration value that specifies the authentication type used by the client to authenticate itself to the CEP server. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **X509AuthAnonymous** | Anonymous authentication. |
| **X509AuthKerberos** | Kerberos authentication. |
| **X509AuthUsername** | Clear text user name and password authentication.<br><br>**Note** The user name and password are encrypted before transmission and are stored securely in the credential vault on the server. |
| **X509AuthCertificate** | Client authentication certificate installed on the local computer and used by the server to verify the identity of the client. |

### `EnrollmentServerAuthFlags` [in]

An [X509EnrollmentAuthFlags](https://learn.microsoft.com/windows/desktop/api/certcli/ne-certcli-x509enrollmentauthflags) enumeration value that specifies the authentication type used by the client to authenticate itself to the CES. See the *AuthFlags* parameter for the possible values of the enumeration type. For Windows 7, only **X509AuthCertificate** can be specified.

### `UrlFlags` [in]

A [PolicyServerUrlFlags](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-policyserverurlflags) enumeration value that specifies policy server flags. This can be a bitwise **OR** of the following values.

| Value | Meaning |
| --- | --- |
| **PsfNone** | No flags are specified. |
| **PsfLocationGroupPolicy** | The policy server URL is specified in group policy by an administrator. |
| **PsfLocationRegistry** | The policy server URL is specified in the registry. |
| **PsfUseClientId** | Specifies that certificate enrollments and renewals include client specific data in a **ClientId** attribute. Examples include the name of the cryptographic service provider, the Windows version number, the user name, the computer DNS name, and the domain controller DNS name.<br><br>This flag has been included to address privacy concerns that can arise during enrollment to servers that are managed by administrators other than those who manage the forest in which the user resides. By not setting this flag, you can prevent sending personal information to non-local administrators. |
| **PsfAutoEnrollmentEnabled** | Automatic certificate enrollment is enabled. |
| **PsfAllowUnTrustedCA** | Specifies that the certificate of the issuing CA need not be trusted by the client to install a certificate signed by the CA. |

### `strRequestId` [in]

 A **BSTR** variable that contains a unique string identifier for the certificate request to be sent to the certification authority during enrollment. The string can contain any information that uniquely identifies the request.

### `strUrl` [in]

 A **BSTR** variable that contains the URL for the certificate enrollment policy (CEP) server.

### `strId` [in]

A **BSTR** variable that contains the ID of the CEP server.

### `strEnrollmentServerUrl` [in]

A **BSTR** variable that contains the URL for the certificate enrollment server.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | There was insufficient memory available to a string value. |

## See also

[ICertPropertyEnrollmentPolicyServer](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertyenrollmentpolicyserver)