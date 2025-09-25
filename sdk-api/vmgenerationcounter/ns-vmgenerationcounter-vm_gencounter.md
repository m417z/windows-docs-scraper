# VM_GENCOUNTER structure

## Description

Describes a virtual machine generation identifier.

## Members

### `GenerationCount`

The low 64 bits of the virtual machine generation identifier.

### `GenerationCountHigh`

The high 64 bits of the virtual machine generation identifier.

## Remarks

For info about the virtual machine generation identifier, see [Virtual machine generation identifier](https://learn.microsoft.com/windows/desktop/HyperV_v2/virtual-machine-generation-identifier).

## See also

[IOCTL_VMGENCOUNTER_READ](https://learn.microsoft.com/windows/desktop/api/vmgenerationcounter/ni-vmgenerationcounter-ioctl_vmgencounter_read)