# D3DKMDT_VIDEO_OUTPUT_TECHNOLOGY enumeration

## Description

A **D3DKMDT_VIDEO_OUTPUT_TECHNOLOGY** enumeration value indicates the type of connector a video output device (on the display adapter) uses to connect to an external display device.

## Constants

### `D3DKMDT_VOT_UNINITIALIZED:-2`

A variable of type **D3DKMDT_VIDEO_OUTPUT_TECHNOLOGY** has not yet been assigned a meaningful value.

### `D3DKMDT_VOT_OTHER:-1`

The video output device connects to an external display device through a connector that is not one of the types that is indicated by the following values in this enumeration.

### `D3DKMDT_VOT_HD15:0`

The video output device connects to an external display device through an HD15 (VGA) connector.

### `D3DKMDT_VOT_SVIDEO:1`

The video output device connects to an external display device through an S-video connector.

### `D3DKMDT_VOT_COMPOSITE_VIDEO:2`

The video output device connects to an external display device through composite video connectors.

### `D3DKMDT_VOT_COMPONENT_VIDEO:3`

The video output device connects to an external display device through component video connectors.

### `D3DKMDT_VOT_DVI:4`

The video output device connects to an external display device through a Digital Video Interface (DVI) connector.

### `D3DKMDT_VOT_HDMI:5`

The video output device connects to an external display device through an High-Definition Multimedia Interface (HDMI) connector.

### `D3DKMDT_VOT_LVDS:6`

The video output device connects to an external display device through an Low Voltage Differential Swing (LVDS) or Mobile Industry Processor Interface (MIPI) Digital Serial Interface (DSI) connector.

### `D3DKMDT_VOT_D_JPN:8`

The video output device connects to an external display device through a D-Jpn connector.

### `D3DKMDT_VOT_SDI:9`

The video output device connects to an external display device through an SDI connector.

### `D3DKMDT_VOT_DISPLAYPORT_EXTERNAL:10`

The connector type is an external display port.

### `D3DKMDT_VOT_DISPLAYPORT_EMBEDDED:11`

The connector type is an embedded display port.

### `D3DKMDT_VOT_UDI_EXTERNAL:12`

The connector type is an external Unified Display Interface (UDI).

### `D3DKMDT_VOT_UDI_EMBEDDED:13`

The connector type is an embedded UDI.

### `D3DKMDT_VOT_SDTVDONGLE:14`

The video output device connects to an external display device through a dongle cable that supports SDTV.

### `D3DKMDT_VOT_MIRACAST:15`

The video output device connects to an external display device wirelessly through a Miracast connected session. For more info, see [Wireless displays (Miracast)](https://learn.microsoft.com/windows-hardware/drivers/display/wireless-displays--miracast-). Supported starting with Windows 8.1 (WDDM 1.3)

### `D3DKMDT_VOT_INDIRECT_WIRED:16`

The video output device connects to a wired indirect display device. Supported starting with Windows 10 version 1607 (WDDM 2.1).

### `D3DKMDT_VOT_INTERNAL:0x80000000`

The video output device connects internally to a display device (for example, the internal connection in a laptop computer). This constant value is not a bit-field value. Instead, it's a standalone video output type.

### `D3DKMDT_VOT_SVIDEO_4PIN:D3DKMDT_VOT_SVIDEO`

The video output device connects to an external display device through a 4-pin S-video connector.

### `D3DKMDT_VOT_SVIDEO_7PIN:D3DKMDT_VOT_SVIDEO`

The video output device connects to an external display device through a 7-pin S-video connector.

### `D3DKMDT_VOT_RF:D3DKMDT_VOT_COMPOSITE_VIDEO`

The video output device connects to an external display device through an RF connector.

### `D3DKMDT_VOT_RCA_3COMPONENT:D3DKMDT_VOT_COMPOSITE_VIDEO`

The video output device connects to an external display device through a set of three RCA connectors.

### `D3DKMDT_VOT_BNC:D3DKMDT_VOT_COMPOSITE_VIDEO`

The video output device connects to an external display device through a BNC connector.

## Remarks

The **ChildCapabilities** member of a [**DXGK_CHILD_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_child_descriptor) structure is a [**DXGK_CHILD_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_child_capabilities) structure whose **Type.VideoOutput** member is a [**DXGK_VIDEO_OUTPUT_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_video_output_capabilities) structure. The **InterfaceTechnology** member of a DXGK_VIDEO_OUTPUT_CAPABILITIES structure is a single **D3DKMDT_VIDEO_OUTPUT_TECHNOLOGY** value.

## See also

[**DXGK_VIDEO_OUTPUT_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_video_output_capabilities)

[**DxgkDdiQueryChildRelations**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_child_relations)