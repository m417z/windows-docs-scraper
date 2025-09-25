# CertSaveStore function

## Description

The **CertSaveStore** function saves the [certificate store](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) to a file or to a memory [BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly).

## Parameters

### `hCertStore` [in]

The handle of the certificate store to be saved.

### `dwEncodingType` [in]

Specifies the [certificate encoding type](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) and [message encoding type](https://learn.microsoft.com/windows/desktop/SecGloss/m-gly). Encoding is used only when *dwSaveAs* contains **CERT_STORE_SAVE_AS_PKCS7**. Otherwise, the *dwMsgAndCertEncodingType* parameter is not used.

This parameter can be a combination of one or more of the following values.

| Value | Meaning |
| --- | --- |
| **PKCS_7_ASN_ENCODING**<br><br>65536 (0x10000) | Specifies PKCS 7 message encoding. |
| **X509_ASN_ENCODING**<br><br>1 (0x1) | Specifies X.509 certificate encoding. |

### `dwSaveAs` [in]

Specifies how to save the certificate store.

This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CERT_STORE_SAVE_AS_PKCS7**<br><br>2 | The certificate store can be saved as a [PKCS #7](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) signed message that does not include additional properties. The *dwEncodingType* parameter specifies the message encoding type. |
| **CERT_STORE_SAVE_AS_STORE**<br><br>1 | The certificate store can be saved as a serialized store containing properties in addition to encoded certificates, [certificate revocation lists](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CRLs), and [certificate trust lists](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CTLs). The *dwEncodingType* parameter is ignored.<br><br>**Note** The **CERT_KEY_CONTEXT_PROP_ID** property and the related **CERT_KEY_PROV_HANDLE_PROP_ID** and **CERT_KEY_SPEC_PROP_ID** values are not saved to a serialized store. |

### `dwSaveTo` [in]

Specifies where and how to save the certificate store. The contents of this parameter determines the format of the *pvSaveToPara* parameter.

This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CERT_STORE_SAVE_TO_FILE**<br><br>1 | The function saves the certificate store to a file. The *pvSaveToPara* parameter contains a handle to a file previously obtained by using the [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function. The file must be opened with write permission. After a successful save operation, the file pointer is positioned after the last write operation. |
| **CERT_STORE_SAVE_TO_FILENAME**<br><br>4 | The function saves the certificate store to a file. The *pvSaveToPara* parameter contains a pointer to a null-terminated Unicode string that contains the path and file name of the file to save to. The function opens the file, saves to it, and closes it. |
| **CERT_STORE_SAVE_TO_FILENAME_A**<br><br>3 | The function saves the certificate store to a file. The *pvSaveToPara* parameter contains a pointer to a null-terminated ANSI string that contains the path and file name of the file to save to. The function opens the file, saves to it, and closes it. |
| **CERT_STORE_SAVE_TO_FILENAME_W**<br><br>4 | The function saves the certificate store to a file. The *pvSaveToPara* parameter contains a pointer to a null-terminated Unicode string that contains the path and file name of the file to save to. The function opens the file, saves to it, and closes it. |
| **CERT_STORE_SAVE_TO_MEMORY**<br><br>2 | The function saves the certificate store to a memory BLOB. The *pvSaveToPara* parameter contains a pointer to a [CERT_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure. Before use, the **CERT_BLOB**'s **pbData** and **cbData** members must be initialized. Upon return, **cbData** is updated with the actual length. For a length-only calculation, **pbData** must be set to **NULL**. If **pbData** is non-**NULL** and **cbData** is not large enough, the function returns zero with a last error code of **ERROR_MORE_DATA**. |

### `pvSaveToPara` [in, out]

A pointer that represents where the store should be saved to. The contents of this parameter depends on the value of the *dwSaveTo* parameter.

### `dwFlags` [in]

This parameter is reserved for future use and must be set to zero.

## Return value

If the function succeeds, the function returns nonzero.

If the function fails, it returns zero. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

Note that [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) or [WriteFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefile) errors can be propagated to this function. One possible error code is **CRYPT_E_FILE_ERROR** which indicates that an error occurred while writing to the file.

## See also

[CertCloseStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certclosestore)

[CertOpenStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certopenstore)

[Certificate Store Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)

[WriteFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefile)