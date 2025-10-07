# SIGNER\_ATTR\_AUTHCODE structure

The **SIGNER\_ATTR\_AUTHCODE** structure specifies attributes for an [*Authenticode*](https://learn.microsoft.com/windows/win32/secgloss/a-gly) signature.

> [!Note]
> This structure is not defined in any header file. To use this structure, you must define it yourself as shown in this topic.

## Members

**cbSize**

The size, in bytes, of the structure.

**fCommercial**

**TRUE** to sign the subject as a commercial publisher; otherwise, **FALSE**.

**fIndividual**

**TRUE** to sign the subject as an individual publisher; otherwise, **FALSE**.

**pwszName**

The display name of the file upon download.

**pwszInfo**

The display name of the URL of the file upon download.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |

## See also

[**SIGNER\_SIGNATURE\_INFO**](https://learn.microsoft.com/windows/win32/seccrypto/signer-signature-info)

