# PROCESSOR_GROUP_INFO structure

## Description

Represents the number and affinity of processors in a processor group.

## Members

### `MaximumProcessorCount`

The maximum number of processors in the group.

### `ActiveProcessorCount`

The number of active processors in the group.

### `Reserved`

This member is reserved.

### `ActiveProcessorMask`

A bitmap that specifies the affinity for zero or more active processors within the group.

## See also

[GROUP_RELATIONSHIP](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-group_relationship)