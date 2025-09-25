# IX509EnrollmentHelper::AddPolicyServer

## Description

The **AddPolicyServer** method registers a certificate enrollment policy (CEP) server and saves CEP access credentials in the credential cache. This method is web enabled.

## Parameters

### `strEnrollmentPolicyServerURI` [in]

A **BSTR** that contains the certificate enrollment policy server URL.

### `strEnrollmentPolicyID` [in]

A **BSTR** that contains the certificate enrollment policy server ID. The ID can be any string. It is set by the administrator who installs the CEP server.

### `EnrollmentPolicyServerFlags` [in]

A [PolicyServerUrlFlags](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-policyserverurlflags) enumeration value. For the **AddPolicyServer** function, you can specify a bitwise **OR** of the following values.

| Value | Meaning |
| --- | --- |
| **PsfAutoEnrollmentEnabled** | Automatic certificate enrollment is enabled. |
| **PsfAllowUnTrustedCA** | Specifies that the certificate of the issuing CA need not be trusted by the client to install a certificate signed by the CA. |

### `authFlags` [in]

An [X509EnrollmentAuthFlags](https://learn.microsoft.com/windows/desktop/api/certcli/ne-certcli-x509enrollmentauthflags) enumeration value that specifies the client authentication type. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **X509AuthAnonymous** | Anonymous authentication. Set the *strCredential* and *strPassword* parameters to **NULL**. |
| **X509AuthKerberos** | Kerberos authentication. Set the *strCredential* and *strPassword* parameters to **NULL**. |
| **X509AuthUsername** | Clear text user name and password authentication. Set the *strCredential* and *strPassword* parameters to the user name and associated password. These strings are encrypted before transmission and are stored securely in the credential vault on the CEP server. |
| **X509AuthCertificate** | Client authentication certificate installed on the local computer and used by the server to verify the identity of the client. Set the *strPassword* parameter to **NULL** and set the certificate thumbprint, a 20-byte SHA1 hash of the certificate, in the *strCredential* parameter. |

### `strCredential` [in]

A **BSTR** that contains the credential.

### `strPassword` [in]

A **BSTR** that contains a clear text password.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The *strEnrollmentPolicyServerURI*, *strCredential*, or *strPassword* parameters cannot be **NULL** or empty. |
| **HRESULT_FROM_WIN32(ERROR_ARITHMETIC_OVERFLOW)** | The *strPassword*, *strCredential*, or *strEnrollmentServerURI* parameters exceed 64,000 characters or contain embedded null characters. |

## Remarks

The *strCredential* and *strPassword* arguments change depending on the value specified in the *authFlags* argument as shown in the following table.

| *flag* parameter | *strCredential* parameter | *strPassword* parameter |
| --- | --- | --- |
| X509AuthAnonymous | **NULL** | **NULL** |
| X509AuthKerberos | **NULL** | **NULL** |
| X509AuthUsername | Clear text user name recognized by the CEP server. | Clear text password associated with the user name. |
| X509AuthCertificate | Contains a 20 byte SHA-1 hash (thumbprint) of the certificate. | **NULL** |

## See also

[IX509EnrollmentHelper](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollmenthelper)