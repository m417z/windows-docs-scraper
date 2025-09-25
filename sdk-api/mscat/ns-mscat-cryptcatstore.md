# CRYPTCATSTORE structure

## Description

[The **CRYPTCATSTORE** structure is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

 The **CRYPTCATSTORE** structure represents a catalog file. The [CryptCATStoreFromHandle](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatstorefromhandle) function populates this structure by using the handle returned by [CryptCATOpen](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatopen).

## Members

### `cbStruct`

The size, in bytes, of this structure.

### `dwPublicVersion`

A value that specifies the "PublicVersion" of the catalog file.

### `pwszP7File`

A pointer to a null-terminated string that contains the name of the catalog file. This member must be initialized before a call to the [CryptCATPersistStore](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatpersiststore) function.

### `hProv`

A handle to the [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP).

### `dwEncodingType`

A value that specifies the encoding type used for the file. Currently, only X509_ASN_ENCODING and PKCS_7_ASN_ENCODING are being used; however, additional encoding types may be added in the future. For either current encoding type, use: X509_ASN_ENCODING | PKCS_7_ASN_ENCODING.

### `fdwStoreFlags`

A bitwise combination of the following values.

| Value | Meaning |
| --- | --- |
| **CRYPTCAT_OPEN_EXCLUDE_PAGE_HASHES**<br><br>0x00010000 | Exclude page hashes in SPC_INDIRECT_DATA. |
| **CRYPTCAT_OPEN_FLAGS_MASK**<br><br>0xffff0000 | For all flags with a value in the upper word, set or clear the flag. |
| **CRYPTCAT_OPEN_INCLUDE_PAGE_HASHES**<br><br>0x00020000 | Include page hashes in SPC_INDIRECT_DATA. The **CRYPTCAT_OPEN_EXCLUDE_PAGE_HASHES** flag takes precedence if it is also set. |
| **CRYPTCAT_OPEN_NO_CONTENT_HCRYPTMSG**<br><br>0x20000000 | Open the file for decoding without detached content. |
| **CRYPTCAT_OPEN_SORTED**<br><br>0x40000000 | Open the catalog with the entries sorted alphabetically by subject. |
| **CRYPTCAT_OPEN_VERIFYSIGHASH**<br><br>0x10000000 | Verify the signature hash but not the certificate chain. |

### `hReserved`

This member is reserved and must be **NULL**.

### `hAttrs`

This member is reserved and must be **NULL**.

### `hCryptMsg`

A handle to the decoded bytes. This member is only set if the file was opened with the **CRYPTCAT_OPEN_NO_CONTENT_HCRYPTMSG** flag set.

### `hSorted`

This member is reserved and must be **NULL**.