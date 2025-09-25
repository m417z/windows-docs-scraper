# DXGI_HDR_METADATA_TYPE enumeration

## Description

Specifies the header metadata type.

## Constants

### `DXGI_HDR_METADATA_TYPE_NONE:0`

Indicates there is no header metadata.

### `DXGI_HDR_METADATA_TYPE_HDR10:1`

Indicates the header metadata is held by a [DXGI_HDR_METADATA_HDR10](https://learn.microsoft.com/windows/desktop/api/dxgi1_5/ns-dxgi1_5-dxgi_hdr_metadata_hdr10) structure.

### `DXGI_HDR_METADATA_TYPE_HDR10PLUS:2`

## Remarks

This enum is used by the [SetHDRMetaData](https://learn.microsoft.com/windows/desktop/api/dxgi1_5/nf-dxgi1_5-idxgiswapchain4-sethdrmetadata) method.

## See also

[DXGI 1.5 Improvements](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-1-5-improvements)

[DXGI Enumerations](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-enums)