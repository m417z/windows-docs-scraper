# D3D11_VIDEO_DECODER_EXTENSION structure

## Description

Contains driver-specific data for the [ID3D11VideoContext::DecoderExtension](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videocontext-decoderextension) method.

## Members

### `Function`

The function number. This number identifies the operation to perform. Currently no function numbers are defined.

### `pPrivateInputData`

A pointer to a buffer that contains input data for the driver.

### `PrivateInputDataSize`

The size of the **pPrivateInputData** buffer, in bytes.

### `pPrivateOutputData`

A pointer to a buffer that the driver can use to write output data.

### `PrivateOutputDataSize`

The size of the **pPrivateOutputData** buffer, in bytes.

### `ResourceCount`

The number of elements in the **ppResourceList** array. If **ppResourceList** is **NULL**, set **ResourceCount** to zero.

### `ppResourceList`

The address of an array of [ID3D11Resource](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11resource) pointers. Use this member to pass Direct3D resources to the driver.

## Remarks

The exact meaning of each structure member depends on the value of **Function**.

## See also

[Direct3D 11 Video Structures](https://learn.microsoft.com/windows/desktop/medfound/direct3d-11-video-structures)