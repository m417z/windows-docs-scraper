# IDebugDataSpaces::WritePointersVirtual

## Description

The **WritePointersVirtual** method is a convenience method for writing pointers to the target's virtual address space.

## Parameters

### `Count` [in]

Specifies the number of pointers to write.

### `Offset` [in]

Specifies the location in the target's virtual address space at which to start writing the pointers.

### `Ptrs` [in]

Specifies the array of pointers to write. The number of elements in this array is *Count*.

## Return value

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | All the pointers in *Ptrs* were written to the target's memory. |

## Remarks

If the target uses 32-bit pointers, this method casts the specified 64-bit values into 32-bit pointers. Then it writes these pointers to the target's memory.

## See also

[IDebugDataSpaces](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugdataspaces)

[IDebugDataSpaces2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugdataspaces2)

[IDebugDataSpaces3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugdataspaces3)

[IDebugDataSpaces4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugdataspaces4)

[ReadPointersVirtual](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugdataspaces4-readpointersvirtual)

[WriteVirtual](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugdataspaces4-writevirtual)