# OperationEnd function

## Description

Notifies the system that the application is about to end an operation

Every call to [OperationStart](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-operationstart) must be followed by a call to **OperationEnd**, otherwise the operation's record of file access patterns is discarded after 10 seconds.

## Parameters

### `OperationEndParams` [in]

An [_OPERATION_END_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-operation_end_parameters) structure that specifies **VERSION**, **OPERATION_ID** and **FLAGS**.

## Return value

**TRUE** for all valid parameters and **FALSE** otherwise. To get extended error information, call **GetLastError**.

## Remarks

The version of the [_OPERATION_END_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-operation_end_parameters) structure is defined as **OPERATION_API_VERSION** in the Windows SDK.

The **OperationEnd** function is safe to call on any thread.

## See also

[OPERATION_ID](https://learn.microsoft.com/previous-versions/windows/desktop/oprec/operation-id)

[Operation Recorder](https://learn.microsoft.com/previous-versions/windows/desktop/oprec/-operation-portal)

[OperationStart](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-operationstart)

[_OPERATION_END_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-operation_end_parameters)

[_OPERATION_START_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-operation_start_parameters)