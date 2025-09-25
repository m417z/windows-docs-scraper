# MsiQueryFeatureStateExW function

## Description

The **MsiQueryFeatureStateEx** function returns the installed state for a product feature. This function can be used to query any feature of an instance of a product installed under the machine account or any context under the current user account or the per-user-managed context under any user account other than the current user. A user must have administrative privileges to get information for a product installed for a user other than the current user.

## Parameters

### `szProductCode` [in]

[ProductCode](https://learn.microsoft.com/windows/desktop/Msi/productcode) GUID of the product that contains the feature of interest.

### `szUserSid` [in]

Specifies the security identifier (SID) of the account, under which, the instance of the product being queried exists. If *dwContext* is not **MSIINSTALLCONTEXT_MACHINE**, a null value specifies the current user.

| Type of SID | Meaning |
| --- | --- |
| **NULL** | NULL denotes the currently logged on user. |
| **User SID** | Specifies enumeration for a particular user in the system. An example of user SID is "S-1-3-64-2415071341-1358098788-3127455600-2561". |

**Note** The special SID string s-1-5-18 (system) cannot be used to enumerate features of products installed as per-machine. If *dwContext* is **MSIINSTALLCONTEXT_MACHINE**, *szUserSid* must be null.

### `dwContext` [in]

The installation context of the product instance being queried.

| Name | Meaning |
| --- | --- |
| **MSIINSTALLCONTEXT_USERMANAGED** | Retrieves the feature state for the per-user-managed instance of the product. |
| **MSIINSTALLCONTEXT_USERUNMANAGED** | Retrieves the feature state for the per-user-unmanaged instance of the product.<br><br>**Note** When the query is made on a product installed under the per-user-unmanaged context for a user account other than the current user, the function fails. |
| **MSIINSTALLCONTEXT_MACHINE** | Retrieves the feature state for the per-machine instance of the product. |

### `szFeature` [in]

Specifies the feature being queried. Identifier of the feature as found in the **Feature** column of the [Feature table](https://learn.microsoft.com/windows/desktop/Msi/feature-table).

### `pdwState` [out, optional]

Installation state of the feature for the specified product instance. This parameter can return one of the following or null.

| Value | Meaning |
| --- | --- |
| **INSTALLSTATE_ADVERTISED** | This feature is advertised. |
| **INSTALLSTATE_LOCAL** | The feature is installed locally. |
| **INSTALLSTATE_SOURCE** | The feature is installed to run from source. |

## Return value

The **MsiQueryFeatureStateEx** function returns the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | A user must have administrative privileges to get information for a product installed for a user other than the current user. |
| **ERROR_BAD_CONFIGURATION** | The configuration data is corrupt. |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. |
| **ERROR_SUCCESS** | The function completed successfully. |
| **ERROR_UNKNOWN_FEATURE** | The feature ID does not identify a known feature. |
| **ERROR_UNKNOWN_PRODUCT** | The product code does not identify a known product. |
| **ERROR_FUNCTION_FAILED** | An unexpected internal failure. |

 For more information, see
[Displayed Error Messages](https://learn.microsoft.com/windows/desktop/Msi/displayed-error-messages).

## Remarks

The
**MsiQueryFeatureStateEx** function does not validate that the feature is actually accessible. The **MsiQueryFeatureStateEx** function does not validate the feature ID. **ERROR_UNKNOWN_FEATURE** is returned for any unknown feature ID. When the query is made on a product installed under the per-user-unmanaged context for a user account other than the current user, the function fails. In this case the function returns **ERROR_UNKNOWN_FEATURE**, or if the product is advertised only (not installed), **ERROR_UNKNOWN_PRODUCT** is returned.

> [!NOTE]
> The msi.h header defines MsiQueryFeatureStateEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Displayed Error Messages](https://learn.microsoft.com/windows/desktop/Msi/displayed-error-messages)

[Feature Table](https://learn.microsoft.com/windows/desktop/Msi/feature-table)

[MsiQueryFeatureState](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiqueryfeaturestatea)

[Not Supported in Windows Installer 2.0 and earlier](https://learn.microsoft.com/windows/desktop/Msi/not-supported-in-windows-installer-version-2-0)

[ProductCode](https://learn.microsoft.com/windows/desktop/Msi/productcode)

[System Status Functions](https://learn.microsoft.com/windows/desktop/Msi/installer-function-reference)