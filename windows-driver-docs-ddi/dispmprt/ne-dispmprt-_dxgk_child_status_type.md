# _DXGK_CHILD_STATUS_TYPE enumeration

## Description

The DXGK_CHILD_STATUS_TYPE enumeration indicates the type of status being requested or reported for a child device of the display adapter.

## Constants

### `StatusUninitialized`

Indicates that a variable of type DXGK_CHILD_STATUS_TYPE has not yet been assigned a meaningful value.

### `StatusConnection`

Indicates that the request or report pertains to whether the child device has a monitor (or other display device) connected to it.

### `StatusRotation`

Indicates that the request or report pertains to the rotation angle of the monitor (or other display device) that is connected to the child device.

### `StatusMiracastConnection`

Indicates that the request or report pertains to a monitor (or other display device) that is connected wirelessly to the child device through a Miracast connected session.

Supported by WDDM 1.3 and later drivers running on Windows 8.1 and later.

## Remarks

The **Type** member of a [DXGK_CHILD_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_child_status) structure is a member of the **DXGK_CHILD_STATUS_TYPE** enumeration.

## See also

[DxgkCbIndicateChildStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_indicate_child_status)

[DxgkDdiQueryChildStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_child_status)