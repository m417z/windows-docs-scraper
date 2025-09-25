# _DDRAW_MODE_SPECIFIC_CAPS structure

## Description

The DDRAW_MODE_SPECIFIC_CAPS structure describes Microsoft DirectDraw capabilities that are specific to a particular display device (head) on the graphics card.

## Members

### `Head` [in]

The display device (head) on the multiple-head graphics card to retrieve capabilities about.

### `Caps` [out]

A valid bitwise OR of the following general capability bits that the driver supports.

| **Capability bit** | **Meaning** |
|:--|:--|
| MODE_CAPS_OVERLAY (0x00000001) | Overlay operations can be performed. |
| MODE_CAPS_OVERLAYSTRETCH (0x00000002) | Overlay operations can be performed simultaneously with stretching. |
| MODE_CAPS_CANBOBINTERLEAVED (0x00000004) | The overlay hardware can display each field of an interlaced video stream individually while it is interleaved in memory without causing any artifacts that might typically occur without special hardware support. This option is valid only when the surface is receiving data from a VPE object and is valid only when the video is zoomed at least 200 percent in the vertical direction. |
| MODE_CAPS_CANBOBNONINTERLEAVED (0x00000008) | The overlay hardware can display each field of an interlaced video stream individually while it is not interleaved in memory without causing any artifacts that might typically occur without special hardware support. This option is valid only when the surface is receiving data from a VPE object and is valid only when the video is zoomed at least 200 percent in the vertical direction. |
| MODE_CAPS_CANFLIPODDEVEN (0x00000010) | The driver supports bob-style deinterlacing that uses software without using a VPE object. |
| MODE_CAPS_READSCANLINE (0x00000020) | The current scan line can be read and returned. |
| MODE_CAPS_COLORCONTROLOVERLAY (0x00000040) | The driver supports color-control settings for an overlay. For information about setting and retrieving color-control settings, see the [GetOverlayColorControls](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getoverlaycolorcontrols) and [SetOverlayColorControls](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setoverlaycolorcontrols) functions. |

### `CKeyCaps` [out]

A valid bitwise OR of the following color key capability bits that the driver supports.

| **Capability bit** | **Meaning** |
|:--|:--|
| MODE_CKEYCAPS_DESTOVERLAY (0x00000001) | Overlaying operations that use color keying of the replaceable bits of the destination surface that is being overlaid for RGB colors can be performed. |
| MODE_CKEYCAPS_DESTOVERLAYYUV (0x00000002) | Overlaying operations that use color keying of the replaceable bits of the destination surface that is being overlaid for YUV colors can be performed. |
| MODE_CKEYCAPS_SRCOVERLAY (0x00000004) | Overlaying operations that use the color key for the source with this overlay surface for RGB colors can be performed. |
| MODE_CKEYCAPS_SRCOVERLAYCLRSPACE (0x00000008) | Overlaying operations that use a color space as the source color key for the overlay surface for RGB colors can be performed. |
| MODE_CKEYCAPS_SRCOVERLAYCLRSPACEYUV (0x00000010) | Overlaying operations that use a color space as the source color key for the overlay surface for YUV colors can be performed. |
| MODE_CKEYCAPS_SRCOVERLAYYUV (0x00000020) | Overlaying operations that use the color key for the source with this overlay surface for YUV colors can be performed. |

### `FxCaps` [out]

A valid bitwise OR of the following effects capability bits that the driver supports.

| **Capability bit** | **Meaning** |
|:--|:--|
| MODE_FXCAPS_OVERLAYSHRINKX (0x00000001) | Arbitrary shrinking of an overlay surface along the x-axis (horizontally) can be performed. |
| MODE_FXCAPS_OVERLAYSHRINKY (0x00000002) | Arbitrary shrinking of an overlay surface along the y-axis (vertically) can be performed. |
| MODE_FXCAPS_OVERLAYSTRETCHX (0x00000004) | Arbitrary stretching of an overlay surface along the x-axis (horizontally) can be performed. |
| MODE_FXCAPS_OVERLAYSTRETCHY (0x00000008) | Arbitrary stretching of an overlay surface along the y-axis (vertically) can be performed. |
| MODE_FXCAPS_OVERLAYMIRRORLEFTRIGHT (0x00000010) | Mirroring of overlays around the vertical axis can be performed. |
| MODE_FXCAPS_OVERLAYMIRRORUPDOWN (0x00000020) | Mirroring of overlays across the horizontal axis can be performed. |
| MODE_FXCAPS_OVERLAYDEINTERLACE (0x00000040) | Deinterlacing of an overlay surface can be performed. |

### `MaxVisibleOverlays` [out]

The maximum number of visible overlays.

### `MinOverlayStretch` [out]

The minimum overlay stretch factor multiplied by 1000. For example, a factor of 1.3 should be stored as 1300. The display driver must set the minimum factor to the actual minimum to which the graphics hardware can shrink the overlay. If the graphics hardware has no minimum limitation, set **MinOverlayStretch** to 1.

### `MaxOverlayStretch` [out]

The maximum overlay stretch factor multiplied by 1000. For example, a factor of 1.3 should be stored as 1300. The display driver must set the maximum factor to the actual maximum to which the graphics hardware can stretch the overlay. If the graphics hardware has no maximum limitation, set **MaxOverlayStretch** to 32000.

## Remarks

Capabilities can change between heads of a multiple-headed graphics card and can change after a display mode change.

## See also

[D3DDDIARG_GETCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getcaps)

[D3DDDICAPS_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_d3dddicaps_type)

[GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps)