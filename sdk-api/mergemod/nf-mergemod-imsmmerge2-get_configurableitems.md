# IMsmMerge2::get_ConfigurableItems

## Description

The
**get_ConfigurableItems** method retrieves the
[ConfigurableItems](https://learn.microsoft.com/windows/desktop/Msi/merge-configurableitems) property of the
[Merge](https://learn.microsoft.com/windows/desktop/Msi/merge-object) object.

## Parameters

### `ConfigurableItems` [out]

Pointer to a memory location containing another pointer to an **IMsmConfigurableItems** interface.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **E_INVALIDARG** | The *ConfigurableItems* pointer is **NULL** |
| **E_OUTOFMEMORY** | The system ran out of memory. |
| **S_OK** | The function succeeded. |

## See also

[Merge Module Automation](https://learn.microsoft.com/windows/desktop/Msi/merge-module-automation)