# ICertRequest3::SetCredential

## Description

The **SetCredential** method sets the credential used to contact the Certificate Enrollment Web Service.

## Parameters

### `hWnd` [in]

A handle to the parent window.

You must set the *hWnd* parameter there is a UI presented to obtain the credential.

For certificate based authorization, the handle is used if a UI prompt is needed to obtain the credential, for example, if the credential is on a smart card and a pin prompt is needed.

When using Kerberos, anonymous, or user name and password authentication, this parameter is ignored.

### `AuthType` [in]

A value of the [X509EnrollmentAuthFlags](https://learn.microsoft.com/windows/desktop/api/certcli/ne-certcli-x509enrollmentauthflags) enumeration that specifies the authentication type.

| Value | Meaning |
| --- | --- |
| **X509AuthAnonymous** | Anonymous authentication.<br><br>Set the *strCredential* and *strPassword* parameters to **NULL** or to empty strings. |
| **X509AuthCertificate** | Client authentication certificate installed on the local computer. The certificate contains a [public key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) that is associated with a [private key](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) (not contained in the [certificate](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly)). The certificate is used by the server to verify the identity of the client.<br><br>The *strCredential* parameter contains a binary 20-byte SHA-1 hash of the certificate to be passed to the Certificate Enrollment Web Service to authenticate the caller. Set the *strPassword* parameter to **NULL** or an empty string. The *strCredential* parameter must refer to a certificate installed in the relevant personal certificate store, and it must have an associated private key that is accessible to the caller. |
| **X509AuthKerberos** | Kerberos authentication.<br><br>Set the *strCredential* and *strPassword* parameters to **NULL** or to empty strings. |
| **X509AuthUsername** | Plaintext user name and password authentication. The user name and password are encrypted when they are stored in the credential vault on the client.<br><br>The *strCredential* and *strPassword* parameters contain a user name string and a plaintext password that are supported by the Certificate Enrollment Web Service to authenticate the caller. Because an enrollment service connection always uses [Secure Sockets Layer protocol](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SSL), the password is encrypted when sent over the wire. |

### `strCredential` [in]

A string that contains the credential.

### `strPassword` [in]

A string that contains the password.

## Return value

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The *AuthType* parameter must be **X509AuthKerberos**. |

## Remarks

The **SetCredential** method must be called prior to calling the [ICertRequest2::Submit](https://learn.microsoft.com/windows/desktop/api/certcli/nf-certcli-icertrequest-submit) method.

The *strCredential* and *strPassword* arguments change depending on the value specified in the *AuthType* parameter as shown in the following table.

| *AuthType* parameter | *strCredential* parameter | *strPassword* parameter |
| --- | --- | --- |
| X509AuthAnonymous | **NULL** | **NULL** |
| X509AuthCertificate | A 20 byte SHA-1 hash (thumbprint) of the certificate | **NULL** |
| X509AuthKerberos | **NULL** | **NULL** |
| X509AuthUsername | A plaintext user name that is recognized by the Certificate Enrollment Web Service | A plaintext password that is associated with the user name |

## See also

[CCertRequest](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertrequest)

[ICertRequest3](https://learn.microsoft.com/windows/desktop/api/certcli/nn-certcli-icertrequest3)