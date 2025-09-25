# IDebugSystemObjects3::GetThreadIdsByIndex

## Description

The **GetThreadIdsByIndex** method returns the engine and system thread IDs for the specified [threads](https://learn.microsoft.com/windows-hardware/drivers/debugger/controlling-threads-and-processes) in the current process.

## Parameters

### `Start` [in]

Specifies the index of the first thread whose IDs are requested.

### `Count` [in]

Specifies the number of threads whose IDs are requested.

### `Ids` [out, optional]

Receives the engine thread IDs. If *Ids* is **NULL**, this information is not returned; otherwise, *Ids* is treated as an array of *Count* ULONG values.

### `SysIds` [out, optional]

Receives the system thread IDs. If *SysIds* is **NULL**, this information is not returned; otherwise, *SysIds* is treated as an array of *Count* ULONG values.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

The index of the first thread is zero. The index of the last thread is the number of threads returned by [GetNumberThreads](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugsystemobjects4-getnumberthreads) minus one.

For more information about threads, see [Threads and Processes](https://learn.microsoft.com/windows-hardware/drivers/debugger/threads-and-processes).