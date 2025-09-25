# _D3DKMT_UNREGISTERTRIMNOTIFICATION structure

## Description

**D3DKMT_UNREGISTERTRIMNOTIFICATION** is used with [D3DKMTUnregisterTrimNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtunregistertrimnotification) to remove a callback registration for a kernel mode device receiving notifications from a graphics framework (such as OpenGL).

## Members

### `Handle` [out]

The callback notification handle received from the call to [D3DKMTRegisterTrimNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtregistertrimnotification).

### `Callback`

## See also

[D3DKMTRegisterTrimNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtregistertrimnotification)

[D3DKMTUnregisterTrimNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtunregistertrimnotification)