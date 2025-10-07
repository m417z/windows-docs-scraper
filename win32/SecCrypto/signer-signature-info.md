# SIGNER\_SIGNATURE\_INFO structure

The **SIGNER\_SIGNATURE\_INFO** structure contains information about a digital signature.

> [!Note]
> This structure is not defined in any header file. To use this structure, you must define it yourself as shown in this topic.

## Members

**cbSize**

The size, in bytes, of the structure.

**algidHash**

The hash algorithm used for the digital signature.

**dwAttrChoice**

Specifies whether the signature has [*Authenticode*](https://learn.microsoft.com/windows/win32/secgloss/a-gly) attributes. This member can be one or more of the following values.

| Value | Meaning |
|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------|
|

**SIGNER\_AUTHCODE\_ATTR**

1

| The signature has [*Authenticode*](https://learn.microsoft.com/windows/win32/secgloss/a-gly) attributes.<br> |
|

**SIGNER\_NO\_ATTR**

0

| The signature does not have [*Authenticode*](https://learn.microsoft.com/windows/win32/secgloss/a-gly) attributes.<br> |

**pAttrAuthcode**

Specifies attributes for an [*Authenticode*](https://learn.microsoft.com/windows/win32/secgloss/a-gly) signature. This member is required if the value of the **dwAttrChoice** member is **SIGNER\_AUTHCODE\_ATTR**.

**psAuthenticated**

Authenticated user-supplied attributes added to the digital signature.

**psUnauthenticated**

Unauthenticated user-supplied attributes added to the digital signature.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |

## See also

[**SignerSign**](https://learn.microsoft.com/windows/win32/seccrypto/signersign)

[**SignerSignEx**](https://learn.microsoft.com/windows/win32/seccrypto/signersignex)

