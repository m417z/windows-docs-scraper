# _DXGK_CHILD_DEVICE_HPD_AWARENESS enumeration

## Description

The DXGK_CHILD_DEVICE_HPD_AWARENESS enumeration is used to describe the hot plug capabilities of a child device of a display adapter.

## Constants

### `HpdAwarenessUninitialized`

Indicates that a variable of type DXGK_CHILD_DEVICE_HPD_AWARENESS has not yet been assigned a meaningful value.

### `HpdAwarenessAlwaysConnected`

Indicates that the child device is always connected; that is, it does not serve as a connector for external devices.

### `HpdAwarenessNone`

Reserved for system use. You should not use this value.

### `HpdAwarenessPolled`

Indicates that the display miniport driver is able to determine whether an external device is connected to the child device by polling the child device.

### `HpdAwarenessInterruptible`

Indicates that the child device is able to generate an interrupt when an external device is connected or disconnected.

## Remarks

The **ChildCapabilities** member of a [DXGK_CHILD_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_child_descriptor) structure is a [DXGK_CHILD_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_child_capabilities) structure. The **HpdAwareness** member of a **DXGK_CHILD_DEVICE_HPD_AWARENESS** structure is a **DXGK_CHILD_CAPABILITIES** structure.

## See also

[DxgkDdiQueryChildRelations](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_child_relations)