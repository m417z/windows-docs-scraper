# _SRIOV_MITIGATED_RANGE_UPDATE_OUTPUT structure

## Description

This structures is the output buffer received by the [IOCTL_SRIOV_MITIGATED_RANGE_UPDATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ni-pcivirt-ioctl_sriov_mitigated_range_update) request that indicates the virtual function (VF) whose memory-mapped I/O space
was mitigated.

## Members

### `VfIndex`

Zero-based index of the virtual function from the first virtual function exposed by this physical function.

## Syntax

```cpp
typedef struct _SRIOV_MITIGATED_RANGE_UPDATE_OUTPUT {
  USHORT  VfIndex;
} SRIOV_MITIGATED_RANGE_UPDATE_OUTPUT, SRIOV_MITIGATED_RANGE_UPDATE_OUTPUT;
```