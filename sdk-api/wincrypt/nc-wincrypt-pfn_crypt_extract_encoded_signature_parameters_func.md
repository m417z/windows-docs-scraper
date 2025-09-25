# PFN_CRYPT_EXTRACT_ENCODED_SIGNATURE_PARAMETERS_FUNC callback function

## Description

If a signature contains encoded parameters, the **PFN_CRYPT_EXTRACT_ENCODED_SIGNATURE_PARAMETERS_FUNC** callback function is called to decode and return the hash algorithm identifier and optionally the signature parameters.

## Parameters

### `dwCertEncodingType` [in]

Specifies the type of encoding used. It is always acceptable to specify both the certificate and [message encoding types](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly) by combining them with a bitwise-**OR** operation as shown in the following example:

X509_ASN_ENCODING | PKCS_7_ASN_ENCODING Currently defined encoding types are:

* X509_ASN_ENCODING
* PKCS_7_ASN_ENCODING

### `pSignatureAlgorithm` [in]

A pointer to a [CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) structure that contains the signature [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) and its optional encoded parameters.

#### - **ppvDecodedSignPara [out, optional]

A pointer to an address for the decoded and allocated signature parameters data structure. Returning the decoded buffer is optional.

### `ppwszCNGHashAlgid` [out]

A pointer to an address for the allocated Unicode string that represents the CNG hash algorithm identifier extracted from the encoded signature parameters. If this function returns **TRUE**, a non-**NULL** pointer must be returned.

### `ppvDecodedSignPara` [out, optional]

A pointer to an address for the decoded and allocated signature parameters data structure. Returning the decoded buffer is optional.

## Return value

If the function succeeds, the function returns nonzero (**TRUE**).

If the function fails, it returns zero (**FALSE**). For extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

If this callback function does not support the signature algorithm, it must return **FALSE** and call [SetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-setlasterror) with **ERROR_NOT_SUPPORTED**.

## Remarks

Memory for the *ppvDecodedSignPara* and *ppwszCNGHashAlgid* parameters must be allocated by using the [LocalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localalloc) function.

You can use [OID Support Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions) to deploy this callback function. Wincrypt.h defines the following constant for this purpose.

| Constant | Definition |
| --- | --- |
| CRYPT_OID_EXTRACT_ENCODED_SIGNATURE_PARAMETERS_FUNC | "CryptDllExtractEncodedSignatureParameters" |