# _D3DDDIARG_EXTENSIONEXECUTE structure

## Description

The D3DDDIARG_EXTENSIONEXECUTE structure describes a Microsoft DirectX Video Acceleration (VA) extension operation to perform.

## Members

### `hExtension` [in]

A handle to the DirectX VA extension device. The user-mode display driver returns this handle in a call to its [CreateExtensionDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createextensiondevice) function.

### `Function` [in]

A specific operation to perform. The possible values for this member are defined by the extension device.

### `pPrivateInput` [in]

A pointer to a [DXVADDI_PRIVATEDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_privatedata) structure that contains data that the driver requires to perform the extension operation.

### `pPrivateOutput` [in]

A pointer to a DXVADDI_PRIVATEDATA structure that contains data about the extension operation that the driver returns.

### `NumBuffers` [in]

The number of buffers in the list that is pointed to by **pBuffers**.

### `pBuffers`

 [in] A pointer to a list of [DXVADDI_PRIVATEBUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_privatebuffer) structures that describe private buffers that an extension device uses to perform an extended operation.

## See also

[CreateExtensionDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createextensiondevice)

[DXVADDI_PRIVATEBUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_privatebuffer)

[DXVADDI_PRIVATEDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_privatedata)

[ExtensionExecute](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_extensionexecute)