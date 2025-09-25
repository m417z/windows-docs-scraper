# DXGKDDI_SETVIRTUALMACHINEDATA callback function

## Description

*Dxgkrnl* calls **DxgkddiSetVirtualMachineData** to pass information about a virtual machine (VM) to the kernel-mode display driver (KMD).

## Parameters

### `hAdapter`

[in] The logical adapter for which to set VM data.

### `Args`

[in] Pointer to a [**DXGKARG_SETVIRTUALMACHINEDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_setvirtualmachinedata) structure that contains arguments to set VM data.

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, return an appropriate NTSTATUS Values error code.

## Remarks

Client GPU virtualization provides an isolation layer at the *Dxgkrnl* level for a particular process that runs in the context of a dedicated VM. For the purpose of GPU hardware scheduling, work submitted by the VM dedicated to such a process is simply treated as a separate GPU client process.

Server GPU virtualization provides much stronger isolation, where VMs are completely isolated from each other at the OS Hypervisor level and each VM is guaranteed a fixed GPU time slice, within which they run their own scheduling algorithm across priority bands, processes, and contexts.

For more information, see [GPU paravitualization](https://learn.microsoft.com/windows-hardware/drivers/display/gpu-paravirtualization).

## See also

[**DXGKARG_SETVIRTUALMACHINEDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_setvirtualmachinedata)