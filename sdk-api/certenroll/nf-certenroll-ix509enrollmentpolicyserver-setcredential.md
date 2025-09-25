# IX509EnrollmentPolicyServer::SetCredential

## Description

The **SetCredential** method sets the credential used to contact the certificate enrollment policy (CEP) server.

## Parameters

### `hWndParent` [in]

Parent window handle.

### `flag` [in]

An [X509EnrollmentAuthFlags](https://learn.microsoft.com/windows/desktop/api/certcli/ne-certcli-x509enrollmentauthflags) enumeration value that specifies the authentication type. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **X509AuthAnonymous** | Anonymous authentication. Set the *strCredential* and *strPassword* parameters to **NULL**. |
| **X509AuthKerberos** | Kerberos authentication. Set the *strCredential* and *strPassword* parameters to **NULL**. |
| **X509AuthUsername** | Clear text user name and password authentication. Set the *strCredential* and *strPassword* parameters to the user name and associated password. These strings are encrypted before transmission and are stored securely in the credential vault on the CEP server. |
| **X509AuthCertificate** | Client authentication certificate installed on the local computer and used by the server to verify the identity of the client. Set the *strPassword* parameter to **NULL** and set the certificate thumbprint, a 20-byte SHA1 hash of the certificate, in the *strCredential* parameter. |

### `strCredential` [in]

A **BSTR** variable that contains the credential.

### `strPassword` [in]

A **BSTR** variable that contains the password.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The *flag* parameter is not a supported value. |

## Remarks

The *strCredential* and *strPassword* arguments will change depending on the value specified in the *flag* argument as shown in the following table.

| *flag* parameter | *strCredential* parameter | *strPassword* parameter |
| --- | --- | --- |
| X509AuthAnonymous | **NULL** | **NULL** |
| X509AuthKerberos | **NULL** | **NULL** |
| X509AuthUsername | Clear text user name recognized by the CEP server. | Clear text password associated with the user name. |
| X509AuthCertificate | Contains a 20 byte SHA-1 hash (thumbprint) of the certificate. | **NULL** |

## See also

[IX509EnrollmentPolicyServer](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollmentpolicyserver)