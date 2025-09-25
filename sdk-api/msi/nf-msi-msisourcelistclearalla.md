# MsiSourceListClearAllA function

## Description

The
**MsiSourceListClearAll** function removes all network sources from the source list of a patch or product in a specified context. For more information, see
[Source Resiliency](https://learn.microsoft.com/windows/desktop/Msi/source-resiliency).

## Parameters

### `szProduct` [in]

 The [ProductCode](https://learn.microsoft.com/windows/desktop/Msi/productcode) of the product to modify.

### `szUserName` [in]

The user name for a per-user installation. The user name should always be in the format of DOMAIN\USERNAME (or MACHINENAME\USERNAME for a local user).

An empty string or **NULL** for a per-machine installation.

### `dwReserved` [in]

Reserved for future use. This value must be set to 0.

## Return value

The **MsiSourceListClearAll** function returns the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The user does not have the ability to clear the source list for this product. |
| **ERROR_BAD_CONFIGURATION** | The configuration data is corrupt. |
| **ERROR_BAD_USERNAME** | Could not resolve the user name. |
| **ERROR_FUNCTION_FAILED** | The function did not succeed. |
| **ERROR_INSTALL_SERVICE_FAILURE** | Could not access installer service. |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. |
| **ERROR_SUCCESS** | The function succeeded. |
| **ERROR_UNKNOWN_PRODUCT** | The specified product is unknown. |

## Remarks

An administrator can modify per-machine installations, their own per-user non-managed installations, and the per-user managed installations for any user. A non-administrator can only modify per-machine installations and their own (managed or non-managed)per-user installations. Users can be enabled to browse for sources by setting policy. For more information, see the [DisableBrowse](https://learn.microsoft.com/windows/desktop/Msi/disablebrowse), [AllowLockdownBrowse](https://learn.microsoft.com/windows/desktop/Msi/allowlockdownbrowse), and [AlwaysInstallElevated](https://learn.microsoft.com/windows/desktop/Msi/alwaysinstallelevated) policies.

If a network source is the current source for the product, this function forces the installer to search the source list for a valid source the next time a source is needed. If the current source is media or a URL source, it is still valid after this call and the source list is not searched unless [MsiSourceListForceResolution](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msisourcelistforceresolutiona) is also called.

If the user name is an empty string or **NULL**, the function operates on the per-machine installation of the product. In this case, if the product is installed as per-user only, the function returns ERROR_UNKNOWN_PRODUCT.

If the user name is not an empty string or **NULL**, it specifies the name of the user whose product installation is modified. If the user name is the current user name, the function first attempts to modify a non-managed installation of the product. If no non-managed installation of the product can be found, the function then tries to modify a managed per-user installation of the product. If no managed or unmanaged per-user installations of the product can be found, the function returns ERROR_UNKNOWN_PRODUCT, even if the product is installed per-machine.

This function cannot modify a non-managed installation for any user besides the current user. If the user name is not an empty string or **NULL**, but is not the current user, the function only checks for a managed per-user installation of the product for the specified user. If the product is not installed as managed per-user for the specified user, the function returns ERROR_UNKNOWN_PRODUCT, even if the product is installed per-machine.

> [!NOTE]
> The msi.h header defines MsiSourceListClearAll as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[AllowLockdownBrowse](https://learn.microsoft.com/windows/desktop/Msi/allowlockdownbrowse)

[AlwaysInstallElevated](https://learn.microsoft.com/windows/desktop/Msi/alwaysinstallelevated)

[DisableBrowse](https://learn.microsoft.com/windows/desktop/Msi/disablebrowse)

[Installation Context](https://learn.microsoft.com/windows/desktop/Msi/installation-context)

[LookupAccountName](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-lookupaccountnamea)

[MsiSourceListForceResolution](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msisourcelistforceresolutiona)

[ProductCode](https://learn.microsoft.com/windows/desktop/Msi/productcode)

[Source Resiliency](https://learn.microsoft.com/windows/desktop/Msi/source-resiliency)