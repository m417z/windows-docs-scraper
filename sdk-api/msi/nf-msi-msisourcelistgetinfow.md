# MsiSourceListGetInfoW function

## Description

The **MsiSourceListGetInfo** function retrieves information about the source list for a product or patch in a specific context.

## Parameters

### `szProductCodeOrPatchCode` [in]

The [ProductCode](https://learn.microsoft.com/windows/desktop/Msi/productcode) or patch GUID of the product or patch. Use a null-terminated string. If the string is longer than 39 characters, the function fails and returns ERROR_INVALID_PARAMETER. This parameter cannot be **NULL**.

### `szUserSid` [in, optional]

 This parameter can be a string security identifier (SID) that specifies the user account that contains the product or patch. The SID is not validated or resolved. An incorrect SID can return ERROR_UNKNOWN_PRODUCT or ERROR_UNKNOWN_PATCH. When referencing a machine context, *szUserSID* must be **NULL** and *dwContext* must be MSIINSTALLCONTEXT_MACHINE.

| Type of SID | Meaning |
| --- | --- |
| ****NULL**** | **NULL** denotes the currently logged on user. When referencing the current user account, *szUserSID* can be **NULL** and *dwContext* can be MSIINSTALLCONTEXT_USERMANAGED or MSIINSTALLCONTEXT_USERUNMANAGED. |
| **User SID** | Specifies enumeration for a specific user in the system. An example of a user SID is "S-1-3-64-2415071341-1358098788-3127455600-2561". |

**Note** The special SID string s-1-5-18 (system) cannot be used to enumerate products or patches installed as per-machine. Setting the SID value to s-1-5-18 returns ERROR_INVALID_PARAMETER.

**Note** The special SID string s-1-1-0 (everyone) should not be used. Setting the SID value to s-1-1-0 fails and returns ERROR_INVALID_PARAM.

### `dwContext` [in]

This parameter specifies the context of the product or patch instance. This parameter can contain one of the following values.

| Type of context | Meaning |
| --- | --- |
| **MSIINSTALLCONTEXT_USERMANAGED** | The product or patch instance exists in the per-user-managed context. |
| **MSIINSTALLCONTEXT_USERUNMANAGED** | The product or patch instance exists in the per-user-unmanaged context. |
| **MSIINSTALLCONTEXT_MACHINE** | The product or patch instance exists in the per-machine context. |

### `dwOptions` [in]

The *dwOptions* value specifies the meaning of *szProductCodeOrPatchCode*.

| Flag | Meaning |
| --- | --- |
| **MSICODE_PRODUCT** | *szProductCodeOrPatchCode* is a product code GUID. <br><br> |
| **MSICODE_PATCH** | *szProductCodeOrPatchCode* is a patch code GUID. |

### `szProperty` [in]

A null-terminated string that specifies the property value to retrieve. The *szProperty* parameter can be one of the following values.

| Name | Meaning |
| --- | --- |
| **INSTALLPROPERTY_MEDIAPACKAGEPATH**<br><br>"MediaPackagePath" | The path relative to the root of the installation media. |
| **INSTALLPROPERTY_DISKPROMPT**<br><br>"DiskPrompt" | The prompt template that is used when prompting the user for installation media. |
| **INSTALLPROPERTY_LASTUSEDSOURCE**<br><br>"LastUsedSource" | The most recently used source location for the product. |
| **INSTALLPROPERTY_LASTUSEDTYPE**<br><br>"LastUsedType" | An "n" if the last-used source is a network location. A "u" if the last used source is a URL location. An "m" if the last used source is media. An empty string ("") if there is no last used source. |
| **INSTALLPROPERTY_PACKAGENAME**<br><br>"PackageName" | The name of the Windows Installer package or patch package on the source. |

### `szValue` [out, optional]

An output buffer that receives the information. This buffer should be large enough to contain the information. If the buffer is too small, the function returns ERROR_MORE_DATA and sets **pcchValue* to the number of **TCHAR** in the value, not including the terminating NULL character.

If the *szValue* is set to **NULL** and *pcchValue* is set to a valid pointer, the function returns ERROR_SUCCESS and sets **pcchValue* to the number of **TCHAR** in the value, not including the terminating NULL character. The function can then be called again to retrieve the value, with *szValue* buffer large enough to contain **pcchValue* + 1 characters.

If *szValue* and *pcchValue* are both set to **NULL**, the function returns ERROR_SUCCESS if the value exists, without retrieving the value.

### `pcchValue` [in, out, optional]

A pointer to a variable that specifies the number of **TCHAR** in the *szValue* buffer. When the function returns, this parameter is set to the size of the requested value whether or not the function copies the value into the specified buffer. The size is returned as the number of **TCHAR** in the requested value, not including the terminating null character.

This parameter can be set to **NULL** only if *szValue* is also **NULL**, otherwise the function returns ERROR_INVALID_PARAMETER.

## Return value

The **MsiSourceListGetInfo** function returns the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The user does not have the ability to read the specified source list. This does not indicate whether a product or patch is found. |
| **ERROR_BAD_CONFIGURATION** | The configuration data is corrupt. |
| **ERROR_INVALID_PARAMETER** | An invalid parameter is passed to the function. |
| **ERROR_MORE_DATA** | The provided buffer is not sufficient to contain the requested data. |
| **ERROR_SUCCESS** | The property is retrieved successfully. |
| **ERROR_UNKNOWN_PATCH** | The patch is not found. |
| **ERROR_UNKNOWN_PRODUCT** | The product is not found. |
| **ERROR_UNKNOWN_PROPERTY** | The source property is not found. |
| **ERROR_FUNCTION_FAILED** | An unexpected internal failure. |

## Remarks

Administrators can modify the installation of a product or patch instance that exists under the machine context or under their own per-user context (managed or unmanaged.) They can modify the installation of a product or patch instance that exists under any user's per-user-managed context. Administrators cannot modify another user's installation of a product or patch instance that exists under that other user's per-user-unmanaged context.

Non-administrators cannot modify the installation of a product or patch instance that exists under another user's per-user context (managed or unmanaged.) They can modify the installation of a product or patch instance that exists under their own per-user-unmanaged context. They can modify the installation of a product or patch instance under the machine context or their own per-user-managed context only if they are enabled to browse for a product or patch source. Users can be enabled to browse for sources by setting policy. For more information, see [DisableBrowse](https://learn.microsoft.com/windows/desktop/Msi/disablebrowse), [AllowLockdownBrowse](https://learn.microsoft.com/windows/desktop/Msi/allowlockdownbrowse), and [AlwaysInstallElevated](https://learn.microsoft.com/windows/desktop/Msi/alwaysinstallelevated) policies.

> [!NOTE]
> The msi.h header defines MsiSourceListGetInfo as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[MsiSourceListSetInfo](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msisourcelistsetinfoa)

[Not Supported in Windows Installer 2.0 and earlier](https://learn.microsoft.com/windows/desktop/Msi/not-supported-in-windows-installer-version-2-0)

[ProductCode](https://learn.microsoft.com/windows/desktop/Msi/productcode)