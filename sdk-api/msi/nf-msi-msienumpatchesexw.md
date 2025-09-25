# MsiEnumPatchesExW function

## Description

The **MsiEnumPatchesEx** function enumerates all patches in a specific context or across all contexts. Patches already applied to products are enumerated. Patches that have been registered but not yet applied to products are also enumerated.

## Parameters

### `szProductCode` [in, optional]

A null-terminated string that specifies the [ProductCode](https://learn.microsoft.com/windows/desktop/Msi/productcode) GUID of the product whose patches are enumerated. If non-**NULL**, patch enumeration is restricted to instances of this product under the user and context specified by *szUserSid* and *dwContext*. If **NULL**, the patches for all products under the specified context are enumerated.

### `szUserSid` [in, optional]

A null-terminated string that specifies a security identifier (SID) that restricts the context of enumeration. The special SID string "S-1-1-0" (Everyone) specifies enumeration across all users in the system. A SID value other than "S-1-1-0" is considered a user SID and restricts enumeration to that user. When enumerating for a user other than current user, any patches that were applied in a per-user-unmanaged context using a version less than Windows Installer version 3.0, are not enumerated. This parameter can be set to **NULL** to specify the current user.

| SID type | Meaning |
| --- | --- |
| ****NULL**** | Specifies the currently logged-on user. |
| **User SID** | An enumeration for a specific user in the system. An example of user SID is "S-1-3-64-2415071341-1358098788-3127455600-2561". |
| **s-1-1-0** | An enumeration across all users in the system. |

**Note** The special SID string "S-1-5-18" (System) cannot be used to enumerate products or patches installed as per-machine. Setting the SID value to "S-1-5-18" returns **ERROR_INVALID_PARAMETER**. When *dwContext* is set to **MSIINSTALLCONTEXT_MACHINE** only, *szUserSid* must be **NULL**.

### `dwContext` [in]

Restricts the enumeration to one or a combination of contexts. This parameter can be any one or a combination of the following values.

| Context | Meaning |
| --- | --- |
| **MSIINSTALLCONTEXT_USERMANAGED** | The enumeration that is extended to all per-user-managed installations for the users that *szUserSid* specifies. An invalid SID returns no items. |
| **MSIINSTALLCONTEXT_USERUNMANAGED** | In this context, only patches installed with Windows Installer version 3.0 are enumerated for users that are not the current user. For the current user, the function enumerates all installed and new patches. An invalid SID for *szUserSid* returns no items. |
| **MSIINSTALLCONTEXT_MACHINE** | An enumeration that is extended to all per-machine installations. When *dwContext* is set to **MSIINSTALLCONTEXT_MACHINE** only, the *szUserSid* parameter must be **NULL**. |

### `dwFilter` [in]

The filter for enumeration. This parameter can be one or a combination of the following parameters.

| Filter | Meaning |
| --- | --- |
| **MSIPATCHSTATE_APPLIED**<br><br>1 | The enumeration includes patches that have been applied. Enumeration does not include superseded or obsolete patches. |
| **MSIPATCHSTATE_SUPERSEDED**<br><br>2 | The enumeration includes patches that are marked as superseded. |
| **MSIPATCHSTATE_OBSOLETED**<br><br>4 | The enumeration includes patches that are marked as obsolete. |
| **MSIPATCHSTATE_REGISTERED**<br><br>8 | The enumeration includes patches that are registered but not yet applied. The [MsiSourceListAddSourceEx](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msisourcelistaddsourceexa) function can register new patches.<br><br>**Note** Patches registered for users other than current user and applied in the per-user-unmanaged context are not enumerated. |
| **MSIPATCHSTATE_ALL**<br><br>15 | The enumeration includes all applied, obsolete, superseded, and registered patches. |

### `dwIndex` [in]

The index of the patch to retrieve. This parameter must be zero for the first call to the **MsiEnumPatchesEx** function and then incremented for subsequent calls. The *dwIndex* parameter should be incremented only if the previous call returned ERROR_SUCCESS.

### `szPatchCode` [out, optional]

An output buffer to contain the GUID of the patch being enumerated. The buffer should be large enough to hold the GUID. This parameter can be **NULL**.

### `szTargetProductCode` [out, optional]

An output buffer to contain the [ProductCode](https://learn.microsoft.com/windows/desktop/Msi/productcode) GUID of the product that receives this patch. The buffer should be large enough to hold the GUID. This parameter can be **NULL**.

### `pdwTargetProductContext` [out, optional]

Returns the context of the patch being enumerated. The output value can be **MSIINSTALLCONTEXT_USERMANAGED**, **MSIINSTALLCONTEXT_USERUNMANAGED**, or **MSIINSTALLCONTEXT_MACHINE**. This parameter can be **NULL**.

### `szTargetUserSid` [out, optional]

An output buffer that receives the string SID of the account under which this patch instance exists. This buffer returns an empty string for a per-machine context.

This buffer should be large enough to contain the SID. If the buffer is too small, the function returns **ERROR_MORE_DATA** and sets **pcchTargetUserSid* to the number of **TCHAR** in the value, not including the terminating NULL character.

If the *szTargetUserSid* is set to **NULL** and *pcchTargetUserSid* is set to a valid pointer, the function returns **ERROR_SUCCESS** and sets **pcchTargetUserSid* to the number of **TCHAR** in the value, not including the terminating **NULL** character. The function can then be called again to retrieve the value, with *szTargetUserSid* buffer large enough to contain **pcchTargetUserSid* + 1 characters.

If *szTargetUserSid* and *pcchTargetUserSid* are both set to **NULL**, the function returns **ERROR_SUCCESS** if the value exists, without retrieving the value.

### `pcchTargetUserSid` [in, out, optional]

A pointer to a variable that specifies the number of **TCHAR** in the *szTargetUserSid* buffer. When the function returns, this parameter is set to the size of the requested value whether or not the function copies the value into the specified buffer. The size is returned as the number of **TCHAR** in the requested value, not including the terminating null character.

This parameter can be set to **NULL** only if *szTargetUserSid* is also **NULL**, otherwise the function returns ERROR_INVALID_PARAMETER.

## Return value

The **MsiEnumPatchesEx** function returns one of the following values.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The function fails trying to access a resource with insufficient privileges. |
| **ERROR_BAD_CONFIGURATION** | The configuration data is corrupt. |
| **ERROR_INVALID_PARAMETER** | An invalid parameter is passed to the function. |
| **ERROR_NO_MORE_ITEMS** | There are no more patches to enumerate. |
| **ERROR_SUCCESS** | The patch is successfully enumerated. |
| **ERROR_UNKNOWN_PRODUCT** | The product that *szProduct* specifies is not installed on the computer in the specified contexts. |
| **ERROR_MORE_DATA** | This is returned when *pcchTargetUserSid* points to a buffer size less than required to copy the SID. In this case, the user can fix the buffer and call [MsiEnumPatchesEx](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msienumpatchesexa) again for the same index value. |

## Remarks

Non-administrators can enumerate patches within their visibility only. Administrators can enumerate patches for other user contexts.

> [!NOTE]
> The msi.h header defines MsiEnumPatchesEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Installation Context](https://learn.microsoft.com/windows/desktop/Msi/installation-context)

[MsiSourceListAddSourceEx](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msisourcelistaddsourceexa)

[Not Supported in Windows Installer 2.0 and earlier](https://learn.microsoft.com/windows/desktop/Msi/not-supported-in-windows-installer-version-2-0)

[ProductCode](https://learn.microsoft.com/windows/desktop/Msi/productcode)