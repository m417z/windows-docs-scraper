# KSTIME structure

## Description

The KSTIME structure specifies a time stamp that can be used to indicate stream position.

## Members

### `Time`

Specifies a time value. When using unscaled time, **Time** is in units of 100-nanoseconds. When using scaled time, **Time** is in units governed by the scale factor expressed in the **Numerator** and **Denominator** members. For more information about scaled and unscaled time, see **Remarks**.

### `Numerator`

Specifies the numerator of the scaling factor for a scaled time value. For a nonscaled value, this should be one. **Numerator** must not be zero.

### `Denominator`

Specifies the denominator of the scaling factor for a scaled time value. For a nonscaled value, this should be one. **Denominator** must not be zero.

## Remarks

Unscaled time stamps are in 100-nanosecond units. A data stream can use different units by specifying the numerator and denominator of a scale factor.