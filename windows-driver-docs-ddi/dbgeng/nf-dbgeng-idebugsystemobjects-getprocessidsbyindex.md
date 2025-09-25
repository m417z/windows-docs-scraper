# IDebugSystemObjects::GetProcessIdsByIndex

## Description

The **GetProcessIdsByIndex** method returns the engine process ID and system process ID for the specified [processes](https://learn.microsoft.com/windows-hardware/drivers/debugger/controlling-threads-and-processes) in the current target.

## Parameters

### `Start` [in]

Specifies the index of the first process whose ID is requested.

### `Count` [in]

Specifies the number of processes whose IDs are requested.

### `Ids` [out, optional]

Receives the engine process IDs. If *Ids* is **NULL**, this information is not returned; otherwise, *Ids* is treated as an array of *Count* ULONG values.

### `SysIds` [out, optional]

Receives the system process IDs. If *SysIds* is **NULL**, this information is not returned; otherwise, *SysIds* is treated as an array of *Count* ULONG values.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

The index of the first process is zero. The index of the last process is the number of processes returned by [GetNumberProcesses](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsystemobjects4-getnumberprocesses) minus one.

For more information about processes, see [Threads and Processes](https://learn.microsoft.com/windows-hardware/drivers/debugger/threads-and-processes).