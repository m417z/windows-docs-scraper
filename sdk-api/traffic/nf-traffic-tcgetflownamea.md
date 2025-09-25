# TcGetFlowNameA function

## Description

The
**TcGetFlowName** function provides the name of a flow that has been created by the calling client. Flow properties and other characteristics of flows are provided based on the name of a flow. Flow names can also be retrieved by a call to the
[TcEnumerateFlows](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcenumerateflows) function.

## Parameters

### `FlowHandle` [in]

Handle for the flow.

### `StrSize` [in]

Size of the string buffer provided in *pFlowName*.

### `pFlowName` [out]

Pointer to the output buffer holding the flow name.

## Return value

| Return code | Description |
| --- | --- |
| **NO_ERROR** | The function executed without errors. |
| **ERROR_INVALID_HANDLE** | The flow handle is invalid. |
| **ERROR_INVALID_PARAMETER** | One of the parameters is invalid. |
| **ERROR_INSUFFICIENT_BUFFER** | The buffer is too small to contain the results. |

## Remarks

Use of the
**TcGetFlowName** function requires administrative privilege.

> [!NOTE]
> The traffic.h header defines TcGetFlowName as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[TcEnumerateFlows](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcenumerateflows)