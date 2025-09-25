# TcSetFlowA function

## Description

The
**TcSetFlow** function sets individual parameters for a given flow.

## Parameters

### `pFlowName` [in]

Name of the flow being set. The value for this parameter is obtained by a previous call to the
[TcEnumerateFlows](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcenumerateflows) function or the
[TcGetFlowName](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcgetflownamea) function.

### `pGuidParam` [in]

Pointer to the globally unique identifier (GUID) that corresponds to the parameter to be set. A list of available GUIDs can be found in
[GUID](https://learn.microsoft.com/previous-versions/windows/desktop/qos/guid).

### `BufferSize` [in]

Size of the client-provided buffer, in bytes.

### `Buffer` [in]

Pointer to a client-provided buffer. Buffer must contain the value to which the traffic control parameter provided in *pGuidParam* should be set.

## Return value

The
**TcSetFlow** function has the following return values.

| Return code | Description |
| --- | --- |
| **NO_ERROR** | The function executed without errors. |
| **ERROR_NOT_READY** | The flow is currently being modified. |
| **ERROR_NOT_ENOUGH_MEMORY** | The buffer size was insufficient for the GUID. |
| **ERROR_INVALID_PARAMETER** | Invalid parameter. |
| **ERROR_NOT_SUPPORTED** | Setting the GUID for the provided flow is not supported. |
| **ERROR_WMI_INSTANCE_NOT_FOUND** | The instance name was not found, likely due to the flow or the interface being in the process of being closed. |
| **ERROR_WMI_GUID_NOT_FOUND** | The device did not register for this GUID. |

## Remarks

Use of the
**TcSetFlow** function requires administrative privilege.

> [!NOTE]
> The traffic.h header defines TcSetFlow as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).