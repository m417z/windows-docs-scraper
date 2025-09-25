# _SRIOV_MITIGATED_RANGE_COUNT_INPUT structure

## Description

This structure is used as an input buffer to the [IOCTL_SRIOV_QUERY_MITIGATED_RANGE_COUNT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ni-pcivirt-ioctl_sriov_query_mitigated_range_count) request to determine the ranges of memory-mapped I/O space that must be mitigated.

## Members

### `VfIndex`

Zero-based index of the virtual function from the first virtual function exposed by this physical function.

## Syntax

```cpp
typedef struct _SRIOV_MITIGATED_RANGE_COUNT_INPUT {
  USHORT  VfIndex;
} SRIOV_MITIGATED_RANGE_COUNT_INPUT, SRIOV_MITIGATED_RANGE_COUNT_INPUT;
```

## See also

[IOCTL_SRIOV_QUERY_MITIGATED_RANGE_COUNT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ni-pcivirt-ioctl_sriov_query_mitigated_range_count)