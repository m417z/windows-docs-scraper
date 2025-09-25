# IDebugRegisters2::GetStackOffset2

## Description

The **GetStackOffset2** method returns the current thread's current stack location.

## Parameters

### `Source` [in]

Specifies the register source to query.

The possible values are listed in the following table.

| Value | Register source |
| --- | --- |
| DEBUG_REGSRC_DEBUGGEE | Fetch register information from the target. |
| DEBUG_REGSRC_EXPLICIT | Fetch register information from the current explicit [register context](https://learn.microsoft.com/windows-hardware/drivers/debugger/changing-contexts). |
| DEBUG_REGSRC_FRAME | Fetch register information from the current scope's register context.<br><br>**Note** Stack unwinding does not guarantee accurate updating of the register context, so the scope frame's register context might not be accurate in all cases. |

### `Offset` [out]

Receives the location in the process's virtual address space of the current thread's current stack.

## Return value

This list does not contain all the errors that might occur. For a list of possible errors, see [HRESULT Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values).

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## See also

[GetStackOffset](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugregisters2-getstackoffset)

[IDebugRegisters2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugregisters2)