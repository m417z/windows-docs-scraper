# _D3DKMT_GETDEVICESTATE structure

## Description

The D3DKMT_GETDEVICESTATE structure describes parameters for retrieving the state of a device.

## Members

### `hDevice` [in]

A handle to the device that status is requested for.

### `StateType` [in]

A [D3DKMT_DEVICESTATE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ne-d3dkmthk-_d3dkmt_devicestate_type)-typed value that indicates the type of status to retrieve for the device.

### `ExecutionState` [out]

A [D3DKMT_DEVICEEXECUTION_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ne-d3dkmthk-_d3dkmt_deviceexecution_state)-typed value that indicates the execution status of the device. The union that is contained in D3DKMT_GETDEVICESTATE holds a value from this enumeration if the **StateType** member is D3DKMT_DEVICESTATE_EXECUTION.

### `PresentState` [in/out]

A [D3DKMT_DEVICEPRESENT_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_devicepresent_state) structure that describes parameters for retrieving the present status of the device. The union that is contained in D3DKMT_GETDEVICESTATE holds a structure of this type if the **StateType** member is D3DKMT_DEVICESTATE_PRESENT.

### `ResetState` [out]

A [D3DKMT_DEVICERESET_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_devicereset_state) structure that describes the reset status of the device. The union that is contained in D3DKMT_GETDEVICESTATE holds a structure of this type if the **StateType** member is D3DKMT_DEVICESTATE_RESET.

### `PresentStateDWM`

### `PageFaultState`

### `PresentQueueState`

## See also

[D3DKMTGetDeviceState](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtgetdevicestate)

[D3DKMT_DEVICEEXECUTION_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ne-d3dkmthk-_d3dkmt_deviceexecution_state)

[D3DKMT_DEVICEPRESENT_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_devicepresent_state)

[D3DKMT_DEVICERESET_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_devicereset_state)

[D3DKMT_DEVICESTATE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ne-d3dkmthk-_d3dkmt_devicestate_type)