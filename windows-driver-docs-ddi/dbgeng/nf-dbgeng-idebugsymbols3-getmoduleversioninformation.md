# IDebugSymbols3::GetModuleVersionInformation

## Description

The **GetModuleVersionInformation** method returns version information for the specified module.

## Parameters

### `Index` [in]

Specifies the index of the module. If it is set to DEBUG_ANY_ID, the *Base* parameter is used to specify the location of the module instead.

### `Base` [in]

If *Index* is DEBUG_ANY_ID, specifies the location in the target's memory address space of the base of the module. Otherwise it is ignored.

### `Item` [in]

Specifies the version information being requested. This string corresponds to the *lpSubBlock* parameter of the function **VerQueryValue**. For details on the **VerQueryValue** function, see the Platform SDK.

### `Buffer` [out, optional]

Receives the requested version information. If *Buffer* is **NULL**, this information is not returned.

### `BufferSize` [in]

Specifies the size in characters of the buffer *Buffer*. This size includes the space for the '\0' terminating character.

### `VerInfoSize` [out, optional]

Receives the size in characters of the version information. This size includes the space for the '\0' terminating character. If *VerInfoSize* is **NULL**, this information is not returned.

## Return value

This method may also return other error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The size of the buffer was smaller than the size of the version information. In this case the buffer is filled with the truncated version information. |
| **E_NOINTERFACE** | The specified module was not found. |

## Remarks

Module version information is available only for loaded modules and may not be available in all sessions.

For more information about modules, see [Modules](https://learn.microsoft.com/windows-hardware/drivers/debugger/modules).

## See also

[GetModuleByIndex](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-getmodulebyindex)

[GetModuleByOffset2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-getmodulebyoffset2)

[GetNumberModules](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-getnumbermodules)

[IDebugSymbols2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols2)

[IDebugSymbols3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols3)