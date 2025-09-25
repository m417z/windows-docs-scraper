# EncoderParameterValueType enumeration

## Description

The **EncoderParameterValueType** enumeration specifies data types for image codec (encoder/decoder) parameters. An element of this enumeration is assigned to the
[Type](https://learn.microsoft.com/previous-versions/ms534434(v=vs.85)) data member of an **EncoderParameter** object.

## Constants

### `EncoderParameterValueTypeByte:1`

Specifies that the parameter is an 8-bit unsigned integer.

### `EncoderParameterValueTypeASCII:2`

Specifies that the parameter is a null-terminated character string.

### `EncoderParameterValueTypeShort:3`

Specifies that the parameter is a 16-bit unsigned integer.

### `EncoderParameterValueTypeLong:4`

Specifies that the parameter is a 32-bit unsigned integer.

### `EncoderParameterValueTypeRational:5`

Specifies that the parameter is an array of two, 32-bit unsigned integers. The pair of integers represents a fraction. The first integer in the pair is the numerator, and the second integer in the pair is the denominator.

### `EncoderParameterValueTypeLongRange:6`

Specifies that the parameter is an array of two, 32-bit unsigned integers. The pair of integers represents a range of numbers. The first integer is the smallest number in the range, and the second integer is the largest number in the range.

### `EncoderParameterValueTypeUndefined:7`

Specifies that the parameter is an array of bytes that can hold values of any type.

### `EncoderParameterValueTypeRationalRange:8`

Specifies that the parameter is an array of four, 32-bit unsigned integers. The first two integers represent one fraction, and the second two integers represent a second fraction. The two fractions represent a range of rational numbers. The first fraction is the smallest rational number in the range, and the second fraction is the largest rational number in the range.

### `EncoderParameterValueTypePointer:9`

Specifies that the parameter is a pointer to a block of custom metadata.

## See also

[EncoderParameter](https://learn.microsoft.com/previous-versions/ms534434(v=vs.85))