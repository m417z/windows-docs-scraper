# FWP_DATA_TYPE enumeration

## Description

The [FWP_VALUE0](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_value0) or an [FWP_CONDITION_VALUE0](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_condition_value0)structure.

## Constants

### `FWP_EMPTY:0`

Indicates no data.

### `FWP_UINT8`

Indicates an unsigned 8-bit integer value.

### `FWP_UINT16`

Indicates an unsigned 16-bit integer value.

### `FWP_UINT32`

Indicates an unsigned 32-bit integer value.

### `FWP_UINT64`

Indicates an unsigned 64-bit integer value.

### `FWP_INT8`

Indicates a signed 8-bit integer value.

### `FWP_INT16`

Indicates a signed 16-bit integer value.

### `FWP_INT32`

Indicates a signed 32-bit integer value.

### `FWP_INT64`

Indicates a signed 64-bit integer value.

### `FWP_FLOAT`

Indicates a pointer to a single-precision floating-point value.

### `FWP_DOUBLE`

Indicates a pointer to a double-precision floating-point value.

### `FWP_BYTE_ARRAY16_TYPE`

Indicates a pointer to an [FWP_BYTE_ARRAY16](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_byte_array16) structure.

### `FWP_BYTE_BLOB_TYPE`

Indicates a pointer to an [FWP_BYTE_BLOB](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_byte_blob) structure.

### `FWP_SID`

Indicates a pointer to a SID.

### `FWP_SECURITY_DESCRIPTOR_TYPE`

Indicates a pointer to an [FWP_BYTE_BLOB](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_byte_blob) structure that describes a security descriptor.

### `FWP_TOKEN_INFORMATION_TYPE`

Indicates a pointer to an [FWP_BYTE_BLOB](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_byte_blob) structure that describes token information.

### `FWP_TOKEN_ACCESS_INFORMATION_TYPE`

Indicates a pointer to an [FWP_BYTE_BLOB](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_byte_blob) structure that describes token access information.

### `FWP_UNICODE_STRING_TYPE`

Indicates a pointer to a null-terminated unicode string.

### `FWP_BYTE_ARRAY6_TYPE`

Reserved.

### `FWP_BITMAP_INDEX_TYPE`

### `FWP_BITMAP_ARRAY64_TYPE`

### `FWP_SINGLE_DATA_TYPE_MAX:0xff`

Reserved for future use.

### `FWP_V4_ADDR_MASK`

Indicates a pointer to an [FWP_V4_ADDR_AND_MASK](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_v4_addr_and_mask) structure.

### `FWP_V6_ADDR_MASK`

Indicates a pointer to an [FWP_V6_ADDR_AND_MASK](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_v6_addr_and_mask) structure.

### `FWP_RANGE_TYPE`

Indicates a pointer to an [FWP_RANGE0](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_range0) structure.

### `FWP_DATA_TYPE_MAX`

Maximum value for testing purposes.

## Remarks

Not all data types are valid for each structure; see the tagged union
in each structure to determine which are allowed.

## See also

[FWP_BYTE_ARRAY16](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_byte_array16)

[FWP_BYTE_BLOB](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_byte_blob)

[FWP_CONDITION_VALUE0](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_condition_value0)

[FWP_RANGE0](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_range0)

[FWP_V4_ADDR_AND_MASK](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_v4_addr_and_mask)

[FWP_V6_ADDR_AND_MASK](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_v6_addr_and_mask)

[FWP_VALUE0](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_value0)