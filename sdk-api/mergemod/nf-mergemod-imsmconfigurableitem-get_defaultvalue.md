# IMsmConfigurableItem::get_DefaultValue

## Description

The
**get_DefaultValue** method retrieves the
[DefaultValue](https://learn.microsoft.com/windows/desktop/Msi/configurableitem-defaultvalue) property of the
[ConfigurableItem](https://learn.microsoft.com/windows/desktop/Msi/configurableitem-object) object.

## Parameters

### `DefaultValue` [out]

A pointer to a location in memory with the default value of a configurable item listed in the DefaultValue column of the
[ModuleConfiguration table](https://learn.microsoft.com/windows/desktop/Msi/moduleconfiguration-table). The client must free the **BSTR** when it is no longer required.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **E_FAIL** | No module is open. |
| **E_INVALIDARG** | Invalid argument. |
| **E_OUTOFMEMORY** | Out of memory. |
| **ERROR_FUNCTION_FAILED as HRESULT** | The function failed. |
| **ERROR_INVALID_HANDLE as HRESULT** | The function failed. |
| **S_OK** | The function succeeded. |

## See also

[IMsmConfigurableItem](https://learn.microsoft.com/windows/desktop/api/mergemod/nn-mergemod-imsmconfigurableitem)

[Merge Module Automation](https://learn.microsoft.com/windows/desktop/Msi/merge-module-automation)