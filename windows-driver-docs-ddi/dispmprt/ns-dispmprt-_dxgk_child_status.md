# _DXGK_CHILD_STATUS structure

## Description

The DXGK_CHILD_STATUS structure contains members that indicate the status of a child device of the display adapter.

## Members

### `Type`

A member of the [DXGK_CHILD_STATUS_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ne-dispmprt-_dxgk_child_status_type) enumeration that indicates the type of status being requested.

### `ChildUid`

An integer, created previously by the display miniport driver, that identifies the child device for which status is being requested.

### `HotPlug`

### `HotPlug.Connected`

If **Type** is equal to [DXGK_CHILD_STATUS_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ne-dispmprt-_dxgk_child_status_type).**StatusConnection**, indicates whether the child device has external hardware (for example, a monitor) connected to it. A value of **TRUE** indicates that hardware is connected; **FALSE** indicates that hardware is not connected.

### `Rotation`

### `Rotation.Angle`

If **Type** is equal to [DXGK_CHILD_STATUS_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ne-dispmprt-_dxgk_child_status_type).**StatusRotation**, indicates the angle of rotation of the display connected to the child device.

### `Miracast`

Supported by WDDM 1.3 and later display miniport drivers running on Windows 8.1 and later.

### `Miracast.Connected`

If **Type** is equal to [DXGK_CHILD_STATUS_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ne-dispmprt-_dxgk_child_status_type).**StatusMiracast**, indicates whether a Miracast connected session has started. A value of **TRUE** indicates that a new monitor has been connected to the Miracast sink, or that the Miracast session has started with a monitor connected. **FALSE** indicates that the monitor that was connected to the Miracast sink has been unplugged, or that the Miracast session has been stopped.

For more info, see [Wireless displays (Miracast)](https://learn.microsoft.com/windows-hardware/drivers/display/wireless-displays--miracast-).

### `Miracast.MiracastMonitorType`

If the **Connected** member of the **Miracast** embedded structure is **TRUE**, indicates the connector type of the connection between the Miracast sink and the monitor or TV.

Alternately, if **Connected** is **TRUE** and the Miracast sink is embedded in the monitor or TV, the display miniport driver should set this value to **D3DKMDT_VOT_MIRACAST**.

If the driver doesn't know the monitor connection state, it should set this value to the last monitor connection state from the [D3DKMDT_VIDEO_OUTPUT_TECHNOLOGY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_video_output_technology) enumeration that it reported to the operating system.

For more info, see [Wireless displays (Miracast)](https://learn.microsoft.com/windows-hardware/drivers/display/wireless-displays--miracast-).

## See also

[D3DKMDT_VIDEO_OUTPUT_TECHNOLOGY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_video_output_technology)

[DXGK_CHILD_STATUS_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ne-dispmprt-_dxgk_child_status_type)

[DxgkCbIndicateChildStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_indicate_child_status)

[DxgkDdiQueryChildRelations](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_child_relations)

[DxgkDdiQueryChildStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_child_status)