# IAssemblyName::IsEqual

## Description

The **IsEqual** method compares the current assembly name to another assembly name.

## Parameters

### `pName` [in]

A pointer to another [IAssemblyName](https://learn.microsoft.com/windows/desktop/api/winsxs/nn-winsxs-iassemblyname) instance, which is to be compared to the current assembly.

### `dwCmpFlags` [in]

Indicates which portion of the assembly names are to be compared. The value can be one of the options of the [ASM_CMP_FLAGS](https://learn.microsoft.com/windows/win32/api/winsxs/ne-winsxs-asm_cmp_flags) enumeration.

## Return value

This method can return one of these values.

| Return value | Description |
| --- | --- |
| S_OK | The specified portions of the names match. |
| S_FALSE | The specified portions of the names do not match. |

## See also

[IAssemblyName](https://learn.microsoft.com/windows/desktop/api/winsxs/nn-winsxs-iassemblyname)