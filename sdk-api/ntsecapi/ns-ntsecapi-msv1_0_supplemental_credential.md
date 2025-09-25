# MSV1_0_SUPPLEMENTAL_CREDENTIAL structure

## Description

The **MSV1_0_SUPPLEMENTAL_CREDENTIAL** structure is used to pass [credentials](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) into MSV1_0 from [Kerberos](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly) or custom [authentication package](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly).

## Members

### `Version`

Specifies the version number of the credential structure and related credential content.

### `Flags`

Describes the credential. This can contain one or more of the following values.

| Value | Meaning |
| --- | --- |
| **MSV1_0_CRED_LM_PRESENT** | The credential contains a LAN Manager (LM) password stored in the **LmPassword** member. |
| **MSV1_0_CRED_NT_PRESENT** | The credential contains a Windows password stored in the **NtPassword** member. |
| **MSV1_0_CRED_VERSION** | Version information is included and is stored in the **Version** member. |

### `LmPassword`

Contains the LM password. The size of this array is defined by the constant **MSV1_0_OWF_PASSWORD_LENGTH**. When you have finished using the password, remove the sensitive information from memory by calling [SecureZeroMemory](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa366877(v=vs.85)). For more information on protecting the password, see [Handling Passwords](https://learn.microsoft.com/windows/desktop/SecBP/handling-passwords).

### `NtPassword`

A string that contains the Windows password. The size of this array is defined by the constant **MSV1_0_OWF_PASSWORD_LENGTH**. When you have finished using the password, remove the sensitive information from memory by calling [SecureZeroMemory](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa366877(v=vs.85)).