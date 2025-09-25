# CACHE_RELATIONSHIP structure

## Description

Describes cache attributes. This structure is used with the [GetLogicalProcessorInformationEx](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getlogicalprocessorinformationex) function.

## Members

### `Level`

The cache level. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| 1 | L1 |
| 2 | L2 |
| 3 | L3 |

### `Associativity`

The cache associativity. If this member is CACHE_FULLY_ASSOCIATIVE (0xFF), the cache is fully associative.

### `LineSize`

The cache line size, in bytes.

### `CacheSize`

The cache size, in bytes.

### `Type`

The cache type. This member is a [PROCESSOR_CACHE_TYPE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-processor_cache_type) value.

### `Reserved`

This member is reserved.

### `GroupMask`

A [GROUP_AFFINITY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-group_affinity) structure that specifies a group number and processor affinity within the group.

## See also

[GROUP_AFFINITY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-group_affinity)

[GetLogicalProcessorInformationEx](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getlogicalprocessorinformationex)

[PROCESSOR_CACHE_TYPE](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-processor_cache_type)

[SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-system_logical_processor_information_ex)