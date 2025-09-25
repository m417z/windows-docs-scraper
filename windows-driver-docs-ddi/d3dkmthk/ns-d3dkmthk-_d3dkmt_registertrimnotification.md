# _D3DKMT_REGISTERTRIMNOTIFICATION structure

## Description

**D3DKMT_REGISTERTRIMNOTIFICATION** is used with [D3DKMTRegisterTrimNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtregistertrimnotification) to register a callback for a kernel mode device for notifications from a graphics framework (such as OpenGL).

## Members

### `AdapterLuid` [in]

Luid of the adapter which the device created.

### `hDevice` [in]

Device to trim the residency list for.

### `Callback` [in]

Pointer to the callback function.

### `Context` [in]

Caller-supplied context for callback.

### `Handle` [out]

Handle that will be used to unregister the callback with [D3DKMTUnregisterTrimNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtunregistertrimnotification).

## See also

[D3DKMTRegisterTrimNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtregistertrimnotification)

[D3DKMTUnregisterTrimNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtunregistertrimnotification)