# MsiIsProductElevatedW function

## Description

The **MsiIsProductElevated** function returns whether or not the product is managed. Only applications that require elevated privileges for installation and being installed through advertisement are considered managed, which means that an application installed per-machine is always considered managed.

An application that is installed per-user is only considered managed if it is advertised by a local system process that is impersonating the user. For more information, see [Advertising a Per-User Application to be Installed with Elevated Privileges](https://learn.microsoft.com/windows/desktop/Msi/advertising-a-per-user-application-to-be-installed-with-elevated-privileges).

**MsiIsProductElevated** verifies that the local system owns the product registry data. The function does not refer to account policies such as [AlwaysInstallElevated](https://learn.microsoft.com/windows/desktop/Msi/alwaysinstallelevated).

## Parameters

### `szProduct` [in]

The full product code GUID of the product.

This parameter is required and cannot be **NULL** or empty.

### `pfElevated` [out]

A pointer to a BOOL for the result.

This parameter cannot be **NULL**.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS, and *pfElevated* is set to **TRUE** if the product is a managed application.

If the function fails, the return value is one of the error codes identified in the following table.

| Return code | Description |
| --- | --- |
| **ERROR_UNKNOWN_PRODUCT** | The product is not currently known. |
| **ERROR_INVALID_PARAMETER** | An invalid argument is passed to the function. |
| **ERROR_BAD_CONFIGURATION** | The configuration information for the product is invalid. |
| **ERROR_FUNCTION_FAILED** | The function failed. |
| **ERROR_CALL_NOT_IMPLEMENTED** | The function is not available for a specific platform. |

## See also

[Determining Installation Context](https://learn.microsoft.com/windows/desktop/Msi/determining-installation-context)

[Installing a Package with Elevated Privileges for a Non-Admin](https://learn.microsoft.com/windows/desktop/Msi/installing-a-package-with-elevated-privileges-for-a-non-admin)

## Remarks

> [!NOTE]
> The msi.h header defines MsiIsProductElevated as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).