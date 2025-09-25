# DXGKCB_NOTIFY_INTERRUPT_DATA_FLAGS structure

## Description

The **DXGKCB_NOTIFY_INTERRUPT_DATA_FLAGS** structure indicates whether the display miniport driver provides a physical adapter mask in a call to the [**DXGKCB_NOTIFY_INTERRUPT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_notify_interrupt) function.

## Members

### `ValidPhysicalAdapterMask`

Specifies whether the driver provides a physical adapter mask. If this member is set, the driver provides a physical adapter mask in the **PhysicalAdapterMask** member of the **CrtcVsync** structure that is contained in the [**DXGKARGCB_NOTIFY_INTERRUPT_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_notify_interrupt_data) structure.

Setting this member is equivalent to setting the first bit of the 32-bit **Value** member (0x00000001).

### `HsyncFlipCompletion`

Specifies whether the Hsync flip has been completed.

### `EvaluateLegacyMonitoredFences`

When set, indicates to the OS to scan all waiters (legacy monitored fence waiter & native fence waiters). For more information, see [Native GPU fence objects](https://learn.microsoft.com/windows-hardware/drivers/display/native-gpu-fence-objects). Available starting with Windows 11, version 22H2 (WDDM 3.2).

### `Reserved`

This member is reserved and should be set to zero.

### `Value`

An alternative way to access to bit fields of this structure.

## See also

[**DXGKARGCB_NOTIFY_INTERRUPT_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_notify_interrupt_data)

[**DXGKCB_NOTIFY_INTERRUPT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_notify_interrupt)