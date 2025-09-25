# CertModifyCertificatesToTrust function

## Description

The **CertModifyCertificatesToTrust** function modifies the set of certificates in a certificate trust list (CTL) for a given purpose.

**Note** This function has no associated import library. You must use the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to CryptDlg.dll.

## Parameters

### `cCerts` [in]

The number of modification requests that are in the *rgCerts* parameter.

### `rgCerts` [in]

A pointer to a [CTL_MODIFY_REQUEST](https://learn.microsoft.com/windows/desktop/api/cryptdlg/ns-cryptdlg-ctl_modify_request) structure that contains an array of modification requests.

### `szPurpose` [in]

A pointer to a null-terminated string that contains the string representation of an object identifier (OID). The OID specifies the enhanced key usage (EKU) of the CTL to be modified.

### `hwnd` [in]

A handle to the parent window of the dialog boxes that this function generates.

### `hcertstoreTrust` [in, optional]

A handle to the certificate store in which to modify the list of trusted certificates. If **NULL**, the Trusted People store is used with the Current User location.

### `pccertSigner` [in, optional]

A pointer to a [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure that contains a certificate. It is used to sign the trust list. The certificate also restricts the set of trust lists that may be modified. If **NULL**, the trust list is not signed.

## Return value

An **HRESULT**. A value of S_OK indicates success.

## See also

[CTL_MODIFY_REQUEST](https://learn.microsoft.com/windows/desktop/api/cryptdlg/ns-cryptdlg-ctl_modify_request)