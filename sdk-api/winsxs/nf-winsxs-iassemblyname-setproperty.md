# IAssemblyName::SetProperty

## Description

The **SetProperty** method adds a name-value pair to the side-by-side assembly name. This method can change or delete the value of an existing name-value pair.

## Parameters

### `PropertyId` [in]

A property ID that represents the name-value pair. Valid property IDs are [ASM_NAME](https://learn.microsoft.com/windows/win32/api/winsxs/ne-winsxs-asm_name) enumeration values.

### `pvProperty` [in]

A pointer to a buffer that contains the value of the name-value pair.

### `cbProperty` [in, optional]

The size in bytes of the buffer specified by *pvProperty*. Set the value of this parameter to zero to remove the name-value pair from the assembly name.

## Return value

This method can return one of these values.

| Return value | Description |
| --- | --- |
| S_OK | The method succeeded. |
| S_FALSE | The method did not succeed. |
| E_UNEXPECTED | The method did not succeed. The [SetProperty](https://learn.microsoft.com/windows/desktop/api/winsxs/nf-winsxs-iassemblyname-setproperty) method was called after the [Finalize](https://learn.microsoft.com/windows/desktop/api/winsxs/nf-winsxs-iassemblyname-finalize) method. |

## See also

[IAssemblyName](https://learn.microsoft.com/windows/desktop/api/winsxs/nn-winsxs-iassemblyname)