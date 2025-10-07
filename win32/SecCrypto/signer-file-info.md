# SIGNER\_FILE\_INFO structure

The **SIGNER\_FILE\_INFO** structure specifies a file to sign.

> [!Note]
> This structure is not defined in any header file. To use this structure, you must define it yourself as shown in this topic.

## Members

**cbSize**

The size, in bytes, of the structure.

**pwszFileName**

A pointer to a null-terminated string that contains the name of the file to sign.

**hFile**

An open handle to the file specified by the **pwszFileName** member. If this member contains a valid handle, this handle is used to access the file. This member can be set to **NULL**.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |

## See also

[**SIGNER\_SUBJECT\_INFO**](https://learn.microsoft.com/windows/win32/seccrypto/signer-subject-info)

