# KEYSVC\_BLOB structure

The **KEYSVC\_BLOB** structure defines a key service BLOB. This structure is used by the [**RKeyPFXInstall**](https://learn.microsoft.com/windows/win32/seccrypto/rkeypfxinstall) function.

## Members

**cb**

A **ULONG** value that specifies the size, in bytes, of **pb**.

**pb**

A pointer to a **BYTE** that contains the BLOB, in [*PKCS \#12*](https://learn.microsoft.com/windows/win32/secgloss/p-gly) format.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------|
| Minimum supported client<br> | None supported<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| Header<br> | Rkeysvcc.h |

## See also

[**RKeyPFXInstall**](https://learn.microsoft.com/windows/win32/seccrypto/rkeypfxinstall)

[**KEYSVC\_UNICODE\_STRING**](https://learn.microsoft.com/windows/win32/seccrypto/keysvc-unicode-string)

