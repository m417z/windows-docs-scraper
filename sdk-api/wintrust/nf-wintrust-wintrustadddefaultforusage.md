# WintrustAddDefaultForUsage function

## Description

The **WintrustAddDefaultForUsage** function specifies the default usage identifier and callback information for a provider.

## Parameters

### `pszUsageOID` [in]

Pointer to a string that contains the identifier.

### `psDefUsage` [in]

Pointer to a [CRYPT_PROVIDER_REGDEFUSAGE](https://learn.microsoft.com/windows/desktop/api/wintrust/ns-wintrust-crypt_provider_regdefusage) structure that contains callback information.

## Return value

The return value is **TRUE** if the function succeeds; **FALSE** if the function fails. If the function fails, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function to determine the reason for failure.

## Remarks

If the provider uses this function and requires any of the callback data, the provider must completely fill out the [CRYPT_PROVIDER_REGDEFUSAGE](https://learn.microsoft.com/windows/desktop/api/wintrust/ns-wintrust-crypt_provider_regdefusage) structure.

The usage and callback information can be retrieved by calling the [WintrustGetDefaultForUsage](https://learn.microsoft.com/windows/desktop/api/wintrust/nf-wintrust-wintrustgetdefaultforusage) function.

## See also

[CRYPT_PROVIDER_DEFUSAGE](https://learn.microsoft.com/windows/desktop/api/wintrust/ns-wintrust-crypt_provider_defusage)

[CRYPT_PROVIDER_REGDEFUSAGE](https://learn.microsoft.com/windows/desktop/api/wintrust/ns-wintrust-crypt_provider_regdefusage)

[WintrustGetDefaultForUsage](https://learn.microsoft.com/windows/desktop/api/wintrust/nf-wintrust-wintrustgetdefaultforusage)