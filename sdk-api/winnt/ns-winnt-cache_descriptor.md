# CACHE_DESCRIPTOR structure

## Description

Describes the cache attributes.

## Members

### `Level`

The cache level. This member can currently be one of the following values; other values may be supported in the future.

| Value | Meaning |
| --- | --- |
| 1 | L1 |
| 2 | L2 |
| 3 | L3 |

### `Associativity`

The cache associativity. If this member is CACHE_FULLY_ASSOCIATIVE (0xFF), the cache is fully associative.

### `LineSize`

The cache line size, in bytes.

### `Size`

The cache size, in bytes.

### `Type`

The cache type. This member is a [PROCESSOR_CACHE_TYPE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-processor_cache_type) value.

## See also

[GetLogicalProcessorInformation](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getlogicalprocessorinformation)

[PROCESSOR_CACHE_TYPE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-processor_cache_type)

[SYSTEM_LOGICAL_PROCESSOR_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-system_logical_processor_information)