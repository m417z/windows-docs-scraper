# IDebugSymbols2::GetTypeSize

## Description

The **GetTypeSize** method returns the number of bytes of memory an instance of the specified type requires.

## Parameters

### `Module` [in]

Specifies the base address of the module containing the type. For more information, see [Modules](https://learn.microsoft.com/windows-hardware/drivers/debugger/modules).

### `TypeId` [in]

Specifies the type ID of the type.

### `Size` [out]

Receives the number of bytes of memory an instance of the specified type requires.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful |

## Remarks

For more information about symbols, see [Symbols](https://learn.microsoft.com/windows-hardware/drivers/debugger/symbols4).

## See also

[GetTypeName](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-gettypename)

[IDebugSymbols](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols)

[IDebugSymbols2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols2)

[IDebugSymbols3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols3)