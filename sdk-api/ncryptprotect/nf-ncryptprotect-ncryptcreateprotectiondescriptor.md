# NCryptCreateProtectionDescriptor function

## Description

The **NCryptCreateProtectionDescriptor** function retrieves a handle to a protection descriptor object.

## Parameters

### `pwszDescriptorString` [in]

Null-terminated Unicode string that contains a protection descriptor rule string or a registered display name for the rule.

If you specify the display name and you want this function to look in the registry for the associated protection descriptor rule string, you must set the *dwFlags* parameter to **NCRYPT_NAMED_DESCRIPTOR_FLAG**.

### `dwFlags` [in]

Flag that specifies whether the string in *pwszDescriptorString* represents the display name of a protection descriptor and, if so, where in the registry the function should search for the associated protection rule string. The following value combinations can be set:

* To indicate that the value set in the *pwszDescriptorString* parameter is a complete protection descriptor rule string rather than a display name, set the *dwFlags* parameter to zero (0).
* To indicate that the string is a display name and that it is saved, along with its associated descriptor rule string, in the **HKEY_LOCAL_MACHINE** registry hive, bitwise-OR the **NCRYPT_NAMED_DESCRIPTOR_FLAG** value and the **NCRYPT_MACHINE_KEY_FLAG** value.
* To indicate that the string is a display name and that it is saved, along with its associated descriptor string rule, in the **HKEY_CURRENT_USER** registry hive, set only the **NCRYPT_NAMED_DESCRIPTOR_FLAG** value. That is, there is no unique flag to specify the current user registry hive.

**Note** To associate a descriptor rule with a display name and save both in the registry, call the [NCryptRegisterProtectionDescriptorName](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptregisterprotectiondescriptorname) function.

### `phDescriptor` [out]

Pointer to a protection descriptor object handle.

## Return value

Returns a status code that indicates the success or failure of the function. Possible return codes include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **ERROR_SUCCESS** | The function was successful. |
| **NTE_INVALID_PARAMETER** | The *phDescriptor* parameter cannot be **NULL**.<br><br>The *pwszDescriptorString* parameter cannot be **NULL** and it cannot be an empty sting. |
| **NTE_BAD_FLAGS** | The dwFlags parameter must be **NCRYPT_MACHINE_KEY_FLAG** or **NCRYPT_NAMED_DESCRIPTOR_FLAG**. |
| **NTE_NO_MEMORY** | Memory could not be allocated to retrieve the registered protection descriptor string. |
| **NTE_NOT_FOUND** | The protection descriptor name specified in the *pwszDescriptorString* parameter could not be found. |

## Remarks

The protection descriptor object created by this function is an internal data structure that contains information about the descriptor. You cannot use it directly. Your application can, however, use the returned handle in the following functions:

* [NCryptCloseProtectionDescriptor](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptcloseprotectiondescriptor)
* [NCryptGetProtectionDescriptorInfo](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptgetprotectiondescriptorinfo)
* [NCryptProtectSecret](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptprotectsecret)
* [NCryptProtectSecret](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptprotectsecret)
* [NCryptUnprotectSecret](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptunprotectsecret)
* [NCryptStreamOpenToProtect](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptstreamopentoprotect)

The following examples show protection descriptor rule strings:

* "SID=S-1-5-21-4392301 AND SID=S-1-5-21-3101812"
* "SDDL=O:S-1-5-5-0-290724G:SYD:(A;;CCDC;;;S-1-5-5-0-290724)(A;;DC;;;WD)"
* "LOCAL=user"
* "LOCAL=machine"
* "WEBCREDENTIALS=MyPasswordName"
* "WEBCREDENTIALS=MyPasswordName,myweb.com"

You can use the [NCryptRegisterProtectionDescriptorName](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptregisterprotectiondescriptorname) function to associate a display name with a rule string and save both in the registry.

## See also

[CNG DPAPI Functions](https://learn.microsoft.com/windows/desktop/SecCNG/cng-dpapi-functions)