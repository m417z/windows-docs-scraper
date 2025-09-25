# D3DKMDT_VIDPN_SOURCE_MODE structure

## Description

The **D3DKMDT_VIDPN_SOURCE_MODE** structure contains information about a video present network (VidPN) source mode.

## Members

### `Id`

An integer that identifies the source mode. The identifier is generated and filled in by the VidPN manager. However, the display miniport driver has the option of overwriting the identifier. For more information, see [**pfnCreateNewModeInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_vidpnsourcemodeset_createnewmodeinfo).

### `Type`

A [**D3DKMDT_VIDPN_SOURCE_MODE_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_vidpn_source_mode_type) enumerator that indicates the mode type: graphics or text.

### `Format`

A union that contains information about either the graphics rendering format or the text format in the following members.

### `Format.Graphics`

A [**D3DKMDT_GRAPHICS_RENDERING_FORMAT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_graphics_rendering_format) structure that contains information about the graphics rendering format (for example, primary surface size and pixel format). This member is meaningful only if the **Type** member is equal to D3DKMDT_RMT_GRAPHICS.

### `Format.Text`

A [**D3DKMDT_TEXT_RENDERING_FORMAT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_text_rendering_format) enumerator that indicates the text format. This member is meaningful only if the **Type** member is equal to D3DKMDT_RMT_TEXT.

## Remarks

For more information about video present sources and VidPN source modes, see [Introduction to Video Present Networks](https://learn.microsoft.com/windows-hardware/drivers/display/introduction-to-video-present-networks) and [Enumerating Cofunctional VidPN Source and Target Modes](https://learn.microsoft.com/windows-hardware/drivers/display/enumerating-cofunctional-vidpn-source-and-target-modes).

## See also

[**D3DKMDT_MONITOR_SOURCE_MODE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_monitor_source_mode)

[**D3DKMDT_VIDPN_TARGET_MODE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_target_mode)