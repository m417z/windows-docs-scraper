# INTERVAL_LIMIT_KIND enumeration

## Description

These values are returned by [IInterval::GetLimits](https://learn.microsoft.com/windows/desktop/api/structuredquery/nf-structuredquery-iinterval-getlimits) as pairs to specify a range with an upper and lower limit. **INTERVAL_LIMIT_KIND** identifies whether the ranges include or exclude the upper and lower values of the range, and whether a range begins or ends in infinity.

## Constants

### `ILK_EXPLICIT_INCLUDED:0`

The value is included in the range. For example, an integer range of numbers that is equal to or greater than 3 and less than or equal to 6 includes both 3 and 6. So the values 3 and 6 would both be returned with **ILK_EXPLICIT_INCLUDED**.

### `ILK_EXPLICIT_EXCLUDED`

The value bounds the range but is not included in the range. For example, an integer range that is greater than 3 but less than 6 excludes both 3 and 6. So the values would both be returned with **ILK_EXPLICIT_EXCLUDED**.

### `ILK_NEGATIVE_INFINITY`

This is typically used as a lower bound. The specified value is ignored because the range begins (or ends) at negative infinity. For example, an integer range that includes every value less than 6 would have **ILK_NEGATIVE_INFINITY** for the lower bound and 6 and **ILK_EXPLICIT_EXCLUDED** for the upper bound.

### `ILK_POSITIVE_INFINITY`

This is typically used as an upper bound. The specified value is ignored because the range begins (or ends) at positive infinity. For example, an integer range that includes every value greater than or equal to 3 would have **ILK_EXPLICIT_INCLUDED** and 3 for the lower bound and **ILK_POSITIVE_INFINITY** for the upper bound.