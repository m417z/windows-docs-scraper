## Description

The *DxgkDdiSetVidPnSourceAddress* function sets the address of the primary surface that is associated with a particular video present source.

## Parameters

### `hAdapter`

A handle to a context block that is associated with a display adapter. The display miniport driver previously provided this handle to the DirectX graphics kernel subsystem in the *MiniportDeviceContext* output parameter of the [**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

### `pSetVidPnSourceAddress`

A pointer to a [**DXGKARG\_SETVIDPNSOURCEADDRESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_setvidpnsourceaddress) structure that contains function arguments.

## Return value

*DxgkDdiSetVidPnSourceAddress* returns STATUS\_SUCCESS if it succeeds; otherwise, it returns one of the error codes defined in *Ntstatus.h*.

Starting with Windows 8, the display miniport driver can fail a call to *DxgkDdiSetVidPnSourceAddress*, returning STATUS\_INVALID\_PARAMETER, when the **SharedPrimaryTransition** member is set in *pSetVidPnSourceAddress*-\>**Flags**. However, such a failure is not expected unless there is an error in either the user mode driver's implementation of the [*CheckDirectFlipSupport*](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_checkdirectflipsupport) function or in the DWM. If such a failure occurs, the operating system will not seamlessly fail back to composition mode, and presentation will be incorrect.

## Remarks

*DxgkDdiSetVidPnSourceAddress* is called only with primaries that fit with the currently committed video present network (VidPN) topology. For example, the D3DDDIFMT\_A8R8G8B8 format is determined to fit with a VidPN that is committed to a D3DDDIFMT\_X8R8G8B8 format, and vice versa.

The DirectX graphics kernel subsystem calls *DxgkDdiSetVidPnSourceAddress* to switch the display mode and to perform memory-mapped I/O (MMIO)–based flip operations. The bit-field flags in the **Flags** member of the [**DXGKARG\_SETVIDPNSOURCEADDRESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_setvidpnsourceaddress) structure that is pointed to by the *pSetVidPnSourceAddress* parameter indicates the type of display operation to perform. To switch the display mode, the graphics kernel subsystem sets the **ContextCount** member of DXGKARG\_SETVIDPNSOURCEADDRESS to zero. In this situation, the content of the array that the **Context** member of DXGKARG\_SETVIDPNSOURCEADDRESS specifies is undefined. To perform a flip operation, the graphics kernel subsystem sets **ContextCount** to the number of contexts and **Context** to the array of driver context handles for the contexts that contribute to the flip operation.

If the display miniport driver previously indicated, in a call to its [**DxgkDdiQueryAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo) function, that it supports a MMIO-based flip (by setting the **FlipOnVSyncMmIo** bit-field flag in the **FlipCaps** member of the [**DXGK\_DRIVERCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_drivercaps) structure to **TRUE**), the driver's *DxgkDdiSetVidPnSourceAddress* function is subsequently called at device interrupt request level (DIRQL) for flip purposes. The driver's *DxgkDdiSetVidPnSourceAddress* function must program the DAC and start scanning out, at the following vertical sync, the primary surface whose address is specified in the **PrimaryAddress** member of DXGKARG\_SETVIDPNSOURCEADDRESS. The driver also must pass the DXGK\_INTERRUPT\_CRTC\_VSYNC interrupt type in the *InterruptType* parameter in a call to the [**DxgkCbNotifyInterrupt**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_notify_interrupt) function to report the effective scan address. The driver must follow the call to **DxgkCbNotifyInterrupt** with a call to the [**DxgkCbNotifyDpc**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_notify_dpc) function.

*DxgkDdiSetVidPnSourceAddress* must be in nonpageable memory. *DxgkDdiSetVidPnSourceAddress* must not call any code that is in pageable memory and must not manipulate any data that is in pageable memory.

### Clone-View Situations

In clone-view situations, the display miniport driver should handle flip operations appropriately as described in this section.

When the DWM is running, the DirectX graphics kernel subsystem flip-synchronizes when a vertical sync occurs. However, the DirectX graphics kernel subsystem can synchronize only when a vertical sync of a single graphics adapter output signal occurs. The DirectX graphics kernel subsystem must immediately flip any other graphics adapter output signals to avoid tearing.

The GPU scheduler will detect a single vertical sync and will determine that the flipped surface is available as soon as the first monitor flip occurs. As a result, the display miniport driver might be rendering to a surface that the second monitor is still displaying.

Video applications (for example, Windows Media Player) are unaware of clone-view situations and expect to have a predictable vertical-sync interval. If the GPU scheduler detected the vertical syncs of both monitors, the vertical sync interval (and therefore the flip) would be unpredictable and would drift over time, which would cause the DWM and video applications to not operate correctly.

For clone-view situations, the display miniport driver must perform a vertical-sync flip on the primary monitor and an MMIO-based immediate flip on the secondary monitor.

The display miniport driver's *DxgkDdiSetVidPnSourceAddress* function should record the address that is being flipped to in the graphics adapter object.

To direct the display miniport driver to not wait for the next vertical retrace of the secondary monitor, the DirectX graphics kernel subsystem sets the **FlipImmediate** bit-field flag to **TRUE** in a call to the driver's *DxgkDdiSetVidPnSourceAddress* function.

See requirements on calling this function with multiplane overlays in [Multiplane overlay VidPN presentation](https://learn.microsoft.com/windows-hardware/drivers/display/multiplane-overlay-vidpn-presentation).

## See also

[**DXGK\_DRIVERCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_drivercaps)

[**DXGKARG\_SETVIDPNSOURCEADDRESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_setvidpnsourceaddress)

[**DxgkCbNotifyDpc**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_notify_dpc)

[**DxgkCbNotifyInterrupt**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_notify_interrupt)

[**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)

[**DxgkDdiSetVidPnSourceVisibility**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setvidpnsourcevisibility)

[**DxgkDdiQueryAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo)