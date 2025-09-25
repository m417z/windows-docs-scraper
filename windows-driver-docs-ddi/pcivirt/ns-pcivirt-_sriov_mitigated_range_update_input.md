# _SRIOV_MITIGATED_RANGE_UPDATE_INPUT structure

## Description

This structure is used as an input buffer to the [IOCTL_SRIOV_MITIGATED_RANGE_UPDATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ni-pcivirt-ioctl_sriov_mitigated_range_update) request to indicate the virtual function (VF) whose memory-mapped I/O space that must be mitigated.

## Members

### `VfIndex`

Zero-based index of the virtual function from the first virtual function exposed by this physical function.

## Syntax

```cpp
typedef struct _SRIOV_MITIGATED_RANGE_UPDATE_INPUT {
  USHORT  VfIndex;
} SRIOV_MITIGATED_RANGE_UPDATE_INPUT, SRIOV_MITIGATED_RANGE_UPDATE_INPUT;
```