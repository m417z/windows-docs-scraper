# IEnroll::createPKCS10WStr

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **createPKCS10WStr** method creates a base64-encoded PKCS #10 [certificate request](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). This method was first defined in the [IEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll) interface.

 This base64-encoded PKCS #10 certificate request (in **BSTR** form) can be submitted to a [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) to request that a certificate be issued to the person or entity whose information it contains.

## Parameters

### `DNName` [in]

A null-terminated Unicode string that contains the distinguished name (DN) of the entity for which the request is being made. In this parameter, the DN name must follow the [X.500](https://learn.microsoft.com/windows/desktop/SecGloss/x-gly) naming convention. For example "CN=User, O=Microsoft". If a two-letter prefix does not exist, an [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) may be provided instead.

### `Usage` [in]

A null-terminated Unicode string that contains an OID that describes the purpose of the certificate being generated. For example, Individual or Commercial Authenticode certificate, or Client Authentication. You can also specify multiple OIDs separated by a comma.

The OID is passed through to the PKCS #10 request. For general extensibility and ease of understanding, the control does not attempt to understand specific-purpose OIDs. Therefore if you specify a Client Authentication OID, the generated key will still be a signature key, not an [exchange key](https://learn.microsoft.com/windows/desktop/SecGloss/e-gly).

### `pPkcs10Blob` [out]

A pointer to a [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) that receives the base64-encoded PKCS10 certificate request.

When you have finished using this memory, free it by passing the **pbData** member of this structure to the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function.

## Return value

 If the method succeeds, the method returns S_OK and *pPkcs10Blob* contains a base64-encoded PKCS #10 request that can be directly posted to a web server for processing.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

By default, the Microsoft Base Cryptographic Provider is used, PROV_RSA_FULL is the provider type, a signature key is created, and a unique new key set is created.

## See also

[IEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4)