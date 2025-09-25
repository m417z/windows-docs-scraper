## Description

Queries the support of the specified operation for the specified I/O ring.

## Parameters

### `ioRing`

An **HIORING** representing a handle to the I/O ring for which operation support is queried.

### `op`

A value from the [IORING_OP_CODE](https://learn.microsoft.com/windows/win32/api/ntioring_x/ne-ntioring_x-ioring_op_code) enumeration specifying the operation for which support is queried.

## Return value

Returns an HRESULT including, but not limitted to the following:

| Value | Description |
|-------|-------------|
| S_OK | The operation is supported. |
| S_FALSE | The operation is unsupported. |

## Remarks

Unknown operation codes are treated as unsupported. Invalid **HIORING** handles are treated as not supporting any operations. So, this method will not throw errors due to these conditions.

## See also