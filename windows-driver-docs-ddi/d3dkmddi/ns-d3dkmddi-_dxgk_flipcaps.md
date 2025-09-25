# _DXGK_FLIPCAPS structure

## Description

The **DXGK_FLIPCAPS** structure identifies flipping capabilities of the display miniport driver that the driver provides through a call to its [DxgkDdiQueryAdapterInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo) function.

## Members

### `FlipOnVSyncWithNoWait`

A **UINT** value that specifies whether the driver supports the scheduling of a flip command that will take effect on the next vertical retrace period (vertical sync) without causing the graphics pipeline to stall until that vertical sync occurs. That is, the graphics pipeline must proceed immediately after the driver writes the physical address of the flipping surface into flip-pending registers at the hardware. Although most hardware uses a depth of one flip-pending register, if hardware uses more than one flip-pending register, the driver should specify the number in the **MaxQueuedFlipOnVSync** member of the [DXGK_DRIVERCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_drivercaps) structure.

If **FlipOnVSyncWithNoWait** is set to 1 (**TRUE**), the driver supports this mechanism. If **FlipOnVSyncWithNoWait** is set to 0 (**FALSE**), the driver does not support this mechanism. That is, the graphics pipeline must wait until the next vertical sync occurs after the scheduling of a flip command to take effect on the next vertical sync.

Setting this member is equivalent to setting the first bit of the 32-bit **Value** member (0x00000001).

### `FlipOnVSyncMmIo`

A **UINT** value that specifies whether the driver supports a memory mapped I/O (MMIO)-based flip that takes effect on the next vertical sync. To support this type of flip, the display miniport driver must support the following operations:

* No generation of a DMA buffer to pass in a call to its [DxgkDdiPresent](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_present) function (that is, **NULL** is passed in the **pDmaBuffer** member of the [DXGKARG_PRESENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_present) structure).
* A flip through a call to its [DxgkDdiSetVidPnSourceAddress](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff560767(v=vs.85)) function at device interrupt request level (DIRQL). In the call to *DxgkDdiSetVidPnSourceAddress*, the driver should program the digital-to-analog converter (DAC) and use the value in the **PrimaryAddress** member of the [DXGKARG_SETVIDPNSOURCEADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_setvidpnsourceaddress) structure to start the scan out. After the vertical sync, the driver should notify the GPU scheduler to report the effective scan address by calling the [DxgkCbNotifyInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_notify_interrupt) function with the **DXGK_INTERRUPT_CRTC_VSYNC** value set in the **InterruptType** member of the [DXGKARGCB_NOTIFY_INTERRUPT_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_notify_interrupt_data) structure. The driver should then call the [DxgkCbNotifyDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_notify_dpc) function to perform most of the scan-out processing.

### `FlipInterval`

A **UINT** value that specifies whether the driver supports the scheduling of a flip command to take effect after two, three, or four vertical syncs occur. Regardless of whether the driver supports a flip interval of two or greater, the driver must support an immediate flip and a flip interval of one.

Setting this member is equivalent to setting the third bit of the 32-bit **Value** member (0x00000004).

### `FlipImmediateMmIo`

A **UINT** value that specifies whether the driver supports a memory mapped I/O (MMIO)-based immediate flip. This type of flip takes effect immediately following a call to the driver's [DxgkDdiSetVidPnSourceAddress](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff560767(v=vs.85)) function without waiting for the next vertical sync to occur.

Setting this member is equivalent to setting the fourth bit of the 32-bit **Value** member (0x00000008).

Supported starting with Windows 7.

### `FlipIndependent`

A **UINT** value that specifies whether the driver supports an independent flip. WDDM 1.3 and later drivers must set this member to 1.

In an *independent flip*, the operating system attempts to bypass a Desktop Window Manager (DWM) user-mode present call and flips to the application back buffer by calling [DxgkDdiPresent](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_present) and [DxgkDdiSetVidPnSourceAddress](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff560767(v=vs.85)) in Direct Flip and multiplane overlay presentation models.

Note that there will be cases when a DWM user-mode present call is made even when **FlipIndependent** is set. Your driver must still handle such cases.

Setting this member is equivalent to setting the fifth bit of the 32-bit **Value** member (0x00000010).

Supported starting with Windows 8.1.

### `DdiPresentForIFlip`

### `FlipImmediateOnHSync`

### `Reserved`

This member is reserved and should be set to zero. Setting this member to zero is equivalent to setting the remaining 27 bits (0xFFFFFFE0) of the 32-bit **Value** member to zeros.

This member is reserved and should be set to zero. Setting this member to zero is equivalent to setting the remaining 28 bits (0xFFFFFFF0) of the 32-bit **Value** member to zeros.

### `Value`

A member in the union that DXGK_FLIPCAPS contains that can hold a 32-bit value that identifies flipping capabilities.

## See also

[DXGKARGCB_NOTIFY_INTERRUPT_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_notify_interrupt_data)

[DXGKARG_PRESENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_present)

[DXGKARG_QUERYADAPTERINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_queryadapterinfo)

[DXGKARG_SETVIDPNSOURCEADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_setvidpnsourceaddress)

[DXGK_DRIVERCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_drivercaps)

[DxgkCbNotifyDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_notify_dpc)

[DxgkCbNotifyInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_notify_interrupt)

[DxgkDdiPresent](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_present)

[DxgkDdiQueryAdapterInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo)

[DxgkDdiSetVidPnSourceAddress](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff560767(v=vs.85))