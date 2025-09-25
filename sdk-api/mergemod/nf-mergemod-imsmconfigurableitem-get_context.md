# IMsmConfigurableItem::get_Context

## Description

The
**get_Context** method retrieves the
[Context](https://learn.microsoft.com/windows/desktop/Msi/configurableitem-context) property of the
[ConfigurableItem](https://learn.microsoft.com/windows/desktop/Msi/configurableitem-object) object.

## Parameters

### `Context` [out]

A pointer to a location in memory with the context of a configurable item listed in the context column of the
[ModuleConfiguration table](https://learn.microsoft.com/windows/desktop/Msi/moduleconfiguration-table). The client must free the **BSTR** when it is no longer needed.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |
| **S_OK** | The function succeeded. |
| **E_FAIL** | No module is open. |
| **E_OUTOFMEMORY** | Out of memory. |
| **ERROR_FUNCTION_FAILED as HRESULT** | The function failed. |
| **ERROR_INVALID_HANDLE as HRESULT** | The function failed. |

## See also

[IMsmConfigurableItem](https://learn.microsoft.com/windows/desktop/api/mergemod/nn-mergemod-imsmconfigurableitem)

[Merge Module Automation](https://learn.microsoft.com/windows/desktop/Msi/merge-module-automation)