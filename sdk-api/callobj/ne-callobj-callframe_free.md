# CALLFRAME_FREE enumeration

## Description

Determines the parameter type to be freed.

## Constants

### `CALLFRAME_FREE_NONE:0`

No values are freed.

### `CALLFRAME_FREE_IN:1`

The [in] parameters are freed. This includes both top-level pointers and the data they reference.

### `CALLFRAME_FREE_INOUT:2`

The data referenced by [in, out] parameters are freed. However, the top-level pointers, which are the actual parameter values, are not freed.

On the server side, this is typically used post-call, as in CALLFRAME_FREE_IN. On the client side, this is typically used when the server was not actually invoked (and so unmarshaling of return values was not attempted) or when unmarshaling of the return values failed.

### `CALLFRAME_FREE_OUT:4`

The data referenced by [out] parameters are freed. However, the top-level pointers, which are the actual parameter values, are not freed.

On the server side, this is typically used post-call, as in CALLFRAME_FREE_IN. On the client side, this is typically only used when unmarshaling of return values failed.

### `CALLFRAME_FREE_TOP_INOUT:8`

The [in, out] parameters are freed. This includes both top-level pointers and the data they reference.

### `CALLFRAME_FREE_TOP_OUT:16`

The [out] parameters are freed. This includes both top-level pointers and the data they reference.

### `CALLFRAME_FREE_ALL:31`

All [in], [out], and [in, out] parameters are freed. This includes both top-level pointers and the data they reference.

## See also

[ICallFrame::Free](https://learn.microsoft.com/windows/desktop/api/callobj/nf-callobj-icallframe-free)

[ICallFrame::FreeParam](https://learn.microsoft.com/windows/desktop/api/callobj/nf-callobj-icallframe-freeparam)