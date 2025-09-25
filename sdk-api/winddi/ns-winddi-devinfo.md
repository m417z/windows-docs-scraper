# DEVINFO structure

## Description

The DEVINFO structure provides information about the driver and its private [PDEV](https://learn.microsoft.com/windows-hardware/drivers/) to the graphics engine.

## Members

### `flGraphicsCaps`

Is a set of flags that describe graphics capabilities of the graphics driver and/or its hardware. These flags are defined in the following table.

| Flag | Definition |
| --- | --- |
| GCAPS_ALTERNATEFILL | Handles alternating fills. |
| GCAPS_ARBRUSHOPAQUE | Supports an arbitrary brush for text opaque rectangle (background color). |
| GCAPS_ARBRUSHTEXT | Supports an arbitrary brush for the text foreground color. |
| GCAPS_ASYNCCHANGE | This flag is obsolete. In legacy drivers, this flag indicates that the driver can change the pointer shape in hardware while other drawing is occurring on the device. |
| GCAPS_ASYNCMOVE | The driver can move the pointer in hardware while other drawing is occurring on the device. |
| GCAPS_BEZIERS | Handles Bezier curves. |
| GCAPS_CMYKCOLOR | The driver supports the CYMK color space. |
| GCAPS_COLOR_DITHER | Handles color dithering to a PDEV-compatible surface. |
| GCAPS_DIRECTDRAW | This flag is obsolete. |
| GCAPS_DITHERONREALIZE | Specifies that GDI can call [DrvRealizeBrush](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvrealizebrush) with the RGB to be dithered directly. |
| GCAPS_DONTJOURNAL | Disallows metafile printing to this printer driver. This is valid only for printer DCs and will generally result in slower return-to-application time when printing. |
| GCAPS_FONT_RASTERIZER | Device hardware can rasterize TrueType fonts. |
| GCAPS_FORCEDITHER | Allows dithering on all geometric pens. |
| GCAPS_GEOMETRICWIDE | Handles geometric widening. |
| GCAPS_GRAY16 | Handles antialiased text natively. |
| GCAPS_HALFTONE | Handles halftoning. |
| GCAPS_HIGHRESTEXT | This flag is obsolete. In legacy drivers, this flag indicates that the driver is requesting glyph positions as returned by the STROBJ in FIX point coordinates. |
| GCAPS_HORIZSTRIKE | This flag is obsolete. In legacy drivers, this flag indicates that the driver handles horizontal strikeouts in [DrvTextOut](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvtextout). |
| GCAPS_ICM | Indicates that color management operations can be performed by the driver or printer hardware. |
| GCAPS_LAYERED | Indicates that this is a layer or [mirror driver](https://learn.microsoft.com/windows-hardware/drivers/) for remoting. Printer drivers cannot be layer drivers. |
| GCAPS_MONO_DITHER | Handles monochrome dithering. |
| GCAPS_NO64BITMEMACCESS | This flag is obsolete. |
| GCAPS_NUP | Indicates that "N-up" printing is supported. |
| GCAPS_OPAQUERECT | Handles opaque rectangles in [DrvTextOut](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvtextout). |
| GCAPS_PALMANAGED | Supports palette management. |
| GCAPS_PANNING | When GDI is simulating the pointer, it should call [DrvMovePointer](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvmovepointer) to notify the driver of the current cursor position. This allows the driver to handle panning virtual displays. |
| GCAPS_SCREENPRECISION | The rasterizer (font engine) should choose a screen (soft) font over a device font when choosing a font for which there is no exact match. |
| GCAPS_VECTORFONT | Handles stroking of vector fonts in [DrvTextOut](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvtextout). |
| GCAPS_VERTSTRIKE | This flag is obsolete. In legacy drivers, this flag indicated that the driver handled vertical strikeouts in [DrvTextOut](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvtextout). |
| GCAPS_WINDINGFILL | Handles winding mode fills. See [Path Fill Modes](https://learn.microsoft.com/windows-hardware/drivers/display/path-fill-modes) for more information. |
| GCAPS2_REMOTEDRIVER | Indicates that the display driver is used to support a remote user session. |

### `lfDefaultFont`

Is an Extended Logical Font structure that specifies the default font for a device. For more information about this structure, see EXTLOGFONT in the Microsoft Windows SDK documentation.

### `lfAnsiVarFont`

Is an Extended Logical Font structure that specifies the default variable-pitch font for a device. For more information about this structure, see EXTLOGFONT in the Windows SDK documentation.

### `lfAnsiFixFont`

Is an Extended Logical Font structure that specifies the default fixed-pitch (monospaced) font for a device. For more information about this structure, see EXTLOGFONT in the Windows SDK documentation.

### `cFonts`

Specifies the number of device fonts. GDI assumes that the device can draw text with this number of fonts on its own surfaces and that the driver can provide metrics information about the fonts. If the driver sets **cFonts** to -1, GDI will wait until fonts are needed to query the driver for the actual number of fonts it supports in a call to [DrvQueryFont](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvqueryfont).

### `iDitherFormat`

Specifies the format of the bitmap. This parameter indicates how many bits of color information per pixel are requested, and must be one of the following values:

| Value | Meaning |
| --- | --- |
| BMF_1BPP | Monochrome |
| BMF_4BPP | 4 bits per pixel |
| BMF_8BPP | 8 bits per pixel |
| BMF_16BPP | 16 bits per pixel |
| BMF_24BPP | 24 bits per pixel |
| BMF_32BPP | 32 bits per pixel |
| BMF_4RLE | 4 bits per pixel, run length encoded |
| BMF_8RLE | 8 bits per pixel, run length encoded |
| BMF_JPEG | JPEG compressed image |
| BMF_PNG | PNG compressed image |

### `cxDither`

### `cyDither`

Specify the dimensions of a dithered brush. If these members are nonzero, then the device can create a dithered brush for a given RGB color.

### `hpalDefault`

Handle to the default palette for the device. The driver should create the palette by calling [EngCreatePalette](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreatepalette). The driver associates a palette with a device by returning this handle to GDI.

### `flGraphicsCaps2`

Is a set of flags that describe additional graphics capabilities of the device driver. These flags are defined in the following table.

| Flag | Definition |
| --- | --- |
| GCAPS2_ALPHACURSOR | Handles pointers with per-pixel alpha values. |
| GCAPS2_CHANGEGAMMARAMP | The display device has a loadable hardware [gamma ramp](https://learn.microsoft.com/windows-hardware/drivers/). |
| GCAPS2_EXCLUDELAYERED | Indicates that this is an accessibility mirror driver. Mirror drivers that do not set this flag will still receive drawing primitives for layered HWNDs. See [Mirror Drivers](https://learn.microsoft.com/windows-hardware/drivers/display/mirror-drivers) for more information. |
| GCAPS2_ICD_MULTIMON | Informs GDI that the driver intends to handle [DrvSetPixelFormat](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvsetpixelformat), [DrvDescribePixelFormat](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvdescribepixelformat), and [DrvSwapBuffers](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvswapbuffers) calls in a multimon environment, even when the rectangle in the operation also intersects another device. Only one device is ever given the opportunity to handle those calls. If the capability is not specified and the region involved intersects more than one device, no driver is called. |
| GCAPS2_INCLUDEAPIBITMAPS | When drawing calls are made to a device-independent bitmap (DIB), an accessibility mirror driver will be called. See [Mirror Drivers](https://learn.microsoft.com/windows-hardware/drivers/display/mirror-drivers) for more information. |
| GCAPS2_JPEGSRC | Device can accept JPEG compressed images (that is, images for which BMF_JPEG is set in the [SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj) structure). |
| GCAPS2_MOUSETRAILS | Indicates that the driver supports mouse trails (a succession of cursor images showing the mouse's location during a short period of time). The driver is capable of handling the values GDI sends in the *fl* parameter of the [DrvSetPointerShape](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvsetpointershape) function. The driver should use the SPS_LENGTHMASK and SPS_FREQMASK masks to obtain values for the length and frequency of the mouse trails. See **DrvSetPointerShape** for more information about these masks. |
| GCAPS2_PNGSRC | Device can accept PNG compressed images (that is, images for which BMF_PNG is set in the [SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj) structure). |
| GCAPS2_SYNCFLUSH | The driver supports a programmatic-based flush mechanism for batched graphics DDI calls. [DrvSynchronizeSurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvsynchronizesurface) will be called whenever GDI must flush any drawing that is being batched by the driver. |
| GCAPS2_SYNCTIMER | The driver supports a timer-based flush mechanism for batched graphics DDI calls. [DrvSynchronizeSurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvsynchronizesurface) will be called periodically, based on a timer interval determined by GDI. |

## Remarks

The driver's [DrvEnablePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablepdev) function fills in a DEVINFO structure; the driver should set only the members that are relevant to it. This structure is zero-initialized by GDI before **DrvEnablePDEV** is called. Applications do not have direct access to this structure.

If a driver sets GCAPS2_JPEGSRC or GCAPS2_PNGSRC in **flGraphicsCaps2**, the following rules apply:

* The driver must provide a [DrvQueryDeviceSupport](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvquerydevicesupport) function.
* Every driver-defined graphics DDI function that receives a [SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj) structure as input must be able to either support the compressed format or return an error code. In the case of printer drivers, to support the compressed format, the driver must be able to perform either one of the following tasks:

  + If the print device can process the JPEG/PNG compressed format, the printer driver should pass the compressed format through to its page description language (PDL) output.
  + If the print device cannot process the JPEG/PNG compressed format, the printer driver must first convert the compressed JPEG/PNG format into another image format that the print device can process. The printer driver can then make the image information available in the driver's PDL output.

    **Note** In the case of converting from JPEG/PNG to the bitmap format, the printer driver must not use GDI functions. For example, the driver can use the Windows Imaging Component (WIC) APIs instead to do the conversion.
* The driver must be able to handle complex clip regions for images that use the compressed format.
* For driver-defined graphics DDI functions that receive a ROP4 input argument, only 0xCCCC is used with JPEG and PNG formats.

## See also

[DrvEnablePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablepdev)

[DrvQueryFont](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvqueryfont)

[DrvRealizeBrush](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvrealizebrush)

[DrvTextOut](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvtextout)