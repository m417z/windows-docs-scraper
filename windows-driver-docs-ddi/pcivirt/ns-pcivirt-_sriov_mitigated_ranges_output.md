# _SRIOV_MITIGATED_RANGES_OUTPUT structure

## Description

This structure is the output buffer received by the [IOCTL_SRIOV_QUERY_MITIGATED_RANGES](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ni-pcivirt-ioctl_sriov_query_mitigated_ranges) request to get the specific ranges on which intercepts must be placed.

## Members

### `BasePageNumber`

The base address of the allocated region of pages.

### `PageCount`

Total number of pages.

### `InterceptReads`

A boolean that indicates the reads intercept bit.

### `InterceptWrites`

A boolean that indicates the write intercept bit.

## Syntax

```cpp
typedef struct _SRIOV_MITIGATED_RANGES_OUTPUT {
  ULONG64  BasePageNumber;
  ULONG    PageCount;
  BOOLEAN  InterceptReads;
  BOOLEAN  InterceptWrites;
} SRIOV_MITIGATED_RANGES_OUTPUT, SRIOV_MITIGATED_RANGES_OUTPUT;
```