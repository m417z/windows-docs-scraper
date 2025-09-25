# TcQueryFlowA function

## Description

The
**TcQueryFlow** function queries traffic control for the value of a specific flow parameter based on the name of the flow. The name of a flow can be retrieved from the
[TcEnumerateFlows](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcenumerateflows) function or from the
[TcGetFlowName](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcgetflownamea) function.

## Parameters

### `pFlowName` [in]

Name of the flow being queried.

### `pGuidParam` [in]

Pointer to the globally unique identifier (GUID) that corresponds to the flow parameter of interest. A list of traffic control's GUIDs can be found in
[GUID](https://learn.microsoft.com/previous-versions/windows/desktop/qos/guid).

### `pBufferSize` [in, out]

Pointer to the size of the client-provided buffer or the number of bytes used by traffic control. For input, points to the size of *Buffer*, in bytes. For output, points to the actual amount of buffer space written with returned flow-parameter data, in bytes.

### `Buffer` [out]

Pointer to the client-provided buffer in which the returned flow parameter is written.

## Return value

| Return code | Description |
| --- | --- |
| **NO_ERROR** | The function executed without errors. |
| **ERROR_INVALID_PARAMETER** | A parameter is invalid. |
| **ERROR_INSUFFICIENT_BUFFER** | The provided buffer is too small to hold the results. |
| **ERROR_NOT_SUPPORTED** | The requested GUID is not supported. |
| **ERROR_WMI_GUID_NOT_FOUND** | The device did not register for this GUID. |
| **ERROR_WMI_INSTANCE_NOT_FOUND** | The instance name was not found, likely because the flow or the interface is in the process of being closed. |

## Remarks

Use of the
**TcQueryFlow** function requires administrative privilege.

> [!NOTE]
> The traffic.h header defines TcQueryFlow as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[GUID](https://learn.microsoft.com/previous-versions/windows/desktop/qos/guid)

[TcEnumerateFlows](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcenumerateflows)

[TcGetFlowName](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcgetflownamea)