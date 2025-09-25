# OPERATION_END_PARAMETERS structure

## Description

This structure is used by the [OperationEnd](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-operationend) function.

## Members

### `Version`

This parameter should be initialized to the **OPERATION_API_VERSION** defined in the Windows SDK.

| Value | Meaning |
| --- | --- |
| **OPERATION_API_VERSION**<br><br>1 | This API was introduced in Windows 8 and Windows Server 2012 as version 1. |

### `OperationId`

Each operation has an [OPERATION_ID](https://learn.microsoft.com/previous-versions/windows/desktop/oprec/operation-id) namespace that is unique for each process. If two applications both use the same **OPERATION_ID** value to identify two operations, the system maintains separate contexts for each operation.

### `Flags`

The value of this parameter can include any combination of the following values.

| Value | Meaning |
| --- | --- |
| **OPERATION_END_DISCARD**<br><br>1 | Specifies that the system should discard the information it has been tracking for this operation. Specify this flag when the operation either fails or does not follow the expected sequence of steps. |

## See also

[OPERATION_ID](https://learn.microsoft.com/previous-versions/windows/desktop/oprec/operation-id)

[OPERATION_START_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-operation_start_parameters)

[Operation Recorder](https://learn.microsoft.com/previous-versions/windows/desktop/oprec/-operation-portal)

[OperationEnd](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-operationend)

[OperationStart](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-operationstart)