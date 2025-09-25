# DXGK_QUERYADAPTERINFOFLAGS structure

## Description

The **DXGK_QUERYADAPTERINFOFLAGS** structure specifies flags to use when querying graphics adapter information.

## Members

### `VirtualMachineData`

Set when the call comes from a virtual machine.

### `SecureVirtualMachine`

Specifies that the virtual machine runs in secure mode.

### `Reserved`

This member is reserved and should be set to zero.

### `Value`

A convenient way to access the flags.

## Remarks

## See also

[**DXGKARG_QUERYADAPTERINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_queryadapterinfo)

[**DxgkDdiQueryAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo)