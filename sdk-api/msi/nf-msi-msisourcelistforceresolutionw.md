# MsiSourceListForceResolutionW function

## Description

The
**MsiSourceListForceResolution** function forces the installer to search the source list for a valid product source the next time a source is required. For example, when the installer performs an installation or reinstallation, or when it requires the path for a component that is set to run from source.

## Parameters

### `szProduct` [in]

 The [ProductCode](https://learn.microsoft.com/windows/desktop/Msi/productcode) of the product to modify.

### `szUserName` [in]

The user name for a per-user installation. The user name should always be in the format of DOMAIN\USERNAME (or MACHINENAME\USERNAME for a local user).

An empty string or **NULL** for a per-machine installation.

### `dwReserved` [in]

Reserved for future use. This value must be set to 0.

## Return value

The **MsiSourceListForceResolution** function returns the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The caller does not have sufficient access to force resolution for the product. |
| **ERROR_BAD_CONFIGURATION** | The configuration data is corrupt. |
| **ERROR_BAD_USER_NAME** | The specified user is not a valid user. |
| **ERROR_FUNCTION_FAILED** | The function could not complete. |
| **ERROR_INSTALL_SERVICE_FAILURE** | The installation service could not be accessed. |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. |
| **ERROR_SUCCESS** | The function succeeded. |
| **ERROR_UNKNOWN_PRODUCT** | The specified product is unknown. |

## Remarks

An administrator can modify per-machine installations, their own per-user non-managed installations, and the per-user managed installations for any user. A non-administrator can only modify per-machine installations and their own (managed or non-managed) per-user installations.

If the user name is an empty string or **NULL**, the function operates on the per-machine installation of the product. In this case, if the product is installed as per-user only, the function returns ERROR_UNKNOWN_PRODUCT.

If the user name is not an empty string or **NULL**, it specifies the name of the user whose product installation is modified. If the user name is the current user name, the function first attempts to modify a non-managed installation of the product. If no non-managed installation of the product can be found, the function then tries to modify a managed per-user installation of the product. If no managed or unmanaged per-user installations of the product can be found, the function returns ERROR_UNKNOWN_PRODUCT, even if the product is installed per-machine.

This function can not modify a non-managed installation for any user besides the current user. If the user name is not an empty string or **NULL**, but is not the current user, the function only checks for a managed per-user installation of the product for the specified user. If the product is not installed as managed per-user for the specified user, the function returns ERROR_UNKNOWN_PRODUCT, even if the product is installed per-machine.

> [!NOTE]
> The msi.h header defines MsiSourceListForceResolution as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Installation Context](https://learn.microsoft.com/windows/desktop/Msi/installation-context)

[LookupAccountName](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-lookupaccountnamea)

[MsiGetComponentPath](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msigetcomponentpatha)

[Source Resiliency](https://learn.microsoft.com/windows/desktop/Msi/source-resiliency)