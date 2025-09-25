# MsiQueryComponentStateA function

## Description

The **MsiQueryComponentState** function returns the installed state for a component. This function can query for a component of an instance of a product that is installed under user accounts other than the current user provided the product is not advertised under the per-user-unmanaged context for a user account other than the current user. The calling process must have administrative privileges to get information for a product installed for a user other than the current user.

## Parameters

### `szProductCode` [in]

Specifies the [ProductCode](https://learn.microsoft.com/windows/desktop/Msi/productcode) GUID for the product that contains the component.

### `szUserSid` [in]

Specifies the security identifier (SID) of the account under which the instance of the product being queried exists. If *dwContext* is not MSIINSTALLCONTEXT_MACHINE, null specifies the current user.

| Type of SID | Meaning |
| --- | --- |
| **NULL** | NULL denotes the currently logged on user. |
| **User SID** | Specifies enumeration for a particular user in the system. An example of user SID is "S-1-3-64-2415071341-1358098788-3127455600-2561". |

**Note** The special SID string "S-1-5-18" (system) cannot be used to enumerate products installed as per-machine. If *dwContext* is **MSIINSTALLCONTEXT_MACHINE**, *szUserSid* must be null.

### `dwContext` [in]

The installation context of the product instance being queried.

| Name | Meaning |
| --- | --- |
| **MSIINSTALLCONTEXT_USERMANAGED** | Retrieves the component's state for the per–user–managed instance of the product. |
| **MSIINSTALLCONTEXT_USERUNMANAGED** | Retrieves the component's state for the per–user–non-managed instance of the product. |
| **MSIINSTALLCONTEXT_MACHINE** | Retrieves the component's state for the per-machine instance of the product. |

### `szComponentCode` [in]

Specifies the component being queried. Component code GUID of the component as found in the ComponentID column of the [Component](https://learn.microsoft.com/windows/desktop/Msi/component-table) table.

### `pdwState` [out]

Installation state of the component for the specified product instance. This parameter can return one of the following or null values.

| Value | Meaning |
| --- | --- |
| **INSTALLSTATE_LOCAL** | The component is installed locally. |
| **INSTALLSTATE_SOURCE** | The component is installed to run from the source. |

## Return value

The **MsiQueryComponentState** function returns the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The calling process must have administrative privileges to get information for a product installed for a user other than the current user. |
| **ERROR_BAD_CONFIGURATION** | The configuration data is corrupt. |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. |
| **ERROR_SUCCESS** | The function completed successfully. |
| **ERROR_UNKNOWN_COMPONENT** | The component ID does not identify a known component. |
| **ERROR_UNKNOWN_PRODUCT** | The product code does not identify a known product. |
| **ERROR_FUNCTION_FAILED** | Failures that cannot be ascribed to any Windows error code. |
| **ERROR_MORE_DATA** | Buffer too small to get the user SID. |

For more information, see
[Displayed Error Messages](https://learn.microsoft.com/windows/desktop/Msi/displayed-error-messages).

## See also

[Component](https://learn.microsoft.com/windows/desktop/Msi/component-table)

[Displayed Error Messages](https://learn.microsoft.com/windows/desktop/Msi/displayed-error-messages)

[Installer Selection Functions](https://learn.microsoft.com/windows/desktop/Msi/database-functions)

[Not Supported in Windows Installer 2.0 and earlier](https://learn.microsoft.com/windows/desktop/Msi/not-supported-in-windows-installer-version-2-0)

[ProductCode](https://learn.microsoft.com/windows/desktop/Msi/productcode)

## Remarks

> [!NOTE]
> The msi.h header defines MsiQueryComponentState as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).