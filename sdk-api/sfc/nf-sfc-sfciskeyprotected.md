# SfcIsKeyProtected function

## Description

Determines whether the specified registry key is protected. Applications should avoid replacing protected registry keys.

## Parameters

### `KeyHandle` [in]

A handle to the root registry key. This must be a handle to one of the following [predefined keys](https://learn.microsoft.com/windows/desktop/SysInfo/predefined-keys).

HKEY_CLASSES_ROOT

HKEY_CURRENT_USER

HKEY_LOCAL_MACHINE

HKEY_USERS

### `SubKeyName` [in, optional]

A **null**-terminated string value containing the name of the subkey. This key must a subkey of the key identified by the *hKey* parameter. For more information about key names, see [Structure of the Registry](https://learn.microsoft.com/windows/desktop/SysInfo/structure-of-the-registry).
If this parameter is **NULL**, the function only checks whether the root registry key is protected.

### `KeySam` [in]

A constant that specifies the alternate registry view that should be used by applications that run on 64-bit Windows. This flag is ignored on the x86 platform. For more information, see [Accessing an Alternate Registry View](https://learn.microsoft.com/windows/desktop/WinProg64/accessing-an-alternate-registry-view).

| Value | Meaning |
| --- | --- |
| 0x0000 | Use the 32-bit registry key from 32-bit applications and use the 64-bit registry key from 64-bit applications. |
| **KEY_WOW64_64KEY**<br><br>0x0100 | Use the 64-bit registry key from either a 32-bit or 64-bit application. |
| **KEY_WOW64_32KEY**<br><br>0x0200 | Use the 32-bit registry key from either a 32-bit or 64-bit application. |

## Return value

If the key is protected, the return value is a nonzero value.

If the key is not protected, the return value is zero.

## Remarks

A key is protected by WRP if the path exists and is protected by WRP. The **SfcIsKeyProtected** function indicates that a subkey is protected by WRP if the subkey has a parent key that is protected by WRP.

For example, if the following registry key exists on the system and is protected by WRP:

```
HKEY_LOCAL_MACHINE
   SOFTWARE
      Classes
         Microsoft
            <WinFeature>
```

The **SfcIsKeyProtected** function returns a nonzero value for the following subkey. The new subkey does not need to exist for the function to determine that it is WRP-protected.

```
HKEY_LOCAL_MACHINE
   SOFTWARE
      Classes
         Microsoft
            <WinFeature>
               <new subkey>
```

## See also

[SfcIsFileProtected](https://learn.microsoft.com/windows/desktop/api/sfc/nf-sfc-sfcisfileprotected)