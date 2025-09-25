# _D3DDDIARG_DECODEEXTENSIONEXECUTE structure

## Description

The D3DDDIARG_DECODEEXTENSIONEXECUTE structure describes a nonstandard Microsoft DirectX Video Acceleration (VA) decode operation to perform.

## Members

### `hDecode` [in]

A handle to the DirectX VA decode device. The user-mode display driver returns this handle in a call to its [CreateDecodeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createdecodedevice) function.

### `Function` [in]

A specific decode operation to perform. The possible values for this member are defined by the nonstandard decode device.

### `pPrivateInput` [in]

A pointer to a [DXVADDI_PRIVATEDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_privatedata) structure that contains data that the driver requires to perform the decode operation.

### `pPrivateOutput` [out]

A pointer to a DXVADDI_PRIVATEDATA structure that contains data about the decode operation that the driver returns.

### `NumBuffers` [in]

The number of buffers in the list that is pointed to by **pBuffers**.

### `pBuffers`

 [in] A pointer to a list of [DXVADDI_PRIVATEBUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_privatebuffer) structures that describe private buffers that a nonstandard decoder uses to perform a decode operation.

## See also

[CreateDecodeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createdecodedevice)

[DXVADDI_PRIVATEBUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_privatebuffer)

[DXVADDI_PRIVATEDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_privatedata)

[DecodeExtensionExecute](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_decodeextensionexecute)