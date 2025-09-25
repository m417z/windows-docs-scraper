# CertSelectionGetSerializedBlob function

## Description

The **CertSelectionGetSerializedBlob** function is a helper function used to retrieve a serialized certificate [BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly) from a [CERT_SELECTUI_INPUT](https://learn.microsoft.com/windows/desktop/api/cryptuiapi/ns-cryptuiapi-cert_selectui_input) structure.

## Parameters

### `pcsi` [in]

A pointer to a [CERT_SELECTUI_INPUT](https://learn.microsoft.com/windows/desktop/api/cryptuiapi/ns-cryptuiapi-cert_selectui_input) structure that contains the certificate store and certificate context chain information.

### `ppOutBuffer` [out]

The address of a pointer to a buffer that receives the serialized certificates BLOB.

### `pulOutBufferSize` [out]

A pointer to a **ULONG** to receive the size, in bytes, of the BLOB received in the buffer pointed to by the *ppOutBuffer* parameter.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. If both **hStore** and **prgpChain** parameters are not **NULL**, return **E_INVALIDARG**. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

The returned serialized BLOB is passed to the [CredUIPromptForWindowsCredentials](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-creduipromptforwindowscredentialsa) function in the *pvInAuthBuffer* parameter to allow a user to select a certificate by using the credential selection UI.

The certificates that are serialized in the BLOB returned in the buffer pointed to by the *ppOutBuffer* parameter of this function are dependent on the values of the **hStore** and **prgpChain** members of the [CERT_SELECTUI_INPUT](https://learn.microsoft.com/windows/desktop/api/cryptuiapi/ns-cryptuiapi-cert_selectui_input) structure.

| **hStore** | **prgpChain** | Certificates serialized |
| --- | --- | --- |
| **NULL** | not **NULL** | The certificates pointed to by the **prgpChain** member are serialized. |
| not **NULL** | **NULL** | The certificates specified by the **hStore** member are serialized. |
| **NULL** | **NULL** | An empty BLOB is returned. |
| not **NULL** | not **NULL** | The call fails and the function returns **E_INVALIDARG**. |