# IDebugDataSpaces4::ReadPointersVirtual

## Description

The **ReadPointersVirtual** method is a convenience method for reading pointers from the target's virtual address space.

## Parameters

### `Count` [in]

Specifies the number of pointers to read.

### `Offset` [in]

Specifies the location in the target's virtual address space to start reading the pointers.

### `Ptrs` [out]

Specifies the array to store the pointers. The number of elements this array holds is *Count*.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | All the pointers were read from the target's memory and stored in *Ptrs*. |

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

## Remarks

This method reads from the memory from the target's virtual address space. The memory is then treated as a list of pointers. Any 32-bit pointers are then sign-extended to 64-bit values.

## See also

[IDebugDataSpaces](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugdataspaces)

[IDebugDataSpaces2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugdataspaces2)

[IDebugDataSpaces3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugdataspaces3)

[IDebugDataSpaces4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugdataspaces4)

[ReadVirtual](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugdataspaces4-readvirtual)

[WritePointersVirtual](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugdataspaces4-writepointersvirtual)