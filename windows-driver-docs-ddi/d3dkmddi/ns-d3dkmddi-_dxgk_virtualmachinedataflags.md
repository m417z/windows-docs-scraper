# DXGK_VIRTUALMACHINEDATAFLAGS structure

## Description

The **DXGK_VIRTUALMACHINEDATAFLAGS** structure specifies attributes of the virtual machine (VM).

## Members

### `SecureVirtualMachine`

When set, specifies that the VM runs in secure mode.

### `LinuxVirtualMachine`

When set, specifies that the VM is Linux-based.

### `Value`

Use to reference bits in the union.

## Remarks

For more information, see [GPU paravitualization](https://learn.microsoft.com/windows-hardware/drivers/display/gpu-paravirtualization).

## See also

[**DXGKARG_SETVIRTUALMACHINEDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_setvirtualmachinedata)

[**DxgkddiSetVirtualMachineData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setvirtualmachinedata)