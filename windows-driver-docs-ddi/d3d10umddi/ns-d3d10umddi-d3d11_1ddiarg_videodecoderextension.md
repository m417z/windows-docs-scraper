# D3D11_1DDIARG_VIDEODECODEREXTENSION structure

## Description

Specifies driver-specific data for the extended Microsoft DirectX Video Acceleration (DXVA) decoding function that is provided by a call to the [VideoDecoderExtension](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videodecoderextension) function.

## Members

### `Function`

The function number. This number identifies the operation to perform. Currently no function numbers are defined.

### `pPrivateInputData`

A pointer to a buffer that contains input data for the driver.

### `PrivateInputDataSize`

The size of the buffer pointed to by **pPrivateInputData**, in bytes.

### `pPrivateOutputData`

A pointer to a buffer that the driver can use to write output data.

### `PrivateOutputDataSize`

The size of the buffer pointed to by **pPrivateOutputData**, in bytes.

### `ResourceCount`

The number of elements in the **pResourceList** array. If **pResourceList** is **NULL**, set **ResourceCount** to zero.

### `pResourceList`

A pointer to an array of resource handles. Use this member to pass Direct3D resources to the driver.

## Remarks

The exact meaning of each structure member depends on the value of **Function**.

## See also

[VideoDecoderExtension](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d11_1ddi_videodecoderextension)