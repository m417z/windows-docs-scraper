# IDebugRegisters2::GetFrameOffset2

## Description

The **GetFrameOffset2** method returns the location of the stack frame for the current function.

## Parameters

### `Source` [in]

Specifies the register source to query.

The possible values are listed in the following table.

| Value | Register source |
| --- | --- |
| DEBUG_REGSRC_DEBUGGEE | Fetch register information from the target. |
| DEBUG_REGSRC_EXPLICIT | Fetch register information from the current explicit [register context](https://learn.microsoft.com/windows-hardware/drivers/debugger/changing-contexts). |
| DEBUG_REGSRC_FRAME | Fetch register information from the current scope's register context. <br><br>**Note** Stack unwinding does not guarantee accurate updating of the register context, so the scope frame's register context might not be accurate in all cases. |

### `Offset` [out]

The location in the process's virtual address space of the stack frame for the current function.

## Return value

This list does not contain all the errors that might occur. For a list of possible errors, see [HRESULT Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values).

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

The meaning of the value that is returned by this method is architecture-specific.

The method [GetFrameOffset](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugregisters2-getframeoffset) performs the same task as this method but always uses the target as the register source.

For an overview of the [IDebugRegisters](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugregisters) interface and other register-related methods, see [Registers](https://learn.microsoft.com/windows-hardware/drivers/debugger/registers).

## See also

[GetFrameOffset](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugregisters2-getframeoffset)

[IDebugRegisters2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugregisters2)