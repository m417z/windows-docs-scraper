# D3DKMTPollDisplayChildren function

## Description

The **D3DKMTPollDisplayChildren** function queries for connectivity status of all child devices of the given adapter.

## Parameters

### `unnamedParam1` [in]

A pointer to a [D3DKMT_POLLDISPLAYCHILDREN](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_polldisplaychildren) structure that describes the parameters for querying for connectivity status of the adapter's child devices.

## Return value

**D3DKMTPollDisplayChildren** returns one of the following values:

| Return code | Description |
|--|--|
| STATUS_SUCCESS | Connectivity status was successfully retrieved. |
| STATUS_DEVICE_REMOVED | The graphics adapter was stopped. |

This function might also return other **NTSTATUS** values.

## Remarks

The OpenGL installable client driver (ICD) calls **D3DKMTPollDisplayChildren** to query for connectivity status of all of the adapter's child devices. The ICD sets the **NonDestructiveOnly** member of [D3DKMT_POLLDISPLAYCHILDREN](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_polldisplaychildren) to indicate whether **D3DKMTPollDisplayChildren** should be destructive (that is, cause visual artifacts). For typical polling, the ICD should set **NonDestructiveOnly** to **TRUE** to prevent the screen from flickering.

New child devices are enumerated to the Plug and Play (PnP) manager when PnP detects them. The devices are then listed in the device manager. If PnP determines that a child device was removed, the device is reported as a surprise removal.

## See also

[D3DKMT_POLLDISPLAYCHILDREN](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_polldisplaychildren)