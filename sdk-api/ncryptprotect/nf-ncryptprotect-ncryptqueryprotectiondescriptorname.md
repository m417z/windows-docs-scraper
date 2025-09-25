# NCryptQueryProtectionDescriptorName function

## Description

The **NCryptQueryProtectionDescriptorName** function retrieves the protection descriptor rule string associated with a registered descriptor display name.

## Parameters

### `pwszName` [in]

The registered display name for the protection descriptor. Register a name by calling the [NCryptRegisterProtectionDescriptorName](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptregisterprotectiondescriptorname) function.

### `pwszDescriptorString` [out]

A null-terminated Unicode string that contains the protection descriptor rule. Set this value to **NULL** and set the size of the descriptor string pointed to by *pcDescriptorString* argument to zero on your initial call to this function. For more information, see Remarks.

### `pcDescriptorString` [in, out]

Pointer to a variable that contains the number of characters in the string retrieved in the *pwszDescriptorString* parameter. Set the variable to zero on your initial call to this function. For more information, see Remarks.

### `dwFlags`

Flag that specifies which registry hive to query for the registered name. This can be zero to look in the **HKEY_CURRENT_USER** hive or you can specify **NCRYPT_MACHINE_KEY_FLAG** to query the **HKEY_LOCAL_MACHINE** hive.

## Return value

Returns a status code that indicates the success or failure of the function. Possible return codes include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **ERROR_SUCCESS** | The function was successful. |
| **NTE_INVALID_PARAMETER** | The *pwszName* parameter cannot be **NULL**, and the value pointed to by the parameter cannot be an empty string. |
| **NTE_BAD_FLAGS** | The *dwFlags* parameter must be zero or **NCRYPT_MACHINE_KEY_FLAG**. |

## Remarks

To retrieve a protection descriptor rule string, you must call this function twice. The first time you call, set the *pwszDescriptorString* argument to **NULL** and the value pointed to by the *pcDescriptorString* argument to zero. Your first call retrieves the number of characters in the descriptor string. Use this number to allocate memory for the string and retrieve a pointer to the allocated buffer. To retrieve the string, call the function again using the pointer.

## See also

[CNG DPAPI Functions](https://learn.microsoft.com/windows/desktop/SecCNG/cng-dpapi-functions)

[NCryptRegisterProtectionDescriptorName](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptregisterprotectiondescriptorname)