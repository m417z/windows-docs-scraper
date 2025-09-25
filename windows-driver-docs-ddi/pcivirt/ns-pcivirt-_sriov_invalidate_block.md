# _SRIOV_INVALIDATE_BLOCK structure

## Description

Contains the configuration block information. This structure is used in a [IOCTL_SRIOV_INVALIDATE_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ni-pcivirt-ioctl_sriov_invalidate_block) request.

## Members

### `VfIndex`

Zero-based index of the virtual function (VF) from the first VF exposed by this physical function (PF).

### `BlockMask`

a block of configuration data.

## Syntax

```cpp
typedef struct _SRIOV_INVALIDATE_BLOCK {
  USHORT  VfIndex;
  UINT64  BlockMask;
} SRIOV_INVALIDATE_BLOCK, SRIOV_INVALIDATE_BLOCK;
```

## See also

[IOCTL_SRIOV_INVALIDATE_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ni-pcivirt-ioctl_sriov_invalidate_block)