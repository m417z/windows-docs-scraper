# SIP_SUBJECTINFO structure

## Description

The **SIP_SUBJECTINFO** structure specifies subject information data to the [subject interface package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SIP) APIs.

## Members

### `cbSize`

The size, in bytes, of this structure.

### `pgSubjectType`

A pointer to a **GUID** structure that identifies the subject type.

### `hFile`

A file handle that represents the subject. If the storage type of the subject is a file, set *hFile* to **INVALID_HANDLE_VALUE** and set the *pwsFileName* parameter to the name of the file.

### `pwsFileName`

A pointer to a null-terminated Unicode string that contains the file name of the subject.

### `pwsDisplayName`

A pointer to a null-terminated Unicode string that contains the display name of
the subject.

### `dwReserved1`

This member is reserved for future use.

### `dwIntVersion`

This member is reserved. Do not modify this member. It is used by the SIP to pass the internal version number
between get and verify functions.

### `hProv`

An [HCRYPTPROV](https://learn.microsoft.com/windows/desktop/SecCrypto/hcryptprov) handle to the cryptography provider.

### `DigestAlgorithm`

A [CRYPT_ALGORITHM_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_algorithm_identifier) structure that contains the identifier for the [hash](https://learn.microsoft.com/windows/desktop/SecGloss/h-gly) algorithm used to hash the file.

### `dwFlags`

A value that modifies the behavior of the functions that use this structure. For more information about possible values for this member, see the *dwFlags* parameter of [SignerSignEx](https://learn.microsoft.com/windows/desktop/SecCrypto/signersignex).

### `dwEncodingType`

A value that specifies the encoding type used for the file. Currently, only **X509_ASN_ENCODING** and **PKCS_7_ASN_ENCODING** are being used; however, additional encoding types may be added in the future. For either current encoding type, use: **X509_ASN_ENCODING** | **PKCS_7_ASN_ENCODING**.

### `dwReserved2`

This member is reserved for future use.

### `fdwCAPISettings`

This member is not used.

### `fdwSecuritySettings`

This member is not used.

### `dwIndex`

The message index of the last call to **CryptSIPGetSignedDataMsg**. operation.

### `dwUnionChoice`

Specifies the type of additional information provided.

| Defined constant/value | Meaning |
| --- | --- |
| **MSSIP_ADDINFO_NONE**<br><br>0 | There is no additional information about the subject. |
| **MSSIP_ADDINFO_FLAT**<br><br>1 | The additional information is a flat file. |
| **MSSIP_ADDINFO_CATMEMBER**<br><br>2 | The additional information is a catalog member. |
| **MSSIP_ADDINFO_BLOB**<br><br>3 | The additional information is a [BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly). |
| **MSSIP_ADDINFO_NONMSSIP**<br><br>500 | The additional information is in a user defined format. |

### `psFlat`

An [MS_ADDINFO_FLAT](https://learn.microsoft.com/windows/win32/api/mssip/ns-mssip-ms_addinfo_flat) structure that contains additional information for flat file subject types.

### `psCatMember`

An [MS_ADDINFO_CATALOGMEMBER](https://learn.microsoft.com/windows/win32/api/mssip/ns-mssip-ms_addinfo_catalogmember) structure that contains additional information for catalog member subject types.

### `psBlob`

An [MS_ADDINFO_BLOB](https://learn.microsoft.com/windows/win32/api/mssip/ns-mssip-ms_addinfo_blob) structure that contains additional information for BLOB subject types.

### `pClientData`

A pointer to SIP-specific data.

## Remarks

Upon first use of the **SIP_SUBJECTINFO** structure, initialize the entire structure to binary zero. Do not initialize the structure between SIP function calls.

Subjects include, but are not limited to, portable executable images (.exe), cabinet (.cab) images, flat files, and catalog files. Each subject type uses a different subset of its data for hash calculation and requires a different procedure for storage and retrieval. Therefore each subject type has a unique subject interface package specification.