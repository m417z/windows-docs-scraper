# DXVA2_DecodeExtensionData structure

## Description

Contains private data for the [IDirectXVideoDecoder::Execute](https://learn.microsoft.com/windows/desktop/api/dxva2api/nf-dxva2api-idirectxvideodecoder-execute) method.

## Members

### `Function`

Function number. This can be zero if this argument is the default or is ignored.

### `pPrivateInputData`

Pointer to private input data passed to the driver.

### `PrivateInputDataSize`

Length of the private input data, in bytes.

### `pPrivateOutputData`

Pointer to private output data passed from the driver to the decoder.

### `PrivateOutputDataSize`

Size of the private output data, in bytes.

## Remarks

This structure corresponds to parameters of the **IAMVideoAccelerator::Execute** method in DirectX Video Acceleration (DXVA) version 1.

## See also

[DXVA2_DecodeExecuteParams](https://learn.microsoft.com/windows/desktop/api/dxva2api/ns-dxva2api-dxva2_decodeexecuteparams)

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)