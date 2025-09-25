# DXGK_DRIVERCAPS structure

## Description

The **DXGK_DRIVERCAPS** structure describes capabilities of a display miniport driver that the driver provides through a call to its [*DxgkDdiQueryAdapterInfo*](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo) function.

## Members

### `HighestAcceptableAddress` [out]

A PHYSICAL_ADDRESS data type (which is defined as LARGE_INTEGER) that indicates the highest acceptable physical address of system memory (RAM) to use.

### `MaxAllocationListSlotId` [out]

The maximum number of allocation-list slot identifiers. An allocation-list slot represents where an allocation is directed in direct memory access (DMA) buffering.

### `ApertureSegmentCommitLimit` [out]

The maximum number of bytes of physical memory that the display miniport driver supports for mapping into an aperture segment. The video memory manager will not map more physical memory into an aperture segment than the limit that **ApertureSegmentCommitLimit** specifies.

### `MaxPointerWidth` [out]

The maximum width of the mouse pointer, in pixels.

### `MaxPointerHeight` [out]

The maximum height of the mouse pointer, in scan lines.

### `PointerCaps` [out]

A [**DXGK_POINTERFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_pointerflags) structure that identifies the mouse pointer capabilities, in bit-field flags, that the driver can support.

### `InterruptMessageNumber` [out]

The message number that is used if message-signaled interrupts are used and the driver calls the [*DxgkCbNotifyInterrupt*](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_notify_interrupt) function from the interrupt handler corresponding to a fixed message number.

### `NumberOfSwizzlingRanges` [out]

The number of swizzling ranges that the driver can support.

### `MaxOverlays` [out]

The maximum number of overlays that the driver can support.

### `GammaRampCaps` [out]

A [**DXGK_GAMMARAMPCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_gammarampcaps) structure that identifies the gamma-ramp capabilities, in bit-field flags, that the driver can support.

### `ColorTransformCaps` [out]

Flags to describe gamma and color space transform capabilities of the display pipelines. NOTE: This field replaces the GammaRampCaps in the pre-WDDM 2.2 version of this structure.

### `PresentationCaps` [out]

A [**DXGK_PRESENTATIONCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_presentationcaps) structure that identifies the presentation capabilities, in bit-field flags, that the driver can support.

### `MaxQueuedFlipOnVSync` [out]

The number of flips that can be queued and pending at the graphics hardware. Each flip is latched to a digital-to-analog converter (DAC) at every VSync interrupt, in order, as the graphics hardware queues the flip.

### `FlipCaps` [out]

A [**DXGK_FLIPCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_flipcaps) structure that identifies the flipping capabilities, in bit-field flags, that the driver can support.

### `SchedulingCaps` [out]

A [**DXGK_VIDSCHCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_vidschcaps) structure that identifies the graphics processing unit (GPU) scheduling capabilities, in bit-field flags, that the driver can support.

### `MemoryManagementCaps` [out]

A [**DXGK_VIDMMCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_vidmmcaps) structure that identifies the video memory management capabilities that the driver can support.

### `GpuEngineTopology` [out]

A [**DXGK_GPUENGINETOPOLOGY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_gpuenginetopology) structure that describes the GPU-engine topology that the driver can support.

### `WDDMVersion` [out]

A [**DXGK_WDDMVERSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_wddmversion) value that identifies the version of WDDM. Supported starting with Windows 7.

If a driver supports Windows 7 or later features (DXGKDDI_INTERFACE_VERSION ≥ DXGKDDI_INTERFACE_VERSION_WIN7), this member is reserved and should be set to zero.

For older drivers that do not support Windows 7 or later features (DXGKDDI_INTERFACE_VERSION < DXGKDDI_INTERFACE_VERSION_WIN7):

* To compile the driver with the Windows 7 WDK (Version 7600), set this member to DXGKDDI_WDDMv1.
* To compile the driver with the Windows 8 WDK, set this member to DXGKDDI_WDDMv1_2.

### `Reserved`

Reserved.

### `Reserved1`

Reserved.

### `PreemptionCaps` [out]

A [**D3DKMDT_PREEMPTION_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_preemption_caps) structure that describes the capabilities for the preemption of GPU graphics requests that the driver supports.

Supported starting with Windows 8.

### `SupportNonVGA` [out]

If **TRUE**, the driver supports resetting the display device and releasing ownership of the current power-on self-test (POST) device by using the [*DxgkDdiStopDeviceAndReleasePostDisplayOwnership*](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_stop_device_and_release_post_display_ownership) function.

Supported starting with Windows 8.

### `SupportSmoothRotation` [out]

If **TRUE**, the driver supports updating path rotation on the adapter by using the [*DxgkDdiUpdateActiveVidPnPresentPath*](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_updateactivevidpnpresentpath) function, while not requiring a new VidPN to be created and set.

Supported starting with Windows 8.

### `SupportPerEngineTDR` [out]

If **TRUE**, the driver supports resetting individual GPU engines.

If this member is set, the display miniport driver must implement the [*DxgkDdiQueryDependentEngineGroup*](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_querydependentenginegroup), [*DxgkDdiQueryEngineStatus*](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryenginestatus), and [*DxgkDdiResetEngine*](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_resetengine) functions.

Supported starting with Windows 8.

### `SupportDirectFlip` [out]

If **TRUE**, the driver supports the creation and opening of shared managed primary allocations. A value of **TRUE** also indicates the following:

* The display miniport driver guarantees that when the [*DxgkDdiSetVidPnSourceAddress*](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setvidpnsourceaddress) function is called, the driver does not allow video memory to be flipped to an incompatible allocation.
* The user mode driver validates Direct Flip resources before the Desktop Windows Manager (DWM) uses them.

Only the DWM can flip video memory to Direct Flip resources. The DWM validates these resources using the user-mode [*CheckDirectFlipSupport*](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_checkdirectflipsupport) function.

Supported starting with Windows 8.

### `SupportMultiPlaneOverlay` [out]

If **TRUE**, the display miniport driver supports multiplane overlays, and the driver should also set a value for the **MaxOverlayPlanes** member. If **FALSE**, the DirectX graphics kernel subsystem will not call multiplane overlay functions.

Supported starting with Windows 8.1.

### `SupportRuntimePowerManagement` [out]

If **TRUE**, the display miniport driver supports run-time power management.

If this member is set, the display miniport driver must implement the [*DxgkDdiSetPowerComponentFState*](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddisetpowercomponentfstate) and [*DxgkDdiPowerRuntimeControlRequest*](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddipowerruntimecontrolrequest) functions.

Supported starting with Windows 8.

### `SupportSurpriseRemovalInHibernation` [out]

If **TRUE**, the display miniport driver supports cleaning up software resources after an external display device in hibernation mode is disconnected from the system.

If this member is set, the display miniport driver must implement the [*DxgkDdiNotifySurpriseRemoval*](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_notify_surprise_removal) function with the *RemovalType* parameter set to **DxgkRemovalHibernation**.

For more information, see [Using cross-adapter resources in a hybrid system](https://learn.microsoft.com/windows-hardware/drivers/display/using-cross-adapter-resources-in-a-hybrid-system).

Supported starting with Windows 8.

### `HybridDiscrete` [out]

If **TRUE**, the display miniport driver is a discrete GPU in a [hybrid system](https://learn.microsoft.com/windows-hardware/drivers/display/using-cross-adapter-resources-in-a-hybrid-system).

If this member is set, the display miniport driver should:

* support WDDM 1.3
* support cross-adapter resources
* have no display outputs

For more information, see [Using cross-adapter resources in a hybrid system](https://learn.microsoft.com/windows-hardware/drivers/display/using-cross-adapter-resources-in-a-hybrid-system).

Supported starting with Windows 8.1.

### `MaxOverlayPlanes` [out]

If **SupportRuntimePowerManagement** is **TRUE**, the display miniport driver should set **MaxOverlayPlanes** to the maximum number of overlay planes that can be simultaneously displayed on a single output, including the primary surface, that it can support. If the number of available planes will change when the operating mode changes, the driver should use a number that reflects the best-case scenario.

Supported starting with Windows 8.1.

### `HybridIntegrated`

Indicates whether the current GPU is hybrid.

### `InternalGpuVirtualAddressRangeStart`

Internal GPU virtual address range start.

### `InternalGpuVirtualAddressRangeEnd`

Internal GPU virtual address range end.

### `SupportSurpriseRemoval`

If TRUE, the display miniport driver supports surprise removal.

### `SupportMultiPlaneOverlayImmediateFlip` [out]

If TRUE, the display miniport driver supports immediate flips to a multiplane overlay plane as long as the only value changing is the physical address to be displayed.

### `CursorScaledWithMultiPlaneOverlayPlane0` [out]

If TRUE, the display hardware will always apply the same scaling factor to the hardware cursor as is applied to plane 0 when per plane multiplane overlay stretching is applied.

### `HybridAcpiChainingRequired`

Indicates that this hybrid discrete driver requires chaining of ACPI events triggered on the integrated adapter.

### `MaxQueuedMultiPlaneOverlayFlipVSync` [out]

Indicates the maximum number of updates to a single plane can be made within a single Vsync period, where the most recent update overrides the previous update. If a driver supports [hardware flip queue](https://learn.microsoft.com/windows-hardware/drivers/display/hardware-flip-queue), the OS ignores this value.

### `MiscCaps`

Miscellaneous capabilities.

### `MiscCaps.SupportContextlessPresent`

Supports null context in DDI calls. When this value is set, the OS will pass NULL context in present related DDIs. Supported starting in WDDM 2.4.

### `MiscCaps.Detachable`

Detachable, i.e. hot-pluggable. Drivers will set this bit during adapter initialization if the adapter is hot-pluggable. Supported starting in WDDM 2.4.

### `MiscCaps.VirtualGpuOnly`

The adapter should not be used by Direct3D applications on the host. Supported starting in WDDM 2.5.

### `MiscCaps.ComputeOnly`

Supports Compute-Only devices by rendering WDDM's render-only device capabilities. Supported starting in Windows 10, version 1901 (WDDM 2.6)

### `MiscCaps.IndependentVidPnVSyncControl`

Drivers that set this capability should read the specified VidPnSourceId in DdiControlInterrupt3 and control VSync on the mentioned VidPnSourceId. Supported starting in Windows 10, version 2004 (WDDM 2.7).

### `MiscCaps.NoHybridDiscreteDListDllSupport`

Indicates whether a driver supports a d-List. Supported starting in Windows 10, version 2004 (WDDM 2.8).

### `MiscCaps.DisplayableSupport`

Indicates whether a driver supports the displayable feature. Supported starting in Windows 11 (WDDM 3.0).

### `MiscCaps.Reserved`

Reserved.

### `MiscCaps.Value`

An alternative way to access the **MiscCaps** bits.

### `MaxHwQueuedFlips`

The maximum number of hardware flip queues that the driver supports. If the OS allows hardware flip queue support, the driver can set **MaxHwQueuedFlips** to a value greater than 1. Added in Windows Server 2022 (WDDM 2.9); supported starting in Windows 11 (WDDM 3.0).

### `HwQueuedFlipCaps`

A [**DXGK_HWQUEUEDFLIP_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgk_hwqueuedflip_caps) value that describes hardware flip queue capabilities. Added in Windows Server 2022 (WDDM 2.9); supported starting in Windows 11 (WDDM 3.0).

## See also

[*DxgkDdiUpdateActiveVidPnPresentPath*](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_updateactivevidpnpresentpath)

[**DXGK_VIDSCHCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_vidschcaps)

[*DxgkDdiStopDeviceAndReleasePostDisplayOwnership*](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_stop_device_and_release_post_display_ownership)

[*CheckDirectFlipSupport*](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_checkdirectflipsupport)

[**DXGK_POINTERFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_pointerflags)

[**D3DKMDT_PREEMPTION_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_preemption_caps)

[**DXGK_GAMMARAMPCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_gammarampcaps)

[*DxgkDdiQueryAdapterInfo*](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo)

[**DXGK_PRESENTATIONCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_presentationcaps)

[**DXGK_VIDMMCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_vidmmcaps)

[**DXGK_GPUENGINETOPOLOGY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_gpuenginetopology)

[*DxgkDdiQueryEngineStatus*](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryenginestatus)

[*DxgkDdiSetPowerComponentFState*](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddisetpowercomponentfstate)

[*DxgkDdiSetVidPnSourceAddress*](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setvidpnsourceaddress)

[*DxgkDdiResetEngine*](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_resetengine)

[*DxgkDdiPowerRuntimeControlRequest*](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddipowerruntimecontrolrequest)

[*DxgkCbNotifyInterrupt*](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_notify_interrupt)

[*DxgkDdiNotifySurpriseRemoval*](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_notify_surprise_removal)

[*DxgkDdiQueryDependentEngineGroup*](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_querydependentenginegroup)

[**DXGK_FLIPCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_flipcaps)

[**DXGKARG_QUERYADAPTERINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_queryadapterinfo)