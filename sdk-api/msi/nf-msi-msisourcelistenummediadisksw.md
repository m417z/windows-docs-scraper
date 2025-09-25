# MsiSourceListEnumMediaDisksW function

## Description

The **MsiSourceListEnumMediaDisks** function enumerates the list of disks registered for the media source for a patch or product.

## Parameters

### `szProductCodeOrPatchCode` [in]

The [ProductCode](https://learn.microsoft.com/windows/desktop/Msi/productcode) or patch GUID of the product or patch. Use a null-terminated string. If the string is longer than 39 characters, the function fails and returns ERROR_INVALID_PARAMETER. This parameter cannot be **NULL**.

### `szUserSid` [in, optional]

A string SID that specifies the user account that contains the product or patch. The SID is not validated or resolved. An incorrect SID can return ERROR_UNKNOWN_PRODUCT or ERROR_UNKNOWN_PATCH. When referencing a machine context, *szUserSID* must be **NULL** and *dwContext* must be MSIINSTALLCONTEXT_MACHINE.

| Type of SID | Meaning |
| --- | --- |
| ****NULL**** | A **NULL** denotes the currently logged on user. When referencing the current user account, *szUserSID* can be **NULL** and *dwContext* can be MSIINSTALLCONTEXT_USERMANAGED or MSIINSTALLCONTEXT_USERUNMANAGED. |
| **User SID** | An enumeration for a specific user in the system. An example of a user SID is "S-1-3-64-2415071341-1358098788-3127455600-2561". |
| **s-1-1-0** | The special SID string s-1-1-0 (everyone) specifies enumeration across all users in the system. |

**Note** The special SID string s-1-5-18 (system) cannot be used to enumerate products or patches installed as per-machine. Setting the SID value to s-1-5-18 returns ERROR_INVALID_PARAMETER.

### `dwContext` [in]

This parameter specifies the context of the product or patch instance. This parameter can contain one of the following values.

| Type of context | Meaning |
| --- | --- |
| **MSIINSTALLCONTEXT_USERMANAGED** | The product or patch instance exists in the per-user-managed context. |
| **MSIINSTALLCONTEXT_USERUNMANAGED** | The product or patch instance exists in the per-user-unmanaged context. |
| **MSIINSTALLCONTEXT_MACHINE** | The product or patch instance exists in the per-machine context. |

### `dwOptions` [in]

The *dwOptions* value that specifies the meaning of *szProductCodeOrPatchCode*.

| Flag | Meaning |
| --- | --- |
| **MSICODE_PRODUCT** | *szProductCodeOrPatchCode* is a product code GUID. <br><br> |
| **MSICODE_PATCH** | *szProductCodeOrPatchCode* is a patch code GUID. |

### `dwIndex` [in]

The index of the source to retrieve. This parameter must be 0 (zero) for the first call to the **MsiSourceListEnumMediaDisks** function, and then incremented for subsequent calls until the function returns ERROR_NO_MORE_ITEMS.

### `pdwDiskId` [out, optional]

On entry to **MsiSourceListEnumMediaDisks** this parameter provides a pointer to a **DWORD** to receive the ID of the disk that is being enumerated. This parameter is optional.

### `szVolumeLabel` [out, optional]

An output buffer that receives the volume label of the disk that is being enumerated. This buffer should be large enough to contain the information. If the buffer is too small, the function returns ERROR_MORE_DATA and sets **pcchVolumeLabel* to the number of **TCHAR** in the value, not including the terminating NULL character.

If *szVolumeLabel* and *pcchVolumeLabel* are both set to **NULL**, the function returns ERROR_SUCCESS if the value exists, without retrieving the value.

### `pcchVolumeLabel` [in, out, optional]

A pointer to a variable that specifies the number of **TCHAR** in the *szVolumeLabel* buffer. When the function returns, this parameter is the number of **TCHAR** in the received value, not including the terminating null character.

This parameter can be set to **NULL** only if *szVolumeLabel* is also **NULL**, otherwise the function returns ERROR_INVALID_PARAMETER.

### `szDiskPrompt` [out, optional]

An output buffer that receives the disk prompt of the disk that is being enumerated. This buffer should be large enough to contain the information. If the buffer is too small, the function returns ERROR_MORE_DATA and sets **pcchDiskPrompt* to the number of **TCHAR** in the value, not including the terminating NULL character.

If the *szDiskPrompt* is set to **NULL** and *pcchDiskPrompt* is set to a valid pointer, the function returns ERROR_SUCCESS and sets **pcchDiskPrompt* to the number of **TCHAR** in the value, not including the terminating NULL character. The function can then be called again to retrieve the value, with *szDiskPrompt* buffer large enough to contain **pcchDiskPrompt* + 1 characters.

If *szDiskPrompt* and *pcchDiskPrompt* are both set to **NULL**, the function returns ERROR_SUCCESS if the value exists, without retrieving the value.

### `pcchDiskPrompt` [in, out, optional]

A pointer to a variable that specifies the number of **TCHAR** in the *szDiskPrompt* buffer. When the function returns, this parameter is set to the size of the requested value whether or not the function copies the value into the specified buffer. The size is returned as the number of **TCHAR** in the requested value, not including the terminating null character.

This parameter can be set to **NULL** only if *szDiskPrompt* is also **NULL**, otherwise the function returns ERROR_INVALID_PARAMETER.

## Return value

The **MsiSourceListEnumMediaDisks** function returns the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The user does not have the ability to read the specified media source or the specified product or patch. This does not indicate whether a media source, product, or patch is found. |
| **ERROR_BAD_CONFIGURATION** | The configuration data is corrupt. |
| **ERROR_INVALID_PARAMETER** | An invalid parameter is passed to the function. |
| **ERROR_NO_MORE_ITEMS** | There are no more disks registered for this product or patch. |
| **ERROR_SUCCESS** | The value is enumerated successfully. |
| **ERROR_UNKNOWN_PATCH** | The patch is not found. |
| **ERROR_UNKNOWN_PRODUCT** | The product is not found. |
| **ERROR_MORE_DATA** | The buffer that is provided is too small to contain the requested information. |
| **ERROR_FUNCTION_FAILED** | Unexpected internal failure. |

## Remarks

When making multiple calls to **MsiSourceListEnumMediaDisks** to enumerate all the sources for a single product instance, each call must be made from the same thread.

An administrator can enumerate per-user unmanaged and managed installations for themselves,
per-machine installations, and per-user managed installations for any user. An administrator cannot
enumerate per-user unmanaged installations for other users. Non-administrators can only enumerate
their own per-user unmanaged and managed installations and per-machine installations.

> [!NOTE]
> The msi.h header defines MsiSourceListEnumMediaDisks as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Installation Context](https://learn.microsoft.com/windows/desktop/Msi/installation-context)

[Not Supported in Windows Installer 2.0 and earlier](https://learn.microsoft.com/windows/desktop/Msi/not-supported-in-windows-installer-version-2-0)

[ProductCode](https://learn.microsoft.com/windows/desktop/Msi/productcode)