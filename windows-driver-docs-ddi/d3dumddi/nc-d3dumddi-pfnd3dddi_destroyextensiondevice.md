# PFND3DDDI_DESTROYEXTENSIONDEVICE callback function

## Description

The **DestroyExtensionDevice** function releases resources for a Microsoft DirectX Video Acceleration (VA) extension device.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `hExtension`

A handle to the DirectX VA extension device that the [CreateExtensionDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createextensiondevice) function created.

## Return value

**DestroyExtensionDevice** should return S_OK or an appropriate error result if it cannot successfully release resources for the DirectX VA extension device.

## Remarks

The **DestroyExtensionDevice** function notifies the driver to destroy the handle to the DirectX VA extension device that the [CreateExtensionDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createextensiondevice) function previously created. The driver can then release resources that are associated with the DirectX VA extension device handle.

## See also

[CreateExtensionDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createextensiondevice)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)