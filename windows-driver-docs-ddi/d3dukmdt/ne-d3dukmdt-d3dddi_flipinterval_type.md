# D3DDDI_FLIPINTERVAL_TYPE enumeration

## Description

The D3DDDI_FLIPINTERVAL_TYPE enumeration type contains values that identify the type of flip that occurs in present operations.

## Constants

### `D3DDDI_FLIPINTERVAL_IMMEDIATE`

Indicates to perform the flip immediately without waiting for a vertical sync to occur.

### `D3DDDI_FLIPINTERVAL_ONE`

Indicates to perform the flip on every vertical sync.

### `D3DDDI_FLIPINTERVAL_TWO`

Indicates to perform the flip on every other vertical sync.

### `D3DDDI_FLIPINTERVAL_THREE`

Indicates to perform the flip on every third vertical sync.

### `D3DDDI_FLIPINTERVAL_FOUR`

Indicates to perform the flip on every fourth vertical sync.

### `D3DDDI_FLIPINTERVAL_IMMEDIATE_ALLOW_TEARING`

## See also

[DXGKARG_PRESENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_present)