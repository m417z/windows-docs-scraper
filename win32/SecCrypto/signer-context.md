# SIGNER\_CONTEXT structure

The **SIGNER\_CONTEXT** structure contains a signed [*BLOB*](https://learn.microsoft.com/windows/win32/secgloss/b-gly).

> [!Note]
> This structure is not defined in any header file. To use this structure, you must define it yourself as shown in this topic.

## Members

**cbSize**

The size, in bytes, of the structure.

**cbBlob**

The size, in bytes, of the **pbBlob** member.

**pbBlob**

A pointer to the signed BLOB.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |

## See also

[**SignerSign**](https://learn.microsoft.com/windows/win32/seccrypto/signersign)

[**SignerSignEx**](https://learn.microsoft.com/windows/win32/seccrypto/signersignex)

