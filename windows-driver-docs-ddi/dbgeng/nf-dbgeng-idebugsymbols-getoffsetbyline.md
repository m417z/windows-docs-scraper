# IDebugSymbols::GetOffsetByLine

## Description

The **GetOffsetByLine** method returns the location of the instruction that corresponds to a specified line in the source code.

## Parameters

### `Line` [in]

Specifies the line number in the source file.

### `File` [in]

Specifies the file name of the source file.

### `Offset` [out]

Receives the location in the target's virtual address space of an instruction for the specified line.

## Return value

This method may also return other error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

A line in a source file might correspond to multiple instructions and this method can return any one of these instructions.

For more information about source files, see [Using Source Files](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-source-files).

## See also

[GetLineByOffset](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsymbols3-getlinebyoffset)

[IDebugSymbols](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols)

[IDebugSymbols2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols2)

[IDebugSymbols3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsymbols3)