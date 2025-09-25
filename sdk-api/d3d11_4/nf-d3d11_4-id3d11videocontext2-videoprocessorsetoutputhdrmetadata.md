# ID3D11VideoContext2::VideoProcessorSetOutputHDRMetaData

## Description

Sets the HDR metadata describing the display on which the content will be presented.

## Parameters

### `pVideoProcessor` [in]

A pointer to the [ID3D11VideoProcessor](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videoprocessor) interface.

### `Type` [in]

The type of HDR metadata supplied.

### `Size` [in]

The size of the HDR metadata supplied in *pHDRMetaData*.

For **DXGI_HDR_METADATA_TYPE_NONE**, the size should be 0.

For **DXGI_HDR_METADATA_TYPE_HDR10**, the size is `sizeof(DXGI_HDR_METADATA_HDR10)`.

### `pHDRMetaData` [in]

Pointer to the metadata information.

For **DXGI_HDR_METADATA_TYPE_NONE**, this should be NULL.

For **DXGI_HDR_METADATA_TYPE_HDR10**, this is a pointer to a [DXGI_HDR_METADATA_HDR10](https://learn.microsoft.com/windows/desktop/api/dxgi1_5/ns-dxgi1_5-dxgi_hdr_metadata_hdr10) structure.

## Remarks

When processing an HDR stream, the driver may use this metadata optimize the video for the output display.

## See also

[ID3D11VideoContext2](https://learn.microsoft.com/windows/desktop/api/d3d11_4/nn-d3d11_4-id3d11videocontext2)

[ID3DVideoContext2](https://learn.microsoft.com/windows/desktop/api/d3d11_4/nn-d3d11_4-id3d11videocontext2)