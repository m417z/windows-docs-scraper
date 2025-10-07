# KEYSVC\_UNICODE\_STRING structure

The **KEYSVC\_UNICODE\_STRING** structure defines a [*Unicode*](https://learn.microsoft.com/windows/win32/secgloss/u-gly) string and a maximum length for the string. This structure is used by the [**RKeyPFXInstall**](https://learn.microsoft.com/windows/win32/seccrypto/rkeypfxinstall) function.

## Members

**Length**

A **USHORT** value that specifies the length, in bytes, used for **Buffer**.

**MaximumLength**

A **USHORT** value that specifies the maximum length, in bytes, allowed for **Buffer**.

**Buffer**

A pointer to a **USHORT** that represents the Unicode string.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------|
| Minimum supported client<br> | None supported<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| Header<br> | Rkeysvcc.h |

## See also

[**RKeyPFXInstall**](https://learn.microsoft.com/windows/win32/seccrypto/rkeypfxinstall)

[**KEYSVC\_BLOB**](https://learn.microsoft.com/windows/win32/seccrypto/keysvc-blob)

