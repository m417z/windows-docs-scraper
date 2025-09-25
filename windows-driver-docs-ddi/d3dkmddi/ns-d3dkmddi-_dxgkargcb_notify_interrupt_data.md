# DXGKARGCB_NOTIFY_INTERRUPT_DATA structure

## Description

The **DXGKARGCB_NOTIFY_INTERRUPT_DATA** structure contains interrupt notification information for the [**DXGKCB_NOTIFY_INTERRUPT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_notify_interrupt) callback function.

## Members

### `InterruptType`

A [**DXGK_INTERRUPT_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_interrupt_type)-typed value that indicates the type of interrupt the display miniport driver is notifying the GPU scheduler about.

### `DmaCompleted`

Structure used when **InterruptType** is **DXGK_INTERRUPT_DMA_COMPLETED**.

### `DmaCompleted.SubmissionFenceId`

The DMA buffer fence identifier of the completed command. This identifier was assigned during a call to the driver's [**DXGKDDI_SUBMITCOMMAND**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_submitcommand) function for the latest completed DMA buffer.

### `DmaCompleted.NodeOrdinal`

The zero-based index of the node that generates the notification.

### `DmaCompleted.EngineOrdinal`

The zero-based index of the engine, within the node that **NodeOrdinal** specifies, that generates the notification. For graphics adapters that are not part of a link, you should always set **EngineOrdinal** to 0. For graphics adapters that are part of a link, set **EngineOrdinal** to the adapter index of the adapter in the link that the interrupting engine belongs to.

### `DmaPreempted`

Structure used when **InterruptType** is **DXGK_INTERRUPT_DMA_PREEMPTED**.

### `DmaPreempted.PreemptionFenceId`

The submission identifier of the preempting request.

### `DmaPreempted.LastCompletedFenceId`

The submission identifier of the last completed command before preemption.

### `DmaPreempted.NodeOrdinal`

The zero-based index of the node that generates the notification.

### `DmaPreempted.EngineOrdinal`

The zero-based index of the engine, within the node that **NodeOrdinal** specifies, that generates the notification. For graphics adapters that are not part of a link, you should always set **EngineOrdinal** set to 0. For graphics adapters that are part of a link, set **EngineOrdinal** to the adapter index of the adapter in the link that the interrupting engine belongs to. The GPU scheduler determines that hardware preempted all commands between the preemption request and the submission that **LastCompletedFenceId** specifies.

### `DmaFaulted`

Structure used when **InterruptType** is **DXGK_INTERRUPT_DMA_FAULTED**.

### `DmaFaulted.FaultedFenceId`

The identifier of the faulty command.

### `DmaFaulted.Status`

The status of the faulty command.

### `DmaFaulted.NodeOrdinal`

The zero-based index of the node that generates the notification.

### `DmaFaulted.EngineOrdinal`

The zero-based index of the engine, within the node that **NodeOrdinal** specifies, that generates the notification. For graphics adapters that are not part of a link, you should always set **EngineOrdinal** to 0. For graphics adapters that are part of a link, set **EngineOrdinal** to the adapter index of the adapter in the link that the interrupting engine belongs to.

### `CrtcVsync`

Structure used when **InterruptType** is **DXGK_INTERRUPT_CRTC_VSYNC**.

### `CrtcVsync.VidPnTargetId`

The zero-based identification number of the video present target in a path of a video present network (VidPN) topology. This number represents the video present target where the vertical sync occurs.

### `CrtcVsync.PhysicalAddress`

The physical address of the displaying buffer. When monitor visibility is off, the operating system still expects a non-**NULL** physical address. This address should be set to the physical address that the pixel pipeline would read from if visibility were on.

### `CrtcVsync.PhysicalAdapterMask`

The physical adapter mask where the vertical sync occurs. If this member contains a valid value, the driver must also set the **ValidPhysicalAdapterMask** bit-field flag in the **Flags** member.

### `DisplayOnlyVsync`

Structure used when **InterruptType** is **DXGK_INTERRUPT_DISPLAYONLY_VSYNC**. Supported starting with Windows 8.

### `DisplayOnlyVsync.VidPnTargetId`

For a display-only driver, the zero-based identification number of the video present target in a path of a video present network (VidPN) topology. This number represents the video present target where the vertical sync occurs. Supported starting with Windows 8.

### `CrtcVsyncWithMultiPlaneOverlay`

Structure used when **InterruptType** is **DXGK_INTERRUPT_CRTC_VSYNC_WITH_MULTIPLANE_OVERLAY**. Provides VSync notifications for display miniport drivers that support multiplane overlays. Supported starting with Windows 8.

### `CrtcVsyncWithMultiPlaneOverlay.VidPnTargetId`

The zero-based identification number of the video present target in a path of a video present network (VidPN) topology. This number represents the video present target where the vertical sync occurs. Supported starting with Windows 8.

### `CrtcVsyncWithMultiPlaneOverlay.PhysicalAdapterMask`

The physical adapter mask where the vertical sync occurs. If this member contains a valid value, the driver must also set the **ValidPhysicalAdapterMask** bit-field flag in the **Flags** member. Supported starting with Windows 8.

### `CrtcVsyncWithMultiPlaneOverlay.MultiPlaneOverlayVsyncInfoCount`

The number of overlay planes that are available to display. Supported starting with Windows 8.

### `CrtcVsyncWithMultiPlaneOverlay.pMultiPlaneOverlayVsyncInfo`

A pointer to a [**DXGK_MULTIPLANE_OVERLAY_VSYNC_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_multiplane_overlay_vsync_info) structure that specifies an overlay plane to display during a VSync interval. Supported starting with Windows 8.

### `DisplayOnlyPresentProgress`

A [**DXGKARGCB_PRESENT_DISPLAYONLY_PROGRESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_present_displayonly_progress) structure that provides the progress of a kernel mode display-only driver's (KMDOD) present operation. Used when **InterruptType** is **DXGK_INTERRUPT_DISPLAYONLY_PRESENT_PROGRESS**. Supported starting with Windows 8.

### `MiracastEncodeChunkCompleted`

Structure used when **InterruptType** is **DXGK_INTERRUPT_MICACAST_CHUNK_PROCESSING_COMPLETE**. Supported by WDDM 1.3 and later display miniport drivers running on Windows 8.1 and later.

### `MiracastEncodeChunkCompleted.VidPnTargetId`

The zero-based identification number of the video present target in a path of a video present network (VidPN) topology. This number represents the video present target where the encoding is being performed. Supported starting with Windows 8.1.

### `MiracastEncodeChunkCompleted.ChunkInfo`

A [**DXGK_MIRACAST_CHUNK_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-dxgk_miracast_chunk_info) encode chunk information structure that the display miniport driver wants to report. Supported starting with Windows 8.1.

### `MiracastEncodeChunkCompleted.pPrivateDriverData`

A pointer to a block of private data that describes this encode chunk. Supported starting with Windows 8.1.

### `MiracastEncodeChunkCompleted.PrivateDataDriverSize`

The size, in bytes, of the block of private data in **pPrivateDriverData**.
This value must not be larger than the **MaxChunkPrivateDriverDataSize** value that the driver reported in the [**DXGK_MIRACAST_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_miracast_caps) structure. Supported starting with Windows 8.1.

### `MiracastEncodeChunkCompleted.Status`

A value of type **NTSTATUS** that indicates whether the encode chunk was successfully added to the queue of chunks. If successful, **STATUS_SUCCESS** is returned. If any other value is returned, the chunk could not be added to the queue, and all outstanding chunks will be lost. Supported starting with Windows 8.1.

|Value|Meaning|
|--- |--- |
|STATUS_SUCCESS|The chunk was successfully added to the queue.|
|STATUS_INVALID_PARAMETER|Parameters were validated and determined to be incorrect.|
|STATUS_NO_MEMORY|The interrupt-service-routine (ISR) ran out of free encode chunks.|

### `DmaPageFaulted`

Structure used when **InterruptType** is **DXGK_INTERRUPT_DMA_PAGE_FAULTED**. Supported starting with Windows 10.

### `DmaPageFaulted.FaultedFenceId`

Submission fence ID of faulted command.

If the faulted fence cannot be determined reliably, **PageFaultFlags** should have **DXGK_PAGE_FAULT_FENCE_INVALID** bit set, and **FaultedFenceId** should be set to 0. Supported starting with Windows 10.

### `DmaPageFaulted.FaultedPrimitiveAPISequenceNumber`

 When per draw fence write is enabled, this identifies the draw operation that caused the page fault, or **DXGK_PRIMITIVE_API_SEQUENCE_NUMBER_UNKNOWN** if such information is not available. Supported starting with Windows 10.

### `DmaPageFaulted.FaultedPipelineStage`

Render pipeline stage during which the fault was generated, or **DXGK_RENDER_PIPELINE_STAGE_UNKNOWN** if such information is not available. Supported starting with Windows 10.

### `DmaPageFaulted.FaultedBindTableEntry`

A bind table index of a resource being accessed at the time of the fault, or **DXGK_BIND_TABLE_ENTRY_UNKNOWN** if such information is not available. Supported starting with Windows 10.

### `DmaPageFaulted.PageFaultFlags`

Flags described in [**DXGK_PAGE_FAULT_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_dxgk_page_fault_flags) enumeration specifying the nature of the fault. Supported starting with Windows 10.

### `DmaPageFaulted.FaultedVirtualAddress`

GPU virtual address of fault, or **D3DGPU_NULL** if the fault has another cause. In the latter case, **FaultErrorCode** field should be used to describe the GPU error. Supported starting with Windows 10.

### `DmaPageFaulted.NodeOrdinal`

Node ordinal of the engine generating the notification. Supported starting with Windows 10.

### `DmaPageFaulted.EngineOrdinal`

Engine ordinal of the engine generating the notification. Supported starting with Windows 10.

### `DmaPageFaulted.PageTableLevel`

Describes page table level that the faulting operation was attempted on. Supported starting with Windows 10.

### `DmaPageFaulted.FaultErrorCode`

A [**DXGK_FAULT_ERROR_CODE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgk_fault_error_code) structure describing the error. Supported starting with Windows 10.

### `DmaPageFaulted.FaultedProcessHandle`

DirectX graphics kernel process handle of the process that generated page fault, or **NULL** if the faulted process cannot be determined. Supported starting with Windows 10.

### `CrtcVsyncWithMultiPlaneOverlay2`

Structure used when **InterruptType** is **DXGK_INTERRUPT_CRTC_VSYNC_WITH_MULTIPLANE_OVERLAY2**. Supported starting with Windows 10, version 1607.

### `CrtcVsyncWithMultiPlaneOverlay2.VidPnTargetId`

Vsync with multiplane overlay Vidpn target id. Supported starting with Windows 10, version 1607.

### `CrtcVsyncWithMultiPlaneOverlay2.PhysicalAdapterMask`

The physical adapter mask where the vertical sync occurs. If this member contains a valid value, the driver must also set the **ValidPhysicalAdapterMask** bit-field flag in the **Flags** member. Supported starting with Windows 10, version 1607.

### `CrtcVsyncWithMultiPlaneOverlay2.MultiPlaneOverlayVsyncInfoCount`

The number of overlay planes that are available to display. Supported starting with Windows 10, version 1607.

### `CrtcVsyncWithMultiPlaneOverlay2.pMultiPlaneOverlayVsyncInfo`

A pointer to a [**DXGK_MULTIPLANE_OVERLAY_VSYNC_INFO2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_multiplane_overlay_vsync_info2) structure that specifies information for each overlay plane updated by the VSync. Supported starting with Windows 10, version 1607.

### `CrtcVsyncWithMultiPlaneOverlay2.GpuFrequency`

The frequency of the GPU clock counter. Supported starting with Windows 10, version 1607.

### `CrtcVsyncWithMultiPlaneOverlay2.GpuClockCounter`

The GPU clock counter at the time of the VSYNC interrupt. Combined with GpuFrequency, this indicates the time of the VSYNC interrupt. Supported starting with Windows 10, version 1607.

### `MonitoredFenceSignaled`

Structure used when **InterruptType** is **DXGK_INTERRUPT_MONITORED_FENCE_SIGNALED**. Supported starting with Windows 10, version 1703.

### `MonitoredFenceSignaled.NodeOrdinal`

Node ordinal of engine generating the notification. Supported starting with Windows 10, version 1703.

### `MonitoredFenceSignaled.EngineOrdinal`

Engine ordinal of engine generating the notification. Supported starting with Windows 10, version 1703.

### `HwContextListSwitchCompleted`

Structure used when **InterruptType** is **DXGK_INTERRUPT_HWCONTEXTLIST_SWITCH_COMPLETED**. Supported starting with Windows 10, version 1703.

### `HwContextListSwitchCompleted.NodeOrdinal`

Node ordinal of engine generating the notification. Supported starting with Windows 10, version 1703.

### `HwContextListSwitchCompleted.EngineOrdinal`

Engine ordinal of engine generating the notification. Supported starting with Windows 10, version 1703.

### `HwContextListSwitchCompleted.ContextSwitchFence`

Context switch fence used to perform this switch operation. Supported starting with Windows 10, version 1703.

### `HwQueuePageFaulted`

Structure used when **InterruptType** is **DXGK_INTERRUPT_HWQUEUE_PAGE_FAULTED**. Supported starting with Windows 10, version 1703.

### `HwQueuePageFaulted.FaultedFenceId`

HW queue progress fence ID of the faulted command. If the faulted fence could not be determined reliably PageFaultFlags should have DXGK_PAGE_FAULT_FENCE_INVALID flag set. Supported starting with Windows 10, version 1703.

### `HwQueuePageFaulted.FaultedVirtualAddress`

Virtual address of fault, or 0 if the fault has another cause. In the latter case, FaultErrorCode field should be used to describe the GPU error. Supported starting with Windows 10, version 1703.

### `HwQueuePageFaulted.FaultedPrimitiveAPISequenceNumber`

When per draw fence write is enabled, identifies the draw that caused the page fault, or DXGK_PRIMITIVE_API_SEQUENCE_NUMBER_UNKNOWN if such information is not available. Supported starting with Windows 10, version 1703.

### `HwQueuePageFaulted.FaultedHwQueue`

When DXGK_PAGE_FAULT_FENCE_INVALID is not set, specifies the handle of the HW queue that generated the fault. Supported starting with Windows 10, version 1703.

### `HwQueuePageFaulted.FaultedHwContext`

When DXGK_PAGE_FAULT_FENCE_INVALID and DXGK_PAGE_FAULT_HW_CONTEXT_VALID are set, specifies the handle of the HW context that generated the fault. Supported starting with Windows 10, version 1703.

### `HwQueuePageFaulted.FaultedProcessHandle`

Wen DXGK_PAGE_FAULT_FENCE_INVALID and DXGK_PAGE_FAULT_PROCESS_HANDLE_VALID are set, specifies the handle of the process that generated the fault. Supported starting with Windows 10, version 1703.

### `HwQueuePageFaulted.NodeOrdinal`

Node ordinal of engine generating the notification. Supported starting with Windows 10, version 1703.

### `HwQueuePageFaulted.EngineOrdinal`

Engine ordinal of engine generating the notification. Supported starting with Windows 10, version 1703.

### `HwQueuePageFaulted.FaultedPipelineStage`

Render pipeline stage during which the fault was generated, or DXGK_RENDER_PIPELINE_STAGE_UNKNOWN if such information is not available. Supported starting with Windows 10, version 1703.

### `HwQueuePageFaulted.FaultedBindTableEntry`

A bind table index of a resource being accessed at the time of the fault, or DXGK_BIND_TABLE_ENTRY_UNKNOWN if such information is not available. Supported starting with Windows 10, version 1703.

### `HwQueuePageFaulted.PageFaultFlags`

Flags specifying the nature of the page fault and recovery policy. Supported starting with Windows 10, version 1703.

### `HwQueuePageFaulted.PageTableLevel`

Described page table level which the faulting operation was attempted on. Supported starting with Windows 10, version 1703.

### `HwQueuePageFaulted.FaultErrorCode`

Structure that contains error code describing the fault. Supported starting with Windows 10, version 1703.

### `PeriodicMonitoredFenceSignaled`

Structure used when **InterruptType** is **DXGK_INTERRUPT_PERIODIC_MONITORED_FENCE_SIGNALED**. Supported starting with Windows 10, version 1703.

### `PeriodicMonitoredFenceSignaled.VidPnTargetId`

The display signaling the monitored fence. Supported starting with Windows 10, version 1703.

### `PeriodicMonitoredFenceSignaled.NotificationID`

The notification id as multiple can be attached to one VidPnSource. Supported starting with Windows 10, version 1703.

### `SchedulingLogInterrupt`

Structure used when **InterruptType** is **DXGK_INTERRUPT_SCHEDULING_LOG_INTERRUPT**. Supported starting with Windows 10, version 1803.

### `SchedulingLogInterrupt.NodeOrdinal`

Node ordinal of engine that raised the scheduling log interrupt. Supported starting with Windows 10, version 1803.

### `SchedulingLogInterrupt.EngineOrdinal`

Engine ordinal of engine that raised the scheduling log interrupt. Supported starting with Windows 10, version 1803.

### `GpuEngineTimeout`

Structure used when **InterruptType** is **DXGK_INTERRUPT_GPU_ENGINE_TIMEOUT**. Supported starting with Windows 10, version 1803.

### `GpuEngineTimeout.NodeOrdinal`

Node ordinal of engine that timed out and needs the reset. Supported starting with Windows 10, version 1803.

### `GpuEngineTimeout.EngineOrdinal`

Engine ordinal of engine that timed out and needs the reset. Supported starting with Windows 10, version 1803.

### `SuspendContextCompleted`

Structure used when **InterruptType** is **DXGK_INTERRUPT_SUSPEND_CONTEXT_COMPLETED**. Supported starting with Windows 10, version 1803.

### `SuspendContextCompleted.hContext`

Hardware context that the suspend acknowledgment is for. Supported starting with Windows 10, version 1803.

### `SuspendContextCompleted.ContextSuspendFence`

Context suspend fence. Supported starting with Windows 10, version 1803.

### `CrtcVsyncWithMultiPlaneOverlay3`

Structure used when **InterruptType** is **DXGK_INTERRUPT_CRTC_VSYNC_WITH_MULTIPLANE_OVERLAY3**. Available starting with Windows Server 2022 (WDDM 2.9).

### `CrtcVsyncWithMultiPlaneOverlay3.VidPnTargetId`

Vsync with multiplane overlay Vidpn target id. Available starting with Windows Server 2022 (WDDM 2.9).

### `CrtcVsyncWithMultiPlaneOverlay3.PhysicalAdapterMask`

The physical adapter mask where the vertical sync occurs. If this member contains a valid value, the driver must also set the **ValidPhysicalAdapterMask** bit-field flag in the **Flags** member. Available starting in Windows Server 2022 (WDDM 2.9).

### `CrtcVsyncWithMultiPlaneOverlay3.MultiPlaneOverlayVsyncInfoCount`

The number of [**DXGK_MULTIPLANE_OVERLAY_VSYNC_INFO3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgk_multiplane_overlay_vsync_info3) structures that **CrtcVsyncWithMultiPlaneOverlay3.pMultiPlaneOverlayVsyncInfo** points to. These structures describe the overlay planes that are available to display. Available starting in Windows Server 2022 (WDDM 2.9).

### `CrtcVsyncWithMultiPlaneOverlay3.pMultiPlaneOverlayVsyncInfo`

A pointer to an array of [**DXGK_MULTIPLANE_OVERLAY_VSYNC_INFO3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgk_multiplane_overlay_vsync_info3) structures that specify information for each overlay plane updated by the VSync. See [Hardware flip queue](https://learn.microsoft.com/windows-hardware/drivers/display/hardware-flip-queue) for more information. Available starting in Windows Server 2022 (WDDM 2.9).

### `CrtcVsyncWithMultiPlaneOverlay3.GpuFrequency`

The frequency of the GPU clock counter. Available starting in Windows Server 2022 (WDDM 2.9).

### `CrtcVsyncWithMultiPlaneOverlay3.GpuClockCounter`

The GPU clock counter at the time of the VSYNC interrupt. Combined with GpuFrequency, this indicates the time of the VSYNC interrupt. Available starting in Windows Server 2022 (WDDM 2.9).

### `NativeFenceSignaled`

[in] Structure used when [**InterruptType**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_interrupt_type) is **DXGK_INTERRUPT_NATIVE_FENCE_SIGNALED**. For more information about native fences, see [Native GPU fence objects](https://learn.microsoft.com/windows-hardware/drivers/display/native-gpu-fence-objects). Supported starting with Windows 11, version 24H2 (WDDM 3.2).

### `NativeFenceSignaled.NodeOrdinal`

Node ordinal of the engine generating the notification. Supported starting with Windows 11, version 24H2 (WDDM 3.2).

### `NativeFenceSignaled.EngineOrdinal`

Engine ordinal of the engine generating the notification. Supported starting with Windows 11, version 24H2 (WDDM 3.2).

### `NativeFenceSignaled.SignaledNativeFenceCount`

The size of the signaled native fence array that **pSignaledNativeFenceArray** points to. Supported starting with Windows 11, version 24H2 (WDDM 3.2).

### `NativeFenceSignaled.pSignaledNativeFenceArray`

Array containing OS kernel-mode handles of all native fences that were signaled and require waiters to be unblocked. If this array is empty, the OS will rescan all pending native fence waiters instead of the subset specified by the signaled native fence array. *Dxgkrnl* reads this value only if [**DXGK_VIDSCHCAPS::OptimizedNativeFenceInterrupt**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_vidschcaps) is FALSE. Supported starting with Windows 11, version 24H2 (WDDM 3.2).

### `NativeFenceSignaled.hHWQueue`

KMD handle of the HWQueue running on the engine that raised the interrupt. If this handle is NULL then *Dxgkrnl* will re-scan the log buffer of all HWQueues on this engine. *Dxgkrnl* reads this value only if [**DXGK_VIDSCHCAPS::OptimizedNativeFenceInterrupt**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_vidschcaps) is TRUE. Supported starting with Windows 11, version 24H2 (WDDM 3.2).

### `EngineStateChange`

[in] Structure used when **InterruptType** is **DXGK_INTERRUPT_GPU_ENGINE_STATE_CHANGE**. For more information, see [User-mode work submission](https://learn.microsoft.com/windows-hardware/drivers/display/user-mode-work-submission). Available starting with Windows 11, version 24H2 (WDDM 3.2).

### `EngineStateChange.NodeOrdinal`

Node ordinal of the engine whose state changed. Available starting with Windows 11, version 24H2 (WDDM 3.2).

### `EngineStateChange.EngineOrdinal`

Engine ordinal of the engine whose state changed. Available starting with Windows 11, version 24H2 (WDDM 3.2).

### `EngineStateChange.NewState`

A [**DXGK_ENGINE_STATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-dxgk_engine_state) value that specifies the new state of the engine. Available starting with Windows 11, version 24H2 (WDDM 3.2).

### `Reserved`

Reserved for future use.

### `Reserved.Reserved`

An array of 32-bit values that are reserved for future use.

### `Flags`

A [**DXGKCB_NOTIFY_INTERRUPT_DATA_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkcb_notify_interrupt_data_flags) structure that indicates whether the display miniport driver provides a physical adapter mask in a call to the [**DxgkCbNotifyInterrupt**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_notify_interrupt) function.

## Remarks

A miniport driver fills in **DXGKARGCB_NOTIFY_INTERRUPT_DATA**, and then uses the [**DXGKCB_SYNCHRONIZE_EXECUTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_synchronize_execution) callback to sync with the interrupt. The **SynchronizeRoutine** parameter of the **DXGKCB_SYNCHRONIZE_EXECUTION** callback points to a miniport-implemented function that gets called by the OS when appropriate, and then the driver fills out the parameter info before calling back into the OS with the [**DXGKCB_NOTIFY_INTERRUPT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_notify_interrupt) callback. The OS then handles the interrupt, with the scheduler using information in the DXGK_MULTIPLANE_OVERLAY_VSYNC_INFO2 struct.

Depending on the value in the **InterruptType** member, the display miniport driver should set the appropriate union member in this structure. For example, for the end of a direct memory access (DMA) buffer fence, which corresponds to a value of DXGK_INTERRUPT_DMA_COMPLETED in **InterruptType**, the driver must set a value in the **SubmissionFenceId** member of the **DmaCompleted** member. This value should be the DMA buffer fence identifier, which the driver's [**DxgkDdiSubmitCommand**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_submitcommand) function assigned to the just completed DMA buffer.

## See also

[**DXGK_INTERRUPT_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_interrupt_type)

[**DXGK_MIRACAST_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_miracast_caps)

[**DXGK_MIRACAST_CHUNK_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-dxgk_miracast_chunk_info)

[**DXGK_MULTIPLANE_OVERLAY_VSYNC_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_multiplane_overlay_vsync_info)

[**DXGKCB_NOTIFY_INTERRUPT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_notify_interrupt)

[**DXGKCB_NOTIFY_INTERRUPT_DATA_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkcb_notify_interrupt_data_flags)

[**DXGK_PAGE_FAULT_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_dxgk_page_fault_flags)

[**DXGKARGCB_PRESENT_DISPLAYONLY_PROGRESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_present_displayonly_progress)

[**DxgkDdiSubmitCommand**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_submitcommand)