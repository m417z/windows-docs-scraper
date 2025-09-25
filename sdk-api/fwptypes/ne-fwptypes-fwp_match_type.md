# FWP_MATCH_TYPE enumeration

## Description

The **FWP_MATCH_TYPE** enumerated type specifies different match types allowed in filter conditions.

## Constants

### `FWP_MATCH_EQUAL:0`

Tests whether the value is equal to the condition value.

All data types support **FWP_MATCH_EQUAL**.

### `FWP_MATCH_GREATER`

Tests whether the value is greater than the condition value.

Only sortable data types support **FWP_MATCH_GREATER**. Sortable data types consist of all integer types, FWP_BYTE_ARRAY16_TYPE, FWP_BYTE_BLOB_TYPE, and FWP_UNICODE_STRING_TYPE.

### `FWP_MATCH_LESS`

Tests whether the value is less than the condition value.

Only sortable data types support **FWP_MATCH_LESS**.

### `FWP_MATCH_GREATER_OR_EQUAL`

Tests whether the value is greater than or equal to the condition value.

Only sortable data types support **FWP_MATCH_GREATER_OR_EQUAL**.

### `FWP_MATCH_LESS_OR_EQUAL`

Tests whether the value is less than or equal to the condition value.

Only sortable data types support **FWP_MATCH_LESS_OR_EQUAL**.

### `FWP_MATCH_RANGE`

Tests whether the value is within a given range of condition values.

Only sortable data types support **FWP_MATCH_RANGE**.

### `FWP_MATCH_FLAGS_ALL_SET`

Tests whether all flags are set.

Only unsigned integer data types support **FWP_MATCH_FLAGS_ALL_SET**.

### `FWP_MATCH_FLAGS_ANY_SET`

Tests whether any flags are set.

Only unsigned integer data types support **FWP_MATCH_FLAGS_ANY_SET**.

### `FWP_MATCH_FLAGS_NONE_SET`

Tests whether no flags are set.

Only unsigned integer data types support **FWP_MATCH_FLAGS_NONE_SET**.

### `FWP_MATCH_EQUAL_CASE_INSENSITIVE`

Tests whether the value is equal to the condition value. The test is case insensitive.

Only the FWP_UNICODE_STRING_TYPE data type supports **FWP_MATCH_EQUAL_CASE_INSENSITIVE**.

### `FWP_MATCH_NOT_EQUAL`

Tests whether the value is not equal to the condition value.

Only sortable data types support **FWP_MATCH_NOT_EQUAL**.

**Note** Available only in Windows 7 and Windows Server 2008 R2.

### `FWP_MATCH_PREFIX`

*This flag has a misleading name.* It tests whether the value **ends** with the condition value, i.e. it the suffix, not the prefix.

The types FWP_BYTE_BLOB_TYPE (when it contains a string) and FWP_UNICODE_STRING_TYPE support this match type.

### `FWP_MATCH_NOT_PREFIX`

*This flag has a misleading name.* It tests whether the value does not **end** with the condition value, i.e. it checks the suffix, not the prefix.

The types FWP_BYTE_BLOB_TYPE (when it contains a string) and FWP_UNICODE_STRING_TYPE support this match type.

### `FWP_MATCH_TYPE_MAX`

Maximum value for testing purposes. Do not rely on this value in code, as it may change when you recompile with a newer SDK.

## Remarks

In general, the value data type and the filter condition data type must be the same. The Base Filtering Engine (BFE) does not perform any data conversion. For example, an FWP_UINT32 value cannot be compared with an FWP_UINT16 value.

Exceptions to this rule are as follows.

* An FWP_UINT32 field that contains an IPv4 address can be compared with an FWP_V4_ADDR_MASK value.
* An FWP_BYTE_ARRAY16_TYPE field that contains an IPv6 address can be compared with an FWP_V6_ADDR_MASK value.
* An FWP_TOKEN_INFORMATION_TYPE field can be compared with an FWP_SECURITY_DESCRIPTOR_TYPE value when adding filters.
* An FWP_TOKEN_ACCESS_INFORMATION_TYPE field can be compared with an FWP_SECURITY_DESCRIPTOR_TYPE value when adding filters.
* An FWP_TOKEN_INFORMATION_TYPE field can be compared with an FWP_SID value when enumerating.
* An FWP_TOKEN_ACCESS_INFORMATION_TYPE field can be compared with an FWP_SID value when enumerating.

## See also

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)