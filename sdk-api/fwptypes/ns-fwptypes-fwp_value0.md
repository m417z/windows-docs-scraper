## Description

The **FWP_VALUE0** structure defines a data value that can be one of a number of different data types.

## Members

### `type`

The type of data for this value.

See [FWP_DATA_TYPE](https://learn.microsoft.com/windows/desktop/api/fwptypes/ne-fwptypes-fwp_data_type) for more information.

### `uint8`

case(FWP_UINT8)

An unsigned 8-bit integer.

### `uint16`

case(FWP_UINT16)

An unsigned 16-bit integer.

### `uint32`

case(FWP_UINT32)

An unsigned 32-bit integer.

### `uint64`

case(FWP_UINT64)

A pointer to an unsigned 64-bit integer.

### `int8`

case(FWP_INT8)

A signed 8-bit integer.

### `int16`

case(FWP_INT16)

A signed 16-bit integer.

### `int32`

case(FWP_INT32)

A signed 32-bit integer.

### `int64`

case(FWP_INT64)

A pointer to a signed 64-bit integer.

### `float32`

case(FWP_FLOAT)

A single-precision floating-point value.

### `double64`

case(FWP_DOUBLE)

A pointer to a double-precision floating-point value.

### `byteArray16`

case(FWP_BYTE_ARRAY16_TYPE)

A pointer to a [FWP_BYTE_ARRAY16](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_byte_array16) structure.

### `byteBlob`

case(FWP_BYTE_BLOB_TYPE)

A pointer to a [FWP_BYTE_BLOB](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_byte_blob) structure.

### `sid`

case(FWP_SID)

A pointer to a SID.

### `sd`

case(FWP_SECURITY_DESCRIPTOR_TYPE)

A pointer to a security descriptor contained in a [FWP_BYTE_BLOB](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_byte_blob) structure. The data contained in the blob is a [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure.

### `tokenInformation`

case(FWP_TOKEN_INFORMATION_TYPE)

A pointer to an [FWP_TOKEN_INFORMATION](https://learn.microsoft.com/windows/win32/api/fwptypes/ns-fwptypes-fwp_token_information) structure.

### `tokenAccessInformation`

case(FWP_TOKEN_ACCESS_INFORMATION_TYPE)

A pointer to token access information contained in a [FWP_BYTE_BLOB](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_byte_blob) structure. The data contained in the blob is a [TOKEN_ACCESS_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_access_information) structure.

### `unicodeString`

case(FWP_UNICODE_STRING_TYPE)

A pointer to a null-terminated unicode string.

### `byteArray6`

case(FWP_BYTE_ARRAY6_TYPE)

Reserved.

### `bitmapArray64`

TBD

## Remarks

For the unnamed union, switch_type(FWP_DATA_TYPE), switch_is(type).

This is primarily used to supply incoming values to the
filter engine.

When IP addresses are stored in FWP_UINT32 format or when IP port is stored in FWP_UINT16 format, they are stored in host-order not network-order.

**FWP_VALUE0** is a specific implementation of FWP_VALUE. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[FWP_BYTE_ARRAY16](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_byte_array16)

[FWP_BYTE_BLOB](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_byte_blob)

[FWP_DATA_TYPE](https://learn.microsoft.com/windows/desktop/api/fwptypes/ne-fwptypes-fwp_data_type)

[Windows Filtering Platform API structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)