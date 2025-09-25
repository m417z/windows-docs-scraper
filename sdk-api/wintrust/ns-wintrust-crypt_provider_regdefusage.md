# CRYPT_PROVIDER_REGDEFUSAGE structure

## Description

The **CRYPT_PROVIDER_REGDEFUSAGE** structure is used by the [WintrustAddDefaultForUsage](https://learn.microsoft.com/windows/desktop/api/wintrust/nf-wintrust-wintrustadddefaultforusage) function to register callback information about a provider's default usage.

## Members

### `cbStruct`

Size, in bytes, of this structure.

### `pgActionID`

GUID that specifies the provider's default action.

### `pwszDllName`

Pointer to the name of the provider DLL.

### `pwszLoadCallbackDataFunctionName`

Pointer to the name of the function that loads the callback data to be returned when the [WintrustGetDefaultForUsage](https://learn.microsoft.com/windows/desktop/api/wintrust/nf-wintrust-wintrustgetdefaultforusage) function is called with the *dwAction* parameter set to **DWACTION_ALLOCANDFILL**. This information also exists in the [WINTRUST_DATA](https://learn.microsoft.com/windows/desktop/api/wintrust/ns-wintrust-wintrust_data) structure.

### `pwszFreeCallbackDataFunctionName`

Pointer to the name of the function that frees allocated memory when the [WintrustGetDefaultForUsage](https://learn.microsoft.com/windows/desktop/api/wintrust/nf-wintrust-wintrustgetdefaultforusage) function is called with the *dwAction* parameter set to **DWACTION_FREE**. This information also exists in the [WINTRUST_DATA](https://learn.microsoft.com/windows/desktop/api/wintrust/ns-wintrust-wintrust_data) structure.

## See also

[CRYPT_PROVIDER_DEFUSAGE](https://learn.microsoft.com/windows/desktop/api/wintrust/ns-wintrust-crypt_provider_defusage)

[WINTRUST_DATA](https://learn.microsoft.com/windows/desktop/api/wintrust/ns-wintrust-wintrust_data)

[WintrustAddDefaultForUsage](https://learn.microsoft.com/windows/desktop/api/wintrust/nf-wintrust-wintrustadddefaultforusage)