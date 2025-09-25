# ID2D1DeviceContext2::CreateLookupTable3D

## Description

Creates a 3D lookup table for mapping a 3-channel input to a 3-channel output. The table data must be provided in 4-channel format.

## Parameters

### `precision`

Type: **[D2D1_BUFFER_PRECISION](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_buffer_precision)**

Precision of the input lookup table data.

### `extents` [in]

Type: **const UINT32***

Number of lookup table elements per dimension (X, Y, Z).

### `data` [in]

Type: **const BYTE***

Buffer holding the lookup table data.

### `dataCount`

Type: **UINT32**

Size of the lookup table data buffer.

### `strides` [in]

Type: **const UINT32***

An array containing two values. The first value is the size in bytes from one row (X dimension) of LUT data to the next.
The second value is the size in bytes from one LUT data plane (X and Y dimensions) to the next.

### `lookupTable` [out]

Type: **[ID2D1LookupTable3D](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1lookuptable3d)****

Receives the new lookup table instance.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

S_OK if successful, otherwise a failure HRESULT.

## See also

[ID2D1DeviceContext2](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1devicecontext2)