# ID3D11VideoContext2::VideoProcessorGetStreamHDRMetaData

## Description

Gets the HDR metadata associated with the video stream.

## Parameters

### `pVideoProcessor` [in]

A pointer to the [ID3D11VideoProcessor](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videoprocessor) interface.

### `StreamIndex` [in]

Identifies the input stream.

### `pType` [out]

The type of the HDR metadata currently associated with the stream.

### `Size` [in]

The size of the memory referenced by *pHDRMetaData*.

If *pHDRMetaData* is NULL, *Size* should be 0.

### `pMetaData` [out]

Pointer to a buffer that receives the HDR metadata.

This parameter can be NULL.

## Remarks

This can be called multiple times, the first time to get the *Type* (in which case *Size* can be 0 and *pHDRMetaData* can be NULL) and then again to with non-NULL values to retrieve the actual metadata.

## See also

[ID3D11VideoContext2](https://learn.microsoft.com/windows/desktop/api/d3d11_4/nn-d3d11_4-id3d11videocontext2)

[ID3DVideoContext2](https://learn.microsoft.com/windows/desktop/api/d3d11_4/nn-d3d11_4-id3d11videocontext2)