# IAssemblyName::GetProperty

## Description

The **GetProperty** method gets the value of a name-value pair in the assembly name.

## Parameters

### `PropertyId` [in]

A property ID that represents the name-value pair. Valid property IDs are [ASM_NAME](https://learn.microsoft.com/windows/win32/api/winsxs/ne-winsxs-asm_name) enumeration values.

### `pvProperty` [out]

A pointer to a buffer that receives the value of the name-value pair.

### `pcbProperty` [in, out]

The size in bytes of the buffer specified by *pvProperty*. The value is zero if this property is not set.

## Return value

This method can return one of these values.

| Return value | Description |
| --- | --- |
| S_OK | The method succeeded. |
| S_FALSE | The method did not succeed. |

## See also

[IAssemblyName](https://learn.microsoft.com/windows/desktop/api/winsxs/nn-winsxs-iassemblyname)