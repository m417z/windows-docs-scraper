# SIGNER\_SUBJECT\_INFO structure

The **SIGNER\_SUBJECT\_INFO** structure specifies a subject to sign.

> [!Note]
> This structure is not defined in any header file. To use this structure, you must define it yourself as shown in this topic.

## Members

**cbSize**

The size, in bytes, of the structure.

**pdwIndex**

This member is reserved. It must be set to zero.

**dwSubjectChoice**

Specifies whether the subject is a file or a [*BLOB*](https://learn.microsoft.com/windows/win32/secgloss/b-gly). This member can be one or more of the following values.

| Value | Meaning |
|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-----------------------------------|
| **SIGNER\_SUBJECT\_BLOB**<br>2 (0x2) | The subject is a BLOB.<br> |
| **SIGNER\_SUBJECT\_FILE**<br>1 (0x1) | The subject is a file.<br> |

**pSignerFileInfo**

A pointer to a [**SIGNER\_FILE\_INFO**](https://learn.microsoft.com/windows/win32/seccrypto/signer-file-info) structure that specifies the file to sign.

**pSignerBlobInfo**

A pointer to a [**SIGNER\_BLOB\_INFO**](https://learn.microsoft.com/windows/win32/seccrypto/signer-blob-info) structure that specifies the BLOB to sign.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |

## See also

[**SignerSign**](https://learn.microsoft.com/windows/win32/seccrypto/signersign)

[**SignerSignEx**](https://learn.microsoft.com/windows/win32/seccrypto/signersignex)

