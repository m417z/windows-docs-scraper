# IDebugDataSpaces4::FillVirtual

## Description

The **FillVirtual** method writes a pattern of bytes to the target's virtual memory. The pattern is written repeatedly until the specified memory range is filled.

## Parameters

### `Start` [in]

Specifies the location in the target's virtual address space at which to start writing the pattern.

### `Size` [in]

Specifies how many bytes to write to the target's memory.

### `Pattern` [in]

Specifies the memory location of the pattern.

### `PatternSize` [in]

Specifies the size in bytes of the pattern.

### `Filled` [out, optional]

Receives the number of bytes written. If it is set to **NULL**, this information isn't returned.

## Return value

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

This method writes the pattern to the target's memory as many times as will fit in *Size* bytes.

If the final copy of the pattern will not completely fit into the memory range, it will only be partially written. This includes the case where the size of the pattern is larger than the value of *Size*, and the extra bytes in the pattern are ignored.

## See also

[IDebugDataSpaces2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugdataspaces2)

[IDebugDataSpaces3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugdataspaces3)

[IDebugDataSpaces4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugdataspaces4)

[WriteVirtual](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugdataspaces4-writevirtual)