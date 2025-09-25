# D3DKMTSetGammaRamp function

## Description

The **D3DKMTSetGammaRamp** function sets the gamma ramp.

## Parameters

### `unnamedParam1` [in]

A pointer to a [D3DKMT_SETGAMMARAMP](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_setgammaramp) structure that describes parameters for setting the gamma ramp.

## Return value

**D3DKMTSetGammaRamp** returns one of the following values:

| Return code | Description |
|--|--|
| STATUS_SUCCESS | The gamma ramp was successfully set. |
| STATUS_DEVICE_REMOVED | The graphics adapter was stopped. |
| STATUS_INVALID_PARAMETER | Parameters were validated and determined to be incorrect. |

This function might also return other **NTSTATUS** values.

## See also

[D3DKMT_SETGAMMARAMP](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_setgammaramp)