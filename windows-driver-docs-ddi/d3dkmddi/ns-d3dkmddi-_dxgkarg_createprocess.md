# DXGKARG_CREATEPROCESS structure

## Description

**DXGKARG_CREATEPROCESS** is used with [**DxgkDdiCreateProcess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createprocess) to create a kernel-mode driver (KMD) process object for a *Dxgkrnl* process object.

## Members

### `hDxgkProcess` [in]

The handle to the *Dxgkrnl* process (DXGPROCESS).

### `hKmdProcess` [out]

Output handle to the process object created by the KMD.

### `Flags` [in]

A [**DXGK_CREATEPROCESSFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_createprocessflags) structure describing the process creation operation.

### `NumPasid` [in]

The number of elements in the process address space identifier array located in the **pPasid** member.

### `pPasid` [in]

A pointer to an array of process address identifiers. There is one identifier for each of the physical GPUs.

### `hKmdVmWorkerProcess` [in]

Handle of the driver VM worker process returned by the system when you create a process with [**VirtualMachineWorkerProcess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_createprocessflags) set. This value is valid only when **VirtualMachineProcess** is set.

### `ProcessNameLength` [in]

The number of Unicode characters in the array that **pProcessName** points to, not including the terminating NULL.

### `pProcessName` [in]

Pointer to a NULL-terminated Unicode string that contains the process name. When **VirtualMachineProcess** is set, this string is the name of the process inside a virtual machine. Can be NULL.

## See also

[**DXGK_CREATEPROCESSFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_createprocessflags)

[**DxgkDdiCreateProcess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createprocess)