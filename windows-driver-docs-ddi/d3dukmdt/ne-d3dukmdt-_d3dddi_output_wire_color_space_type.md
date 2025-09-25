# _D3DDDI_OUTPUT_WIRE_COLOR_SPACE_TYPE enumeration

## Description

Specifies the final wire signaling color space values.

## Constants

### `D3DDDI_OUTPUT_WIRE_COLOR_SPACE_G22_P709`

See [D3DDDI_COLOR_SPACE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-d3dddi_color_space_type).

### `D3DDDI_OUTPUT_WIRE_COLOR_SPACE_RESERVED`

Reserved.

### `D3DDDI_OUTPUT_WIRE_COLOR_SPACE_G2084_P2020`

See [D3DDDI_COLOR_SPACE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-d3dddi_color_space_type).

### `D3DDDI_OUTPUT_WIRE_COLOR_SPACE_G22_P709_WCG`

This enum value starts at 30, so as not to be confused with the existing [D3DDDI_COLOR_SPACE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-d3dddi_color_space_type).

### `D3DDDI_OUTPUT_WIRE_COLOR_SPACE_G22_P2020`

Used by the OS only, graphics drivers should not expect this value.

### `D3DDDI_OUTPUT_WIRE_COLOR_SPACE_G2084_P2020_HDR10PLUS`

Used by the OS only, graphics drivers should not expect this value.

### `D3DDDI_OUTPUT_WIRE_COLOR_SPACE_G2084_P2020_DVLL`

Used by the OS only, graphics drivers should not expect this value.

## Remarks

>[!NOTE]
> This enum is intended to specify the final wire signaling color space values. Do not mix it with the enum values defined in [D3DDDI_COLOR_SPACE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-d3dddi_color_space_type), which are used to specify input color space for MPOs and other surfaces.