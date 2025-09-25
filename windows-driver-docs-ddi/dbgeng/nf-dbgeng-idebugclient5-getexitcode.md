# IDebugClient5::GetExitCode

## Description

The **GetExitCode** method returns the exit code of the current process if that process has already run through to completion.

## Parameters

### `Code` [out]

Receives the exit code of the process. If the process is still running, *Code* will be set to STILL_ACTIVE.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The process is still running. |

## Remarks

This method is available only for live user-mode debugging.