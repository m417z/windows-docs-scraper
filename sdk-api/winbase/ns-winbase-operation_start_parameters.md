# OPERATION_START_PARAMETERS structure

## Description

This structure is used by the [OperationStart](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-operationstart) function.

## Members

### `Version`

This parameter should be initialized to the **OPERATION_API_VERSION** value defined in the Windows SDK.

| Value | Meaning |
| --- | --- |
| **OPERATION_API_VERSION**<br><br>1 | This API was introduced in Windows 8 and Windows Server 2012 as version 1. |

### `OperationId`

Each operation has an [OPERATION_ID](https://learn.microsoft.com/previous-versions/windows/desktop/oprec/operation-id) namespace that is unique for each process. If two applications both use the same **OPERATION_ID** value to identify two operations, the system maintains separate contexts for each operation.

### `Flags`

The value of this parameter can include any combination of the following values.

| Value | Meaning |
| --- | --- |
| **OPERATION_START_TRACE_CURRENT_THREAD**<br><br>1 | Specifies that the system should only track the activities of the calling thread in a multi-threaded application. Specify this flag when the operation is performed on a single thread to isolate its activity from other threads in the process. |

## See also

[OPERATION_END_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-operation_end_parameters)

[OPERATION_ID](https://learn.microsoft.com/previous-versions/windows/desktop/oprec/operation-id)

[Operation Recorder](https://learn.microsoft.com/previous-versions/windows/desktop/oprec/-operation-portal)

[OperationEnd](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-operationend)

[OperationStart](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-operationstart)