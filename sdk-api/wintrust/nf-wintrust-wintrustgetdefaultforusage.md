# WintrustGetDefaultForUsage function

## Description

The **WintrustGetDefaultForUsage** function retrieves the default usage identifier and callback information.

## Parameters

### `dwAction` [in]

Action to perform. This can be one of the following values. For more information, see Remarks.

| Value | Meaning |
| --- | --- |
| **DWACTION_ALLOCANDFILL** | Allocate memory and fill the [CRYPT_PROVIDER_DEFUSAGE](https://learn.microsoft.com/windows/desktop/api/wintrust/ns-wintrust-crypt_provider_defusage) structure pointed to by the *psUsage* parameter. |
| **DWACTION_FREE** | Free all memory allocated during a previous call to this function by specifying **DWACTION_ALLOCANDFILL** for this parameter. |

### `pszUsageOID` [in]

Pointer to a string that contains the identifier.

### `psUsage` [in, out]

Pointer to a [CRYPT_PROVIDER_DEFUSAGE](https://learn.microsoft.com/windows/desktop/api/wintrust/ns-wintrust-crypt_provider_defusage) structure that contains callback information to be retrieved.

## Return value

The return value is **TRUE** if the function succeeds; **FALSE** if the function fails. If the function fails, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function to determine the reason for failure.

## Remarks

Call this function once with the *dwAction* parameter set to **DWACTION_ALLOCANDFILL** to allocate memory and fill a [CRYPT_PROVIDER_DEFUSAGE](https://learn.microsoft.com/windows/desktop/api/wintrust/ns-wintrust-crypt_provider_defusage) structure with information. Call this function again with the *dwAction* parameter set to **DWACTION_FREE** to free the allocated memory.

The default usage and callback information for a provider is registered by calling the [WintrustAddDefaultForUsage](https://learn.microsoft.com/windows/desktop/api/wintrust/nf-wintrust-wintrustadddefaultforusage) function.

## See also

[CRYPT_PROVIDER_DEFUSAGE](https://learn.microsoft.com/windows/desktop/api/wintrust/ns-wintrust-crypt_provider_defusage)

[CRYPT_PROVIDER_REGDEFUSAGE](https://learn.microsoft.com/windows/desktop/api/wintrust/ns-wintrust-crypt_provider_regdefusage)

[WintrustAddDefaultForUsage](https://learn.microsoft.com/windows/desktop/api/wintrust/nf-wintrust-wintrustadddefaultforusage)