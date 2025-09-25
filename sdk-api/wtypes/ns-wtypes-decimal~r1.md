# DECIMAL structure

## Description

Represents a decimal data type that provides a sign and scale for a number (as in coordinates.)

Decimal variables are stored as 96-bit (12-byte) unsigned integers scaled by a variable power of 10. The power of 10 scaling factor specifies the number of digits to the right of the decimal point, and ranges from 0 to 28.

## Members

### `wReserved`

Reserved.

### `DUMMYUNIONNAME`

### `DUMMYSTRUCTNAME`

### `scale`

The number of decimal places for the number. Valid values are from 0 to 28. So 12.345 is represented as 12345 with a scale of 3.

### `sign`

Indicates the sign; 0 for positive numbers or DECIMAL_NEG for negative numbers. So -1 is represented as 1 with the DECIMAL_NEG bit set.

### `signscale`

The sign and number of decimal places.

### `Hi32`

The high 32 bits of the number.

### `DUMMYUNIONNAME2`

### `DUMMYSTRUCTNAME2`

### `Lo32`

The low 32 bits of the number.

### `Mid32`

The middle 32 bits of the number.

### `Lo64`

The low 32 bits of the number.

## Remarks

## See also