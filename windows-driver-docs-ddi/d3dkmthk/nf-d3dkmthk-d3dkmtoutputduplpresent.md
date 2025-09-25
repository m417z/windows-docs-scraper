# D3DKMTOutputDuplPresent function

## Description

Submits a present command from the [Desktop Duplication API](https://learn.microsoft.com/windows/desktop/direct3ddxgi/desktop-dup-api) swapchain of the Desktop Window Manager (DWM) to the Microsoft DirectX graphics kernel subsystem (Dxgkrnl.sys).

## Parameters

### `unnamedParam1` [in]

A pointer to a [D3DKMT_OUTPUTDUPLPRESENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_outputduplpresent) structure that describes parameters for the present operation.

## Return value

Returns one of the following values:

| Return code | Description |
|--|--|
| STATUS_SUCCESS | The present operation was successfully performed. |
| STATUS_DEVICE_REMOVED | The graphics adapter was stopped or the display context was reset. |
| STATUS_INVALID_PARAMETER | Parameters were validated and determined to be incorrect. |
| STATUS_NO_MEMORY | [D3DKMTOutputDuplPresent]() could not complete because of insufficient memory. |
| STATUS_GRAPHICS_ALLOCATION_INVALID | The primary surface handle was invalidated because of a display mode change. If the OpenGL installable client driver (ICD) receives this error code, it should reopen or re-create the primary handle, replace all references in the command buffer to the old handle with the new handle, and then resubmit the buffer. |
| STATUS_GRAPHICS_GPU_EXCEPTION_ON_DEVICE | An error occurred on the rendering device context that the hContext member of [D3DKMT_OUTPUTDUPLPRESENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_outputduplpresent) specifies.<br>**Note:** This error code does not indicate the initiation of a Timeout Detection and Recovery (TDR) process or that the GPU stopped responding.<br>For example, the DirectX graphics kernel subsystem puts a device into an error state if the display miniport driver indicated that a DMA buffer that was submitted from this device caused a fault or if the video memory manager could not page-in all of the allocations that are required for a DMA buffer even after splitting the DMA buffer. After a device is in an error state, it cannot perform any more operations and must be destroyed and re-created. The ICD can call the [D3DKMTGetDeviceState](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtgetdevicestate) function to determine a more precise reason for the error. |

## See also

[D3DKMTGetDeviceState](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtgetdevicestate)

[D3DKMT_OUTPUTDUPLPRESENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_outputduplpresent)