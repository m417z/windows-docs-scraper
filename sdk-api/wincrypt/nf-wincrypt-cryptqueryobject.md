# CryptQueryObject function

## Description

**Important** This API is deprecated. New and existing software should start using [Cryptography Next Generation APIs.](https://learn.microsoft.com/windows/desktop/SecCNG/cng-portal) Microsoft may remove this API in future releases.

The **CryptQueryObject** function retrieves information about the contents of a cryptography API object, such as a [certificate](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly), a [certificate revocation list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly), or a [certificate trust list](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). The object can either reside in a structure in memory or be contained in a file.

## Parameters

### `dwObjectType` [in]

Indicates the type of the object to be queried. This must be one of the following values.

| Value | Meaning |
| --- | --- |
| **CERT_QUERY_OBJECT_BLOB** | The object is stored in a structure in memory. |
| **CERT_QUERY_OBJECT_FILE** | The object is stored in a file. |

### `pvObject` [in]

A pointer to the object to be queried.
The type of data pointer depends on the contents of the *dwObjectType* parameter.

| *dwObjectType* value | Meaning |
| --- | --- |
| **CERT_QUERY_OBJECT_BLOB** | This parameter is a pointer to a [CERT_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)), or similar, structure that contains the object to query. |
| **CERT_QUERY_OBJECT_FILE** | This parameter is a pointer to a null-terminated Unicode string that contains the path and name of the file to query. |

### `dwExpectedContentTypeFlags` [in]

Indicates the expected content type. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CERT_QUERY_CONTENT_FLAG_ALL** | The content can be any type. This does not include the **CERT_QUERY_CONTENT_FLAG_PFX_AND_LOAD** flag.<br><br>If this flag is specified, this function will attempt to obtain information about the object, trying different content types until the proper content type is found or the content types are exhausted. This is obviously inefficient, so this flag should only be used if the content type is not known. |
| **CERT_QUERY_CONTENT_FLAG_CERT** | The content is a single certificate. |
| **CERT_QUERY_CONTENT_FLAG_CERT_PAIR** | The content is an [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) encoded X509_CERT_PAIR (an encoded certificate pair that contains either forward, reverse, or forward and reverse cross certificates). |
| **CERT_QUERY_CONTENT_FLAG_CRL** | The content is a single CRL. |
| **CERT_QUERY_CONTENT_FLAG_CTL** | The content is a single CTL. |
| **CERT_QUERY_CONTENT_FLAG_PFX** | The content is a PFX ([PKCS #12](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly)) packet, but it will not be loaded by this function. You can use the [PFXImportCertStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-pfximportcertstore) function to load this into a store. |
| **CERT_QUERY_CONTENT_FLAG_PFX_AND_LOAD** | The content is a PFX ([PKCS #12](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly)) packet and will be loaded by this function subject to the conditions specified in the following note.<br><br>**Note**<br><br>If the PFX packet contains an embedded password that is not an empty string or **NULL**, and the password was not protected to an Active Directory (AD) principal that includes the calling user, this function will not be able to decrypt the PFX packet. The packet can be decrypted, however, if the password used when the PFX packet was created was encrypted to an AD principal and the user, as part of that principal, has permission to decrypt the password. For more information, see the *pvPara* parameter and the **PKCS12_PROTECT_TO_DOMAIN_SIDS** flag of the [PFXExportCertStoreEx](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-pfxexportcertstoreex) function.<br><br>You can protect PFX passwords to an AD principal beginning in Windows 8 and Windows Server 2012.<br><br>**Windows Server 2003 and Windows XP:** This value is not supported. |
| **CERT_QUERY_CONTENT_FLAG_PKCS7_SIGNED** | The content is a PKCS #7 signed message. |
| **CERT_QUERY_CONTENT_FLAG_PKCS7_SIGNED_EMBED** | The content is an embedded PKCS #7 signed message. |
| **CERT_QUERY_CONTENT_FLAG_PKCS7_UNSIGNED** | The content is a PKCS #7 unsigned message. |
| **CERT_QUERY_CONTENT_FLAG_PKCS10** | The content is a PKCS #10 message. |
| **CERT_QUERY_CONTENT_FLAG_SERIALIZED_CERT** | The content is a serialized single certificate. |
| **CERT_QUERY_CONTENT_FLAG_SERIALIZED_CRL** | The content is a serialized single CRL. |
| **CERT_QUERY_CONTENT_FLAG_SERIALIZED_CTL** | The content is serialized single CTL. |
| **CERT_QUERY_CONTENT_FLAG_SERIALIZED_STORE** | The content is a serialized store. |

### `dwExpectedFormatTypeFlags` [in]

Indicates the expected format of the returned type. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CERT_QUERY_FORMAT_FLAG_ALL** | The content can be returned in any format. |
| **CERT_QUERY_FORMAT_FLAG_ASN_ASCII_HEX_ENCODED** | The content should be returned in [ASCII](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) hex-encoded format with a "{ASN}" prefix. |
| **CERT_QUERY_FORMAT_FLAG_BASE64_ENCODED** | The content should be returned in Base64 encoded format. |
| **CERT_QUERY_FORMAT_FLAG_BINARY** | The content should be returned in binary format. |

### `dwFlags` [in]

This parameter is reserved for future use and must be set to zero.

### `pdwMsgAndCertEncodingType` [out]

A pointer to a **DWORD** value that receives the type of encoding used in the message. If this information is not needed, set this parameter to **NULL**.

This parameter can receives a combination of one or more of the following values.

| Value | Meaning |
| --- | --- |
| **PKCS_7_ASN_ENCODING**<br><br>65536 (0x10000) | Specifies PKCS 7 message encoding. |
| **X509_ASN_ENCODING**<br><br>1 (0x1) | Specifies X.509 certificate encoding. |

### `pdwContentType` [out]

A pointer to a **DWORD** value that receives the actual type of the content. If this information is not needed, set this parameter to **NULL**. The returned content type can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CERT_QUERY_CONTENT_CERT** | The content is a single certificate. |
| **CERT_QUERY_CONTENT_CERT_PAIR** | The content is an ASN.1 encoded X509_CERT_pair. |
| **CERT_QUERY_CONTENT_CRL** | The content is a single CRL. |
| **CERT_QUERY_CONTENT_CTL** | The content is a single CTL. |
| **CERT_QUERY_CONTENT_PFX** | The content is a PFX ([PKCS #12](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly)) packet. This function only verifies that the object is a PKCS #12 packet. The PKCS #12 packet is not loaded into a certificate store. |
| **CERT_QUERY_CONTENT_PFX_AND_LOAD** | The content is a PFX ([PKCS #12](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly)) packet, and it has been loaded into a certificate store.<br><br>**Windows Server 2003 and Windows XP:** This value is not supported. |
| **CERT_QUERY_CONTENT_PKCS7_SIGNED** | The content is a PKCS #7 signed message. |
| **CERT_QUERY_CONTENT_PKCS7_SIGNED_EMBED** | The content is an embedded PKCS #7 signed message. |
| **CERT_QUERY_CONTENT_PKCS7_UNSIGNED** | The content is a PKCS #7 unsigned message. |
| **CERT_QUERY_CONTENT_PKCS10** | The content is a PKCS #10 message. |
| **CERT_QUERY_CONTENT_SERIALIZED_CERT** | The content is a serialized single certificate. |
| **CERT_QUERY_CONTENT_SERIALIZED_CRL** | The content is a serialized single CRL. |
| **CERT_QUERY_CONTENT_SERIALIZED_CTL** | The content is a serialized single CTL. |
| **CERT_QUERY_CONTENT_SERIALIZED_STORE** | The content is a serialized store. |

### `pdwFormatType` [out]

A pointer to a **DWORD** value that receives the actual format type of the content. If this information is not needed, set this parameter to **NULL**. The returned format type can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CERT_QUERY_FORMAT_ASN_ASCII_HEX_ENCODED** | The content is in [ASCII](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) hex-encoded format with an "{ASN}" prefix. |
| **CERT_QUERY_FORMAT_BASE64_ENCODED** | The content is in Base64 encoded format. |
| **CERT_QUERY_FORMAT_BINARY** | The content is in binary format. |

### `phCertStore` [out]

A pointer to an **HCERTSTORE** value that receives a handle to a certificate store that includes all of the certificates, CRLs, and CTLs in the object.

This parameter only receives a certificate store handle when the *dwContentType* parameter receives one of the following values. This parameter receives **NULL** for all other content types.

#### CERT_QUERY_CONTENT_CERT

#### CERT_QUERY_CONTENT_CRL

#### CERT_QUERY_CONTENT_CTL

#### CERT_QUERY_CONTENT_PFX_AND_LOAD

#### CERT_QUERY_CONTENT_PKCS7_SIGNED

#### CERT_QUERY_CONTENT_PKCS7_SIGNED_EMBED

#### CERT_QUERY_CONTENT_SERIALIZED_CERT

#### CERT_QUERY_CONTENT_SERIALIZED_CRL

#### CERT_QUERY_CONTENT_SERIALIZED_CTL

#### CERT_QUERY_CONTENT_SERIALIZED_STORE

When you have finished using the handle, free it by passing the handle to the [CertCloseStore](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certclosestore) function.

If this information is not needed, set this parameter to **NULL**.

### `phMsg` [out]

A pointer to an **HCRYPTMSG** value that receives the handle of an opened message.

This parameter only receives a message handle when the *dwContentType* parameter receives one of the following values. This parameter receives **NULL** for all other content types.

#### CERT_QUERY_CONTENT_PKCS7_SIGNED

#### CERT_QUERY_CONTENT_PKCS7_SIGNED_EMBED

#### CERT_QUERY_CONTENT_PKCS7_UNSIGNED

When you have finished using the handle, free it by passing the handle to the [CryptMsgClose](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptmsgclose) function.

If this information is not needed, set this parameter to **NULL**.

### `ppvContext` [out]

A pointer to a pointer that receives additional information about the object.

The format of this data depends on the value received by the *dwContentType* parameter. The following table lists the format of the data for the specified *dwContentType* value.

| *dwContentType* value | Meaning |
| --- | --- |
| **CERT_QUERY_CONTENT_CERT** | This parameter receives a pointer to a [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure. When you have finished using the structure, free it by passing this pointer to the [CertFreeCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecertificatecontext) function. |
| **CERT_QUERY_CONTENT_CRL** | This parameter receives a pointer to a [CRL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crl_context) structure. When you have finished using the structure, free it by passing this pointer to the [CertFreeCRLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecrlcontext) function. |
| **CERT_QUERY_CONTENT_CTL** | This parameter receives a pointer to a [CTL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_context) structure. When you have finished using the structure, free it by passing this pointer to the [CertFreeCTLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreectlcontext) function. |
| **CERT_QUERY_CONTENT_SERIALIZED_CERT** | This parameter receives a pointer to a [CERT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_context) structure. When you have finished using the structure, free it by passing this pointer to the [CertFreeCertificateContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecertificatecontext) function. |
| **CERT_QUERY_CONTENT_SERIALIZED_CRL** | This parameter receives a pointer to a [CRL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crl_context) structure. When you have finished using the structure, free it by passing this pointer to the [CertFreeCRLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreecrlcontext) function. |
| **CERT_QUERY_CONTENT_SERIALIZED_CTL** | This parameter receives a pointer to a [CTL_CONTEXT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_context) structure. When you have finished using the structure, free it by passing this pointer to the [CertFreeCTLContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-certfreectlcontext) function. |

If this information is not needed, set this parameter to **NULL**.

## Return value

If the function succeeds, the function returns nonzero.

If the function fails, it returns zero. For extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[Data Management Functions](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)