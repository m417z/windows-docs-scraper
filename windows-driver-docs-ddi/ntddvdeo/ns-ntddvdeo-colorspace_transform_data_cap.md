# COLORSPACE_TRANSFORM_DATA_CAP structure

## Description

The colorspace transform data cap.

## Members

### `DataType`

A [COLORSPACE_TRANSFORM_DATA_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ne-ntddvdeo-colorspace_transform_data_type) enumeration.

### `BitCountOfInteger`

Bit count of integer if *DataType* is fixed-point(COLORSPACE_TRANSFORM_DATA_TYPE_FIXED_POINT).

### `BitCountOfFraction`

Bit count of fraction if *DataType* is fixed-point(COLORSPACE_TRANSFORM_DATA_TYPE_FIXED_POINT).

### `BitCountOfExponent`

Bit count of exponent if the *DataType* is float(COLORSPACE_TRANSFORM_DATA_TYPE_FLOAT).

### `BitCountOfMantissa`

Bit count of mantissa if the DataType is float(COLORSPACE_TRANSFORM_DATA_TYPE_FLOAT).

### `Value`

### `NumericRangeMin`

Minimum number of gamma data.

### `NumericRangeMax`

Maximum number of gamma data.

## Remarks

## See also