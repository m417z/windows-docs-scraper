# FWP_CONDITION_VALUE0 structure

## Description

The **FWP_CONDITION_VALUE0** structure contains values that are used in filter conditions when testing for matching filters.

## Members

### `type`

Specifies the data type of the condition value.

See [FWP_DATA_TYPE](https://learn.microsoft.com/windows/win32/api/fwptypes/ne-fwptypes-fwp_data_type) for more information.

### `uint8`

Available when **type** is FWP_UINT8.

An unsigned 8-bit integer.

### `uint16`

Available when **type** is FWP_UINT16.

An unsigned 16-bit integer.

### `uint32`

Available when **type** is FWP_UINT32.

An unsigned 32-bit integer.

### `uint64`

Available when **type** is FWP_UINT64.

A pointer to an unsigned 64-bit integer.

> [!NOTE]
> This value cannot be null.

### `int8`

Available when **type** is FWP_INT8.

A signed 8-bit integer.

### `int16`

Available when **type** is FWP_INT16.

A signed 16-bit integer.

### `int32`

Available when **type** is FWP_INT32.

A signed 32-bit integer.

### `int64`

Available when **type** is FWP_INT64.

A pointer to a signed 64-bit integer.

> [!NOTE]
> This value cannot be null.

### `float32`

Available when **type** is FWP_FLOAT.

A single-precision floating-point value.

### `double64`

Available when **type** is FWP_DOUBLE.

A pointer to a double-precision floating-point value.

> [!NOTE]
> This value cannot be null.

### `byteArray16`

Available when **type** is FWP_BYTE_ARRAY16_TYPE.

A pointer to a [FWP_BYTE_ARRAY16](https://learn.microsoft.com/windows/win32/api/fwptypes/ns-fwptypes-fwp_byte_array16) structure.

> [!NOTE]
> This value cannot be null.

### `byteBlob`

Available when **type** is FWP_BYTE_BLOB_TYPE.

A pointer to a [FWP_BYTE_BLOB](https://learn.microsoft.com/windows/win32/api/fwptypes/ns-fwptypes-fwp_byte_blob) structure.

> [!NOTE]
> [FWP_BYTE_BLOB](https://learn.microsoft.com/windows/win32/api/fwptypes/ns-fwptypes-fwp_byte_blob) structure cannot be null.

### `sid`

Available when **type** is FWP_SID.

A pointer to a security identifier (SID) structure.

> [!NOTE]
> This security identifier cannot be null.

### `sd`

Available when **type** is FWP_SECURITY_DESCRIPTOR_TYPE.

A pointer to a security descriptor contained in a [FWP_BYTE_BLOB](https://learn.microsoft.com/windows/win32/api/fwptypes/ns-fwptypes-fwp_byte_blob) structure.

> [!NOTE]
> Security descriptors cannot be null when used in filter conditions. Moreover, they need to be in self-relative format.

### `tokenInformation`

Available when **type** is FWP_TOKEN_INFORMATION_TYPE.

A pointer to token information contained in a [FWP_TOKEN_INFORMATION](https://learn.microsoft.com/windows/win32/api/fwptypes/ns-fwptypes-fwp_token_information) structure.

### `tokenAccessInformation`

Available when **type** is FWP_TOKEN_ACCESS_INFORMATION_TYPE.

A pointer to token access information contained in a [FWP_BYTE_BLOB](https://learn.microsoft.com/windows/win32/api/fwptypes/ns-fwptypes-fwp_byte_blob) structure.

> [!NOTE]
> [FWP_BYTE_BLOB](https://learn.microsoft.com/windows/win32/api/fwptypes/ns-fwptypes-fwp_byte_blob) structure cannot be null.

### `unicodeString`

Available when **type** is FWP_UNICODE_STRING_TYPE.

A pointer to a null-terminated unicode string.

> [!NOTE]
> This value cannot be null.

### `byteArray6`

Available when **type** is FWP_BYTE_ARRAY6_TYPE.

A pointer to a [FWP_BYTE_ARRAY6](https://learn.microsoft.com/windows/win32/api/fwptypes/ns-fwptypes-fwp_byte_array6) structure.

> [!NOTE]
> This value cannot be null.

> [!NOTE]
> Available only in Windows 7 and Windows Server 2008 R2.

### `bitmapArray64`

### `v4AddrMask`

Available when **type** is FWP_V4_ADDR_MASK.

A pointer to an IPv4 address contained in an [FWP_V4_ADDR_AND_MASK](https://learn.microsoft.com/windows/win32/api/fwptypes/ns-fwptypes-fwp_v4_addr_and_mask) structure.

### `v6AddrMask`

Available when **type** is FWP_V6_ADDR_MASK.

A pointer to an IPv6 address contained in an [FWP_V6_ADDR_AND_MASK](https://learn.microsoft.com/windows/win32/api/fwptypes/ns-fwptypes-fwp_v6_addr_and_mask) structure.

### `rangeValue`

Available when **type** is FWP_RANGE_TYPE.

A pointer to a range contained in an [FWP_RANGE0](https://learn.microsoft.com/windows/win32/api/fwptypes/ns-fwptypes-fwp_range0) structure.

## Remarks

The data type of
**FWP_CONDITION_VALUE0** must be compatible with the data type of the
[FWP_VALUE0](https://learn.microsoft.com/windows/win32/api/fwptypes/ns-fwptypes-fwp_value0) to which it is being compared. However, this does not mean the data types
necessarily need to be the same. For example, an FWP_V4_ADDR_MASK can be
compared to an FWP_UINT32 containing an IPv4 address. See [FWP_MATCH_TYPE](https://learn.microsoft.com/windows/win32/api/fwptypes/ne-fwptypes-fwp_match_type) for detailed information about **FWP_CONDITION_VALUE0** and **FWP_VALUE0** compatibility rules.

**FWP_CONDITION_VALUE0** is a specific implementation of FWP_CONDITION_VALUE. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[FWP_BYTE_ARRAY16](https://learn.microsoft.com/windows/win32/api/fwptypes/ns-fwptypes-fwp_byte_array16)

[FWP_BYTE_ARRAY6](https://learn.microsoft.com/windows/win32/api/fwptypes/ns-fwptypes-fwp_byte_array6)

[FWP_BYTE_BLOB](https://learn.microsoft.com/windows/win32/api/fwptypes/ns-fwptypes-fwp_byte_blob)

[FWP_RANGE0](https://learn.microsoft.com/windows/win32/api/fwptypes/ns-fwptypes-fwp_range0)

[FWP_V4_ADDR_AND_MASK](https://learn.microsoft.com/windows/win32/api/fwptypes/ns-fwptypes-fwp_v4_addr_and_mask)

[FWP_V6_ADDR_AND_MASK](https://learn.microsoft.com/windows/win32/api/fwptypes/ns-fwptypes-fwp_v6_addr_and_mask)

[FWP_VALUE0](https://learn.microsoft.com/windows/win32/api/fwptypes/ns-fwptypes-fwp_value0)

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)