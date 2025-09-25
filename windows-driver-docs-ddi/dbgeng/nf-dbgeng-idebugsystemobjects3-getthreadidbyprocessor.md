# IDebugSystemObjects3::GetThreadIdByProcessor

## Description

The **GetThreadIdByProcessor** method returns the engine thread ID for the kernel-mode virtual thread corresponding to the specified processor.

## Parameters

### `Processor` [in]

Specifies the processor corresponding to the desired thread.

### `Id` [out]

Receives the engine thread ID.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

This method is only available in kernel-mode debugging.

For more information about threads, see [Threads and Processes](https://learn.microsoft.com/windows-hardware/drivers/debugger/threads-and-processes).