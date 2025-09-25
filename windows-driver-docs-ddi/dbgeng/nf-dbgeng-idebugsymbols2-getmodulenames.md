# IDebugSymbols2::GetModuleNames

## Description

The **GetModuleNames** method returns the names of the specified module.

## Parameters

### `Index` [in]

Specifies the index of the module whose names are requested. If it is set to DEBUG_ANY_ID, the module is specified by *Base*.

### `Base` [in]

Specifies the base address of the module whose names are requested. This parameter is only used if *Index* is set to DEBUG_ANY_ID.

### `ImageNameBuffer` [out, optional]

Receives the image name of the module. If *ImageNameBuffer* is **NULL**, this information is not returned.

### `ImageNameBufferSize` [in]

Specifies the size in characters of the buffer *ImageNameBuffer* in characters. This size includes the space for the '\0' terminating character.

### `ImageNameSize` [out, optional]

Receives the size in characters of the image name. This size includes the space for the '\0' terminating character. If *ImageNameSize* is **NULL**, this information is not returned.

### `ModuleNameBuffer` [out, optional]

Receives the module name of the module. If *ModuleNameBuffer* is **NULL**, this information is not returned.

### `ModuleNameBufferSize` [in]

Specifies the size in characters of the buffer *ModuleNameBuffer*. This size includes the space for the '\0' terminating character.

### `ModuleNameSize` [out, optional]

Receives the size in characters of the module name. This size includes the space for the '\0' terminating character. If *ModuleNameSize* is **NULL**, this information is not returned.

### `LoadedImageNameBuffer` [out, optional]

Receives the loaded image name of the module. If *LoadedImageNameBuffer* is **NULL**, this information is not returned.

### `LoadedImageNameBufferSize` [in]

Specifies the size in characters of the buffer *LoadedImageNameBuffer*. This size includes the space for the '\0' terminating character.

### `LoadedImageNameSize` [out, optional]

Receives the size in characters of the loaded image name. This size includes the space for the '\0' terminating character. If *LoadedImageNameSize* is **NULL**, this information is not returned.

## Return value

This method may also return other error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The method was successful. However, at least one of *ImageNameBuffer*, *ModuleNameBuffer*, or *LoadedImageNameBuffer* was too small for the corresponding name, so it was truncated. |
| **E_NOINTERFACE** | The specified module was not found. |

## Remarks

For more information about modules, see [Modules](https://learn.microsoft.com/windows-hardware/drivers/debugger/modules).

## See also

[GetModuleNameString](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-getmodulenamestring)

[IDebugSymbols](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols)

[IDebugSymbols2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols2)

[IDebugSymbols3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols3)