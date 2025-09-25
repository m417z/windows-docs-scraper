# IDebugSystemObjects4::GetSystemIdsByIndex

## Description

The **GetSystemIdsByIndex** method returns the engine target IDs for the specified targets.

## Parameters

### `Start` [in]

Specifies the index of the first target whose target ID is requested.

### `Count` [in]

Specifies the number of processes whose IDs are requested.

### `Ids` [out]

Receives the engine target IDs. If *Ids* is **NULL**, this information is not returned; otherwise, *Ids* is treated as an array of *Count* ULONG values.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

The index of the first target is zero. The index of the last target is the number of targets returned by [GetNumberSystems](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsystemobjects4-getnumbersystems) minus one.

## See also

[Debugging Session and Execution Model](https://learn.microsoft.com/windows-hardware/drivers/debugger/debugging-session-and-execution-model)

[IDebugSystemObjects3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsystemobjects3)

[IDebugSystemObjects4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsystemobjects4)