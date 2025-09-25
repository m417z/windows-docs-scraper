# IOCSPAdmin::GetSigningCertificates

## Description

The **GetSigningCertificates** method gets the signing certificates that are available on a responder server for a given [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA) certificate. This method only returns signing certificates from the **CERT_SYSTEM_STORE_LOCAL_MACHINE** system store for the specified server.

## Parameters

### `bstrServerName` [in]

A string that contains the responder-server name.

### `pCACertVar` [in]

The CA certificate for which to retrieve signing certificates.

### `pVal` [out]

## Return value

### C++

If the method succeeds, it returns **S_OK**.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

The available signing certificates.

## Remarks

Each signing certificate has the following properties:

* Signed by the CA specified by the *pCACertVar* parameter
* Includes the Online Certificate Status Protocol (OCSP) signing (**XCN_OID_PKIX_KP_OCSP_SIGNING**) extension
* Has not expired
* Responder server can access the certificate private key

## See also

[IOCSPAdmin](https://learn.microsoft.com/windows/desktop/api/certadm/nn-certadm-iocspadmin)