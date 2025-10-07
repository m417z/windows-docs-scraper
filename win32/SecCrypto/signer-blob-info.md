# SIGNER\_BLOB\_INFO structure

\[The **SIGNER\_BLOB\_INFO** structure is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.\]

The **SIGNER\_BLOB\_INFO** structure specifies a [*BLOB*](https://learn.microsoft.com/windows/win32/secgloss/b-gly) to sign.

> [!Note]
> This structure is not defined in any header file. To use this structure, you must define it yourself as shown in this topic.

## Members

**cbSize**

The size, in bytes, of the structure.

**pGuidSubject**

A pointer to a **GUID** that specifies the Subject Interface Package (SIP) to load.

**cbBlob**

The size, in bytes, of the BLOB to sign.

**pbBlob**

A pointer to the BLOB to sign.

**pwszDisplayName**

The display name of the BLOB. This member can be set to **NULL**.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |

## See also

[**SIGNER\_SUBJECT\_INFO**](https://learn.microsoft.com/windows/win32/seccrypto/signer-subject-info)

