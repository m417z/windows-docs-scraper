# NCRYPT_UI_POLICY structure

## Description

The **NCRYPT_UI_POLICY** structure is used with the [NCRYPT_UI_POLICY_PROPERTY](https://learn.microsoft.com/windows/desktop/SecCNG/key-storage-property-identifiers) property to contain strong key user interface information for a key. This structure is used with the [NCryptSetProperty](https://learn.microsoft.com/windows/desktop/api/ncrypt/nf-ncrypt-ncryptsetproperty) and [NCryptGetProperty](https://learn.microsoft.com/windows/desktop/api/ncrypt/nf-ncrypt-ncryptgetproperty) functions with the [NCRYPT_UI_POLICY_PROPERTY](https://learn.microsoft.com/windows/desktop/SecCNG/key-storage-property-identifiers) property.

## Members

### `dwVersion`

The version number of the structure. This member must contain 1.

### `dwFlags`

A set of flags that provide additional user interface information or requirements.

| Value | Meaning |
| --- | --- |
| **NCRYPT_UI_PROTECT_KEY_FLAG**<br><br>0x00000001 | Display the strong key user interface as needed. |
| **NCRYPT_UI_FORCE_HIGH_PROTECTION_FLAG**<br><br>0x00000002 | Force high protection. |
| **NCRYPT_UI_APPCONTAINER_ACCESS_MEDIUM_FLAG**<br><br>0x00000008 | An app container has accessed a medium key that is not strongly protected. For example, a key that is for user consent only, or is password or fingerprint protected. |

### `pszCreationTitle`

A pointer to a null-terminated Unicode string that contains the text that will be used in the title of the strong key dialog box when the key is completed. If this member is **NULL**, a default creation title will be used in the strong key dialog box. This member is only used on key finalization.

### `pszFriendlyName`

A pointer to a null-terminated Unicode string that contains the text that will be displayed in the strong key dialog box as the name of the key. If this member is **NULL**, a default name will be used in the strong key dialog box. This member is used both when the key is completed and when the key is used.

### `pszDescription`

A pointer to a null-terminated Unicode string that contains the text that will be displayed in the strong key dialog box as the description of the key. If this member is **NULL**, a default description will be used in the strong key dialog box. This member is used both when the key is completed and when the key is used.