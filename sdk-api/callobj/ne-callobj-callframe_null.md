# CALLFRAME_NULL enumeration

## Description

Determines the parameter type to be freed.

## Constants

### `CALLFRAME_NULL_NONE:0`

No values are freed.

### `CALLFRAME_NULL_INOUT:2`

The data referenced by [in, out] parameters are freed.

### `CALLFRAME_NULL_OUT:4`

The data referenced by [out] parameters are freed.

### `CALLFRAME_NULL_ALL:6`

All [out] and [in, out] parameters are freed.

## See also

[ICallFrame::Free](https://learn.microsoft.com/windows/desktop/api/callobj/nf-callobj-icallframe-free)