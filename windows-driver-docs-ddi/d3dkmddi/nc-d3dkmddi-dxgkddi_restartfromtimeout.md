# DXGKDDI_RESTARTFROMTIMEOUT callback function

## Description

The *DxgkDdiRestartFromTimeout* function indicates that the driver can access the graphics processing unit (GPU) again after the recovery from a hardware timeout has completed.

## Parameters

### `hAdapter` [in]

A handle to a context block that is associated with a display adapter. The display miniport driver previously provided this handle to the Microsoft DirectX graphics kernel subsystem in the *MiniportDeviceContext* output parameter of the [DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

## Return value

*DxgkDdiRestartFromTimeout* returns STATUS_SUCCESS to indicate that the driver handled the call successfully; otherwise, the operating system bug checks and causes a restart.

## Remarks

The operating system calls the *DxgkDdiRestartFromTimeout* function after the recovery of a hardware time-out completes from the operating system's perspective (for example, all of the system-managed resources, mappings, and so on are released). The *DxgkDdiRestartFromTimeout* function indicates that the driver can begin to access the GPU and release any driver-managed resources. However, most drivers might not be required to perform any actions during a call to *DxgkDdiRestartFromTimeout*. Regardless of whether *DxgkDdiRestartFromTimeout* performs any actions, it must still be implemented and can simply return STATUS_SUCCESS immediately.

*DxgkDdiRestartFromTimeout* should be made pageable.

## See also

[DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)

[DxgkDdiResetFromTimeout](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_resetfromtimeout)