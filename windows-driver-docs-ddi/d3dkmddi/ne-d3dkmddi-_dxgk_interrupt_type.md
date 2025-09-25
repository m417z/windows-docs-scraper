# DXGK_INTERRUPT_TYPE enumeration

## Description

The **DXGK_INTERRUPT_TYPE** enumeration indicates the type of the interrupt that the kernel-mode display driver (KMD) is notifying *Dxgkrnl* about.

## Constants

### `DXGK_INTERRUPT_DMA_COMPLETED:1`

A direct memory access (DMA) buffer is completed by using a fence identifier. The driver must supply the DMA buffer fence identifier in the **SubmissionFenceId** member of the **DmaCompleted** structure in the union that is contained in the [**DXGKARGCB_NOTIFY_INTERRUPT_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_notify_interrupt_data) structure in a call to the [**DxgkCbNotifyInterrupt**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_notify_interrupt) function. This DMA buffer fence identifier was assigned during a call to the driver's [**DxgkDdiSubmitCommand**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_submitcommand) function for the latest completed DMA buffer.

### `DXGK_INTERRUPT_DMA_PREEMPTED:2`

A preemption request is completed. The driver must supply the preemption fence identifier in the **PreemptionFenceId** member and the latest fence identifier that hardware completed (not preempted) in the **LastCompletedFenceId** member of the **DmaPreempted** structure in the union that is contained in the DXGKARGCB_NOTIFY_INTERRUPT_DATA structure in a call to the [**DxgkCbNotifyInterrupt**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_notify_interrupt) function.

The GPU scheduler determines that the graphics hardware preempted all of the commands between the preemption request and the submission with the latest fence identifier.

### `DXGK_INTERRUPT_CRTC_VSYNC:3`

A scan out is completed. The driver must supply information in the **CrtcVsync** structure in the union that is contained in the [**DXGKARGCB_NOTIFY_INTERRUPT_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_notify_interrupt_data) structure in a call to the [**DxgkCbNotifyInterrupt**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_notify_interrupt) function.

The display miniport driver notifies with this interrupt type after video hardware entered into the vertical retrace period, and the pending flip address was latched into the DAC and scanned out. The display miniport driver is not required to report this interrupt after the operating system calls the driver's [**DxgkDdiControlInterrupt**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_controlinterrupt) function to disable the interrupt type; however, the driver must resume reporting after the operating system calls the driver's *DxgkDdiControlInterrupt* function again to enable the interrupt type.

### `DXGK_INTERRUPT_DMA_FAULTED:4`

Reserved for system use. Do not use in your driver.

### `DXGK_INTERRUPT_DISPLAYONLY_VSYNC:5`

In a kernel-mode display-only driver, a VSync has completed. Supported starting with Windows 8.

### `DXGK_INTERRUPT_DISPLAYONLY_PRESENT_PROGRESS:6`

In a kernel-mode display-only driver, a present operation has completed or has failed. Supported starting with Windows 8.

### `DXGK_INTERRUPT_CRTC_VSYNC_WITH_MULTIPLANE_OVERLAY:7`

A Vsync has completed in a display miniport driver that supports multiplane overlays. Supported starting with Windows 8.1.

### `DXGK_INTERRUPT_MICACAST_CHUNK_PROCESSING_COMPLETE:8`

The GPU has completed encoding a Miracast encode chunk. Supported starting with Windows 8.1.

The display miniport driver can optionally provide private data that the user-mode driver can obtain using the [**GetNextChunkData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_get_next_chunk_data) function.

### `DXGK_INTERRUPT_DMA_PAGE_FAULTED:9`

This interrupt type should be raised when a GPU encounters an error condition that requires OS to perform a recovery action, such as putting the running packet device in error or resetting the GPU. Supported starting with Windows 10.

When this interrupt type is set, interrupt data should be provided in the **DmaPageFaulted** member of [**DXGKARGCB_NOTIFY_INTERRUPT_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_notify_interrupt_data) structure.

### `DXGK_INTERRUPT_CRTC_VSYNC_WITH_MULTIPLANE_OVERLAY2:10`

A Vsync has completed in a display miniport driver that supports multiplane overlays. Supported starting with Windows 10.

### `DXGK_INTERRUPT_MONITORED_FENCE_SIGNALED:11`

Raise this interrupt type when the monitored fence is signaled. Supported starting with Windows 10.

### `DXGK_INTERRUPT_HWQUEUE_PAGE_FAULTED:12`

Raise this interrupt type when the hardware queue page has faulted. Supported starting with Windows 10.

### `DXGK_INTERRUPT_HWCONTEXTLIST_SWITCH_COMPLETED:13`

Raise this interrupt type when the hardware context list switch has completed. Supported starting with Windows 10.

### `DXGK_INTERRUPT_PERIODIC_MONITORED_FENCE_SIGNALED:14`

Raise this interrupt type when the periodic monitored fence is signaled. Supported starting with Windows 10.

### `DXGK_INTERRUPT_SCHEDULING_LOG_INTERRUPT:15`

Raised during a scheduling log interrupt. Supported starting with Windows 10.

### `DXGK_INTERRUPT_GPU_ENGINE_TIMEOUT:16`

Raised when the GPU engine has timed out. Supported starting with Windows 10.

### `DXGK_INTERRUPT_SUSPEND_CONTEXT_COMPLETED:17`

Raised when the suspend context has completed. Supported starting with Windows 10.

### `DXGK_INTERRUPT_CRTC_VSYNC_WITH_MULTIPLANE_OVERLAY3:18`

A Vsync has completed in a display miniport driver that supports the [hardware flip queue model](https://learn.microsoft.com/windows-hardware/drivers/display/hardware-flip-queue). Supported starting with Windows 11 (WDDM 3.0).

### `DXGK_INTERRUPT_NATIVE_FENCE_SIGNALED:19`

A set of [native fence GPU objects](https://learn.microsoft.com/windows-hardware/drivers/display/native-gpu-fence-objects) monitored by the CPU were signaled on a GPU engine. Supported starting in Windows 11, version 24H2.

### `DXGK_INTERRUPT_GPU_ENGINE_STATE_CHANGE:20`

An engine state transition has occurred that requires a CPU power action or timeout recovery. Available starting in Windows 11, version 22H2 (WDDM 3.1).

## See also

[**DXGK_INTERRUPT_STATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_interrupt_state)

[**DXGKARG_CONTROLINTERRUPT2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_controlinterrupt2)

[**DXGKARG_CONTROLINTERRUPT3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_controlinterrupt3)

[**DXGKARGCB_NOTIFY_INTERRUPT_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_notify_interrupt_data)

[**DxgkCbNotifyInterrupt**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_notify_interrupt)

[**DxgkDdiControlInterrupt**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_controlinterrupt)

[**DxgkDdi_ControlInterrupt2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_controlinterrupt2)

[**DxgkDdi_ControlInterrupt3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_controlinterrupt3)

[**DxgkDdiSubmitCommand**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_submitcommand)

[**GetNextChunkData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_get_next_chunk_data)