# _D3DKMT_DMM_ESCAPE structure

## Description

 Do not use the D3DKMT_DMM_ESCAPE structure; it is for testing purposes only.

The D3DKMT_DMM_ESCAPE structure describes how to control the display mode manager (DMM) in a call to the [D3DKMTEscape](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtescape) function.

## Members

### `Type`

### `ProvidedBufferSize`

actual size of Data[] array, in bytes.

### `MinRequiredBufferSize`

minimum required size of Data[] array to contain requested data.

### `Data`

## See also

[D3DKMTEscape](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtescape)

[D3DKMT_ESCAPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_escape)