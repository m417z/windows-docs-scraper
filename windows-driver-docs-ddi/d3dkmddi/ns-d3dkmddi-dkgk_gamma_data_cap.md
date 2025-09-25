# DKGK_GAMMA_DATA_CAP structure

## Description

Gamma data caps.

## Members

### `DataType`

A [DXGK_GAMMA_DATA_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-dxgk_gamma_data_type) enumeration value.

### `BitCountOfInteger`

Bit count of integer if *DataType* is fixed-point(**DXGK_GAMMA_DATA_TYPE_FIXED_POINT**).

### `BitCountOfFraction`

Bit count of fraction if *DataType* is fixed-point(**DXGK_GAMMA_DATA_TYPE_FIXED_POINT**).

### `BitCountOfExponent`

Bit count of exponent if the *DataType* is float(**DXGK_GAMMA_DATA_TYPE_FLOAT**).

### `BitCountOfMantissa`

Bit count of mantissa if the *DataType* is float(**DXGK_GAMMA_DATA_TYPE_FLOAT**).

### `Value`

### `NumericRangeMin`

Minimum number of gamma data.

### `NumericRangeMax`

Maximum number of gamma data.

## Remarks

## See also