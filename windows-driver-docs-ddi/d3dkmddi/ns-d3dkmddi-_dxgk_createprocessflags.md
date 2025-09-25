# DXGK_CREATEPROCESSFLAGS structure

## Description

**DXGK_CREATEPROCESSFLAGS** are *Dxgkrnl*-provided flags that describe the characteristics of *Dxgkrnl*'s process that [**DxgkDdiCreateProcess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createprocess) is to create a kernel-mode driver (KMD) process object for.

## Members

### `SystemProcess`

Indicates that the process referenced by [**hDxgkProcess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_createprocess) is a system process.

### `GdiProcess`

Indicates that the process referenced by [**hDxgkProcess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_createprocess) is a GDI process.

### `VirtualMachineProcess`

Indicates that the *Dxgkrnl* process being created during a call to [**DxgkDdiCreateProcess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createprocess) is associated with a virtual machine. Each virtual machine *Dxgkrnl* process will belong to the same EPROCESS as the same virtual machine worker process. Introduced in WDDM 2.2.

### `VirtualMachineWorkerProcess`

Indicates that the process being created during a call to [**DxgkDdiCreateProcess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createprocess) is the worker process for a virtual machine. Because no rendering or driver resource is created in this process context, the driver might skip allocating certain resources. Introduced in WDDM 2.4.

### `SessionIsolatedContainer`

Indicates whether the process is running within a session-isolated container. Introduced in WDDM 2.5.

### `Reserved`

This member is reserved and should be set to zero.

### `Value`

The consolidated value of the bitfield members of the structure.

## See also

[**DXGKARG_CREATEPROCESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_createprocess)

[**DxgkDdiCreateProcess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createprocess)