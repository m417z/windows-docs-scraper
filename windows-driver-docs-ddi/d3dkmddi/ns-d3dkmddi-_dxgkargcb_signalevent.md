# DXGKARGCB_SIGNALEVENT structure

## Description

**DXGKARGCB_SIGNALEVENT** contains the arguments used by the [**DxgkCbSignalEvent**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_signalevent) callback function to signal an event.

## Members

### `hDxgkProcess`

[in] Handle to the *Dxgkrnl* process object that was passed to [**DxgkDdiCreateProcess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createprocess). The process must be created for a virtual machine; that is, [**DXGK_CREATEPROCESSFLAGS::VirtualMachineProcess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_createprocessflags) must be set in the call to **DxgkDdiCreateProcess**.

When **CpuEventObject** is set, **hDxgkProcess** must be zero.

The driver must synchronize the callback with [**DxgkDdiDestroyProcess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_destroyprocess) to ensure that the process isn't destroyed during the callback.

### `hEvent`

[in] The user-mode event handle that needs to be signaled. The handle is valid in the context of the *Dxgkrnl* process identified by **hDxgkProcess**. The user-mode driver on the guest can send the user-mode event handle to the kernel-mode driver via [**DxgkddiEscape**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_escape) or other APIs that allow private driver data.

When **CpuEventObject** is set, **hEvent** is equal to the *Dxgkrnl* CPU event object handle, passed in [**DxgkddiCreatecpuevent**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createcpuevent).

### `CpuEventObject`

[in] When set, indicates the event is a CPU event object. Supported starting in Windows 11 (WDDM 3.0). See [Signaling a CPU event from KMD](https://learn.microsoft.com/windows-hardware/drivers/display/signaling-cpu-event-from-kmd) for more information.

### `Reserved`

[in] Reserved; set to zero.

### `Flags`

[in] An alternative way to access the union's flags.

## See also

[**DxgkCbSignalEvent**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_signalevent)

[**DxgkddiCreatecpuevent**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createcpuevent)

[**DxgkDdiCreateProcess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createprocess)

[**DxgkDdiDestroyProcess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_destroyprocess)

[**DxgkddiEscape**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_escape)