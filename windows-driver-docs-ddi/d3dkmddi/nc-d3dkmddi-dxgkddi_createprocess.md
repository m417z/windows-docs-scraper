# DXGKDDI_CREATEPROCESS callback function

## Description

*Dxgkrnl* calls the kernel-mode display driver's (KMD) **DxgkDdiCreateProcess** function to create a kernel-mode driver (KMD) process object for a *Dxgkrnl* process object.

## Parameters

### `hAdapter`

[in] A handle to the display adapter.

### `pArgs`

[in/out] Pointer to a [**DXGKARG_CREATEPROCESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_createprocess) structure that describes the operation.

## Return value

**DxgkDdiCreateProcess** returns STATUS_SUCCESS if it succeeds. Otherwise, it returns an appropriate NTSTATUS error code.

## Remarks

**DxgkDdiCreateProcess** allows the KMD to create a process context that allows the KMD to manage resources and permissions for processes, including those running in specialized environments like virtual machines and containers, ensuring proper graphics operations across different system contexts.

During process creation, the kernel-mode driver is allowed to call the [**DxgkCbReserveVirtualAddressRange**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_reservegpuvirtualaddressrange) callback. At this point the GPU virtual address space for the process is free and the driver has the opportunity to reserve virtual address space for its needs.

When [**CREATEPROCESSFLAGS::VirtualMachineWorkerProcess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_createprocessflags) is set, the process belongs to the worker process of a virtual machine.

## See also

[**DXGKARG_CREATEPROCESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_createprocess)