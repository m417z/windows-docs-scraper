# MsiSourceListAddSourceW function

## Description

The
**MsiSourceListAddSource** function adds to the list of valid network sources that contain the specified type of sources for a product or patch in a specified user context.

The number of sources in the [SOURCELIST](https://learn.microsoft.com/windows/desktop/Msi/sourcelist) property is unlimited.

## Parameters

### `szProduct` [in]

 The [ProductCode](https://learn.microsoft.com/windows/desktop/Msi/productcode) of the product to modify.

### `szUserName` [in]

The user name for a per-user installation. On Windows 2000 or Windows XP, the user name should always be in the format of DOMAIN\USERNAME (or MACHINENAME\USERNAME for a local user).

An empty string or **NULL** for a per-machine installation.

### `dwReserved` [in]

Reserved for future use. This value must be set to 0.

### `szSource` [in]

Pointer to the string specifying the source.

## Return value

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The user does not have the ability to add a source. |
| **ERROR_BAD_CONFIGURATION** | The configuration data is corrupt. |
| **ERROR_BAD_USERNAME** | Could not resolve the user name. |
| **ERROR_FUNCTION_FAILED** | The function did not succeed. |
| **ERROR_INSTALL_SERVICE_FAILURE** | Could not access installer service. |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. |
| **ERROR_SUCCESS** | The source was added. |
| **ERROR_UNKNOWN_PRODUCT** | The specified product is unknown. |

## Remarks

An administrator can modify per-machine installations, their own per-user non-managed installations, and the per-user managed installations for any user. A non-administrator can only modify per-machine installations and their own (managed or non-managed)per-user installations. Users can be enabled to browse for sources by setting policy. For more information, see the [DisableBrowse](https://learn.microsoft.com/windows/desktop/Msi/disablebrowse), [AllowLockdownBrowse](https://learn.microsoft.com/windows/desktop/Msi/allowlockdownbrowse), and [AlwaysInstallElevated](https://learn.microsoft.com/windows/desktop/Msi/alwaysinstallelevated) policies.

Note that this function merely adds the new source to the list of valid sources. If another source was used to install the product, the new source is not used until the current source is unavailable.

It is the responsibility of the caller to ensure that the provided source is a valid source image for the product.

If the user name is an empty string or **NULL**, the function operates on the per-machine installation of the product. In this case, if the product is installed only in the per-user state, the function returns ERROR_UNKNOWN_PRODUCT.

If the user name is not an empty string or **NULL**, it specifies the name of the user whose product installation is modified. If the user name is the current user name, the function first attempts to modify a non-managed installation of the product. If no non-managed installation of the product can be found, the function then tries to modify a managed per-user installation of the product. If no managed or unmanaged per-user installations of the product can be found, the function returns ERROR_UNKNOWN_PRODUCT, even if the product is installed per-machine.

This function can not modify a non-managed installation for any user besides the current user. If the user name is not an empty string or **NULL**, but is not the current user, the function only checks for a managed per-user installation of the product for the specified user. If the product is not installed as managed per-user for the specified user, the function returns ERROR_UNKNOWN_PRODUCT, even if the product is installed per-machine.

> [!NOTE]
> The msi.h header defines MsiSourceListAddSource as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[AllowLockdownBrowse](https://learn.microsoft.com/windows/desktop/Msi/allowlockdownbrowse)

[AlwaysInstallElevated](https://learn.microsoft.com/windows/desktop/Msi/alwaysinstallelevated)

[DisableBrowse](https://learn.microsoft.com/windows/desktop/Msi/disablebrowse)

[Installation Context](https://learn.microsoft.com/windows/desktop/Msi/installation-context)

[LookupAccountName](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-lookupaccountnamea)

[ProductCode](https://learn.microsoft.com/windows/desktop/Msi/productcode)

[SOURCELIST](https://learn.microsoft.com/windows/desktop/Msi/sourcelist)

[Source Resiliency](https://learn.microsoft.com/windows/desktop/Msi/source-resiliency)