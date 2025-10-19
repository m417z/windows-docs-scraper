# MsiGetPatchInfoExA function

## Description

The **MsiGetPatchInfoEx** function queries for information about the application of a patch to a specified instance of a product.

## Parameters

### `szPatchCode` [in]

A null-terminated string that contains the GUID of the patch. This parameter cannot be **NULL**.

### `szProductCode` [in]

A null-terminated string that contains the [ProductCode](https://learn.microsoft.com/windows/desktop/Msi/productcode) GUID of the product instance. This parameter cannot be **NULL**.

### `szUserSid` [in]

A null-terminated string that specifies the security identifier (SID) under which the instance of the patch being queried exists. Using a **NULL** value specifies the current user.

| SID | Meaning |
| --- | --- |
| **NULL** | Specifies the user that is logged on. |
| **User SID** | Specifies the enumeration for a specific user ID in the system. The following example identifies a possible user SID: "S-1-3-64-2415071341-1358098788-3127455600-2561". |

**Note** The special SID string "S-1-5-18" (system) cannot be used to enumerate products installed as per-machine. If *dwContext* is **MSIINSTALLCONTEXT_MACHINE**, *szUserSid* must be **NULL**.

### `dwContext` [in]

Restricts the enumeration to a per-user-unmanaged, per-user-managed, or per-machine context. This parameter can be any one of the following values.

| Context | Meaning |
| --- | --- |
| **MSIINSTALLCONTEXT_USERMANAGED**<br><br>1 | Query that is extended to all per–user-managed installations for the users that *szUserSid* specifies. |
| **MSIINSTALLCONTEXT_USERUNMANAGED**<br><br>2 | Query that is extended to all per–user-unmanaged installations for the users that *szUserSid* specifies. |
| **MSIINSTALLCONTEXT_MACHINE**<br><br>4 | Query that is extended to all per-machine installations. |

### `szProperty` [in]

A null-terminated string that specifies the property value to retrieve. The *szProperty* parameter can be one of the following:

| Name | Meaning |
| --- | --- |
| **INSTALLPROPERTY_LOCALPACKAGE**<br><br>"LocalPackage" | Gets the cached patch file that the product uses. |
| **INSTALLPROPERTY_TRANSFORMS**<br><br>"Transforms" | Gets the set of patch transforms that the last patch installation applied to the product. This value may not be available for per-user, non-managed applications if the user is not logged on. |
| **INSTALLPROPERTY_INSTALLDATE**<br><br>"InstallDate" | Gets the last time this product received service. The value of this property is replaced each time a patch is applied or removed from the product or the /v [Command-Line Option](https://learn.microsoft.com/windows/desktop/Msi/command-line-options) is used to repair the product. If the product has received no repairs or patches this property contains the time this product was installed on this computer. |
| **INSTALLPROPERTY_UNINSTALLABLE**<br><br>"Uninstallable" | Returns "1" if the patch is marked as possible to uninstall from the product. In this case, the installer can still block the uninstallation if this patch is required by another patch that cannot be uninstalled. |
| **INSTALLPROPERTY_PATCHSTATE**<br><br>"State" | Returns "1" if this patch is currently applied to the product. Returns "2" if this patch is superseded by another patch. Returns "4" if this patch is obsolete. These values correspond to the constants the *dwFilter* parameter of [MsiEnumPatchesEx](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msienumpatchesexa) uses. |
| **INSTALLPROPERTY_DISPLAYNAME**<br><br>"DisplayName" | Get the registered display name for the patch. For patches that do not include the DisplayName property in the [MsiPatchMetadata](https://learn.microsoft.com/windows/desktop/Msi/msipatchmetadata-table) table, the returned display name is an empty string (""). |
| **INSTALLPROPERTY_MOREINFOURL**<br><br>"MoreInfoURL" | Get the registered support information URL for the patch. For patches that do not include the MoreInfoURL property in the [MsiPatchMetadata](https://learn.microsoft.com/windows/desktop/Msi/msipatchmetadata-table) table, the returned support information URL is an empty string (""). |

### `lpValue` [out, optional]

This parameter is a pointer to a buffer that receives the property value. This buffer should be large enough to contain the information. If the buffer is too small, the function returns **ERROR_MORE_DATA** and sets **pcchValue* to the number of **TCHAR** in the property value, not including the terminating **NULL** character.

If *lpValue* is set to **NULL** and *pcchValue* is set to a valid pointer, the function returns **ERROR_SUCCESS** and sets **pcchValue* to the number of **TCHAR** in the value, not including the terminating **NULL** character. The function can then be called again to retrieve the value, with *lpValue* buffer large enough to contain **pcchValue* + 1 characters.

If *lpValue* and *pcchValue* are both set to **NULL**, the function returns **ERROR_SUCCESS** if the value exists, without retrieving the value.

### `pcchValue` [in, out]

When calling the function, this parameter should be a pointer to a variable that specifies the number of **TCHAR** in the *lpValue* buffer. When the function returns, this parameter is set to the size of the requested value whether or not the function copies the value into the specified buffer. The size is returned as the number of **TCHAR** in the requested value, not including the terminating null character.

This parameter can be set to **NULL** only if *lpValue* is also **NULL**. Otherwise, the function returns **ERROR_INVALID_PARAMETER**.

## Return value

The **MsiGetPatchInfoEx** function returns the following values.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The function fails trying to access a resource with insufficient privileges. |
| **ERROR_BAD_CONFIGURATION** | The configuration data is corrupt. |
| **ERROR_FUNCTION_FAILED** | The function fails and the error is not identified in other error codes. |
| **ERROR_INVALID_PARAMETER** | An invalid parameter is passed to the function. |
| **ERROR_MORE_DATA** | The value does not fit in the provided buffer. |
| **ERROR_SUCCESS** | The patch is enumerated successfully. |
| **ERROR_UNKNOWN_PRODUCT** | The product that *szProduct* specifies is not installed on the computer. |
| **ERROR_UNKNOWN_PROPERTY** | The property is unrecognized. |
| **ERROR_UNKNOWN_PATCH** | The patch is unrecognized. |

## Remarks

**Windows Installer 2.0:** Not supported. This function is available beginning with Windows Installer version 3.0.

A user may query patch data for any product instance that is visible. The administrator group can query patch data for any product instance and any user on the computer. Not all values are guaranteed to be available for per-user, non-managed applications if the user is not logged on.

> [!NOTE]
> The msi.h header defines MsiGetPatchInfoEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[ProductCode](https://learn.microsoft.com/windows/desktop/Msi/productcode)

[Removing Patches](https://learn.microsoft.com/windows/desktop/Msi/removing-patches)