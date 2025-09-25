# CERT_SELECTUI_INPUT structure

## Description

The **CERT_SELECTUI_INPUT** structure is used by the [CertSelectionGetSerializedBlob](https://learn.microsoft.com/windows/desktop/api/cryptuiapi/nf-cryptuiapi-certselectiongetserializedblob) function to serialize the certificates contained in a store or an array of certificate chains. The returned serialized [BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly) can be passed to the [CredUIPromptForWindowsCredentials](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-creduipromptforwindowscredentialsa) function.

## Members

### `hStore`

The handle of a certificate store created by the caller. The store contains the set of application preselected certificates.

### `prgpChain`

An array of pointers to [CERT_CHAIN_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_chain_context) structures. Applications provision this array by preselecting certificate chains using the [CertSelectCertificateChains](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certselectcertificatechains) function.

### `cChain`

The number of [CERT_CHAIN_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_chain_context) structures that are in the array pointed to by the **prgpChain** member.