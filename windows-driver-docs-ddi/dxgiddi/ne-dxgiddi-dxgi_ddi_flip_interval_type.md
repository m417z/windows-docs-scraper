# DXGI_DDI_FLIP_INTERVAL_TYPE enumeration

## Description

The DXGI_DDI_FLIP_INTERVAL_TYPE enumeration type contains values that identify the type of flip that occurs in present operations.

## Constants

### `DXGI_DDI_FLIP_INTERVAL_IMMEDIATE`

Indicates to perform the flip immediately without waiting for a vertical sync to occur.

### `DXGI_DDI_FLIP_INTERVAL_ONE`

Indicates to perform the flip on every vertical sync.

### `DXGI_DDI_FLIP_INTERVAL_TWO`

Indicates to perform the flip on every other vertical sync.

### `DXGI_DDI_FLIP_INTERVAL_THREE`

Indicates to perform the flip on every third vertical sync.

### `DXGI_DDI_FLIP_INTERVAL_FOUR`

Indicates to perform the flip on every fourth vertical sync.

### `DXGI_DDI_FLIP_INTERVAL_IMMEDIATE_ALLOW_TEARING`

## See also

[DXGI_DDI_ARG_PRESENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_arg_present)