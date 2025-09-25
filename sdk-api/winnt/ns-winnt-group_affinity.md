# GROUP_AFFINITY structure

## Description

Represents a processor group-specific affinity, such as the affinity of a thread.

## Members

### `Mask`

A bitmap that specifies the affinity for zero or more processors within the specified group.

### `Group`

The processor group number.

### `Reserved`

This member is reserved.

## See also

[CACHE_RELATIONSHIP](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-cache_relationship)

[NUMA_NODE_RELATIONSHIP](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-numa_node_relationship)

[PROCESSOR_RELATIONSHIP](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-processor_relationship)