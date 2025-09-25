# IAssemblyName::GetDisplayName

## Description

The **GetDisplayName** method gets a string representation of the side-by-side assembly name.

## Parameters

### `szDisplayName` [out]

A pointer to a buffer that receives the string value that contains the assembly name.

### `pccDisplayName` [in, out]

When calling this method, set this parameter to the size of the buffer specified by **szDisplayName**. Specify the size in characters and include the null terminator. When the method returns, the value of *pccDisplayName* is the size of the name returned.

### `dwDisplayFlags` [in]

One or more of the options of the [ASM_DISPLAY_FLAGS](https://learn.microsoft.com/windows/win32/api/winsxs/ne-winsxs-asm_display_flags) enumeration to specify which portions of the assembly's name to include in the string representation of the assembly name. The default for *dwDisplayFlags* is 0, which returns all portions of the assembly's display name.

## Return value

This method can return one of these values.

| Return value | Description |
| --- | --- |
| S_OK | The method succeeded. |
| S_FALSE | The method did not succeed. |

## See also

[IAssemblyName](https://learn.microsoft.com/windows/desktop/api/winsxs/nn-winsxs-iassemblyname)