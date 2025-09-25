# IDebugControl3::SetCodeLevel

## Description

The **SetCodeLevel** method sets the current code level and is mainly used when stepping through code.

## Parameters

### `Level` [in]

Specifies the current code level. *Level* can take one of the values in the following table.

| Value | Description |
| --- | --- |
| DEBUG_LEVEL_SOURCE | *Source mode*. When stepping through code on the target, the size of a single step will be a line of source code. |
| DEBUG_LEVEL_ASSEMBLY | *Assembly mode*. When stepping through code on the target, the size of a single step will be a single processor instruction. |

## Return value

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

For more information about the code level, see [Using Source Files](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-source-files).

## See also

[GetCodeLevel](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getcodelevel)

[IDebugControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol)

[IDebugControl2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol2)

[IDebugControl3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol3)