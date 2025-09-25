# IDebugSymbols2::GetModuleNameString

## Description

The **GetModuleNameString** method returns the name of the specified module.

## Parameters

### `Which` [in]

Specifies which of the module's names to return, possible values are:

| Value | Description |
| --- | --- |
| DEBUG_MODNAME_IMAGE | The image name. This is the name of the executable file, including the extension. Typically, the full path is included in user mode but not in kernel mode. |
| DEBUG_MODNAME_MODULE | The module name. This is usually just the file name without the extension. In a few cases, the module name differs significantly from the file name. |
| DEBUG_MODNAME_LOADED_IMAGE | The loaded image name. Unless Microsoft CodeView symbols are present, this is the same as the image name. |
| DEBUG_MODNAME_SYMBOL_FILE | The symbol file name. The path and name of the symbol file. If no symbols have been loaded, this is the name of the executable file instead. |
| DEBUG_MODNAME_MAPPED_IMAGE | The mapped image name. In most cases, this is **NULL**. If the debugger is mapping an image file (for example, during minidump debugging), this is the name of the mapped image. |

### `Index` [in]

Specifies the index of the module. If it is set to DEBUG_ANY_ID, the *Base* parameter is used to specify the location of the module instead.

### `Base` [in]

If *Index* is DEBUG_ANY_ID, specifies the location in the target's memory address space of the base of the module. Otherwise it is ignored.

### `Buffer` [out, optional]

Receives the name of the module. If *Buffer* is **NULL**, this information is not returned.

### `BufferSize` [in]

Specifies the size in characters of the buffer *Buffer*. This size includes the space for the '\0' terminating character.

### `NameSize` [out, optional]

Receives the size in characters of the module's name. This size includes the space for the '\0' terminating character. If *NameSize* is **NULL**, this information is not returned.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The method was successful. However, the size of the buffer was smaller than the size of the module's name so it was truncated to fit in the buffer. |

## Remarks

For more information about modules, see [Modules](https://learn.microsoft.com/windows-hardware/drivers/debugger/modules).

## See also

[GetModuleNames](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-getmodulenames)

[IDebugSymbols2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols2)

[IDebugSymbols3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols3)