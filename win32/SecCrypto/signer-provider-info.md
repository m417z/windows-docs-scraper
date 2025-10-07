# SIGNER\_PROVIDER\_INFO structure

The **SIGNER\_PROVIDER\_INFO** structure specifies the [*cryptographic service provider*](https://learn.microsoft.com/windows/win32/secgloss/c-gly) (CSP) and private key information used to create a digital signature.

> [!Note]
> This structure is not defined in any header file. To use this structure, you must define it yourself as shown in this topic.

## Members

**cbSize**

The size, in bytes, of the structure.

**pwszProviderName**

The name of the CSP used to create the digital signature. If the value of this member is **NULL**, the default provider is used.

**dwProviderType**

The type of the CSP specified by the **pwszProviderName** member.

**dwKeySpec**

The key specification. If this member is set to zero, the key specification in the **pwszPvkFileName** or **pwszKeyContainer** member is used. If there is more than one key specification in the **pwszKeyContainer** member, **AT\_SIGNATURE** is used. If it fails, **AT\_KEYEXCHANGE** is used.

**dwPvkChoice**

Specifies the type of private key information. This member can be one or more of the following values.

| Value | Meaning |
|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------------------|
| **PVK\_TYPE\_FILE\_NAME**

1 (0x1) | The private key information is a file name.\ | | **PVK\_TYPE\_KEYCONTAINER**

2 (0x2) | The private key information is a key container.\ |

**pwszPvkFileName**

The name of the file that contains the private key information.

**pwszKeyContainer**

The name of the key container that contains the private key information.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |

## See also

[**SignerSign**](https://learn.microsoft.com/windows/win32/seccrypto/signersign)

[**SignerSignEx**](https://learn.microsoft.com/windows/win32/seccrypto/signersignex)

