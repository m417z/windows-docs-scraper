# _SRIOV_MITIGATED_RANGE_COUNT_OUTPUT structure

## Description

This structures is the output buffer received by the [IOCTL_SRIOV_QUERY_MITIGATED_RANGE_COUNT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ni-pcivirt-ioctl_sriov_query_mitigated_range_count) request that contains an array of ranges of memory-mapped I/O space
that must be mitigated.

## Members

### `RangeCount`

Array of ranges of memory-mapped I/O space
that must be mitigated.

## Syntax

```cpp
typedef struct _SRIOV_MITIGATED_RANGE_COUNT_OUTPUT {
  ULONG [6] RangeCount;
} SRIOV_MITIGATED_RANGE_COUNT_OUTPUT, SRIOV_MITIGATED_RANGE_COUNT_OUTPUT;
```

## See also

[IOCTL_SRIOV_QUERY_MITIGATED_RANGE_COUNT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ni-pcivirt-ioctl_sriov_query_mitigated_range_count)