# _D3DDDI_HDR_METADATA_TYPE enumeration (d3dukmdt.h)

## Description

Defines the format of HDR metadata.

## Constants

### `D3DDDI_HDR_METADATA_TYPE_NONE`

No HDR metadata is present.

### `D3DDDI_HDR_METADATA_TYPE_HDR10`

The HDR metadata is defined using the [D3DDDI_HDR_METADATA_HDR10](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_hdr_metadata_hdr10) structure.

### `D3DDDI_HDR_METADATA_TYPE_HDR10PLUS`

The HDR metadata is defined using the [D3DDDI_HDR_METADATA_HDR10PLUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-d3dddi_hdr_metadata_hdr10plus) structure.

## Syntax

```cpp
typedef enum _D3DDDI_HDR_METADATA_TYPE {
  D3DDDI_HDR_METADATA_TYPE_NONE                 = 0,
  D3DDDI_HDR_METADATA_TYPE_HDR10                = 1
} D3DDDI_HDR_METADATA_TYPE;
```