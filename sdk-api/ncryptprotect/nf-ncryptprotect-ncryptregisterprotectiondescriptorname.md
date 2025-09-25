# NCryptRegisterProtectionDescriptorName function

## Description

The **NCryptRegisterProtectionDescriptorName** function registers the display name and the associated rule string for a protection descriptor.

## Parameters

### `pwszName` [in]

Pointer to a null-terminated Unicode string that contains the display name of the descriptor to be registered.

### `pwszDescriptorString` [in, optional]

Pointer to a null-terminated Unicode string that contains a protection descriptor rule. If this parameter is **NULL** or the string is empty, the registry value previously created for the *pwszName* parameter will be deleted.

### `dwFlags`

A constant that indicates the registry hive under which to register the new entry. If this value is zero (0), the registry root is **HKEY_CURRENT_USER**. If this value is **NCRYPT_MACHINE_KEY_FLAG**, the root is **HKEY_LOCAL_MACHINE**.

## Return value

Returns a status code that indicates the success or failure of the function. Possible return codes include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **ERROR_SUCCESS** | The function was successful. |
| **NTE_INVALID_PARAMETER** | The *pwszName* parameter cannot be **NULL**, and the value pointed to by the parameter cannot be an empty string. |
| **NTE_BAD_FLAGS** | The *dwFlags* parameter must be zero or **NCRYPT_MACHINE_KEY_FLAG**. |

## Remarks

The registry key created by using this function is not volatile. The information is stored in a file and preserved when the computer shuts down.

## See also

[CNG DPAPI Functions](https://learn.microsoft.com/windows/desktop/SecCNG/cng-dpapi-functions)

[NCryptQueryProtectionDescriptorName](https://learn.microsoft.com/windows/desktop/api/ncryptprotect/nf-ncryptprotect-ncryptqueryprotectiondescriptorname)