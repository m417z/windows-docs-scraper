# _SRIOV_MITIGATED_RANGES_INPUT structure

## Description

This structure is the input buffer in the [IOCTL_SRIOV_QUERY_MITIGATED_RANGES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ni-pcivirt-ioctl_sriov_query_mitigated_ranges) request to get the specific ranges on which intercepts must be placed.

## Members

### `VfIndex`

Zero-based index of the virtual function from the first virtual function exposed by this physical function.

### `BarNumber`

The number of BAR of the ranges of memory-mapped I/O space.

## Syntax

```cpp
typedef struct _SRIOV_MITIGATED_RANGES_INPUT {
  USHORT  VfIndex;
  UCHAR   BarNumber;
} SRIOV_MITIGATED_RANGES_INPUT, SRIOV_MITIGATED_RANGES_INPUT;
```