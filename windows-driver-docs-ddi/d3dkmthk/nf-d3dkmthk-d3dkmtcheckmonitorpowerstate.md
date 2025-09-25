# D3DKMTCheckMonitorPowerState function

## Description

The **D3DKMTCheckMonitorPowerState** function verifies the power state of a monitor.

## Parameters

### `unnamedParam1` [in]

A pointer to a [D3DKMT_CHECKMONITORPOWERSTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_checkmonitorpowerstate) structure that describes the connection to the monitor for which to check the power state.

## Return value

**D3DKMTCheckMonitorPowerState** returns one of the following values:

| Return code | Description |
|--|--|
| STATUS_SUCCESS | The power state of the monitor was successfully verified. |
| STATUS_INVALID_PARAMETER | Parameters were validated and determined to be incorrect. |

This function might also return other **NTSTATUS** values.

## See also

[D3DKMT_CHECKMONITORPOWERSTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_checkmonitorpowerstate)