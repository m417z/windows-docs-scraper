# EngAssociateSurface function

## Description

The **EngAssociateSurface** function marks a given surface as belonging to a specified device.

## Parameters

### `hsurf`

Handle to the surface or bitmap to be associated with *hdev*. This handle was returned by [EngCreateBitmap](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreatebitmap) or [EngCreateDeviceBitmap](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreatedevicebitmap).

### `hdev`

Handle to the device with which the surface is to be associated. This is the GDI-created handle that was passed to the driver's [DrvCompletePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvcompletepdev) function.

### `flHooks`

Specifies the functions that the driver can hook from GDI. The driver must implement the corresponding function for every bit that it sets in *flHooks*. This member is a bitwise OR of any of the following values:

| Flag | Function to be hooked |
| --- | --- |
| HOOK_ALPHABLEND | [DrvAlphaBlend](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvalphablend) |
| HOOK_BITBLT | [DrvBitBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvbitblt) |
| HOOK_COPYBITS | [DrvCopyBits](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvcopybits) |
| HOOK_FILLPATH | [DrvFillPath](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvfillpath) |
| HOOK_GRADIENTFILL | [DrvGradientFill](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvgradientfill) |
| HOOK_LINETO | [DrvLineTo](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvlineto) |
| HOOK_MOVEPANNING | Obsolete |
| HOOK_PAINT | Obsolete |
| HOOK_PLGBLT | [DrvPlgBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvplgblt) |
| HOOK_STRETCHBLT | [DrvStretchBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvstretchblt) |
| HOOK_STRETCHBLTROP | [DrvStretchBltROP](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvstretchbltrop) |
| HOOK_STROKEANDFILLPATH | [DrvStrokeAndFillPath](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvstrokeandfillpath) |
| HOOK_STROKEPATH | [DrvStrokePath](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvstrokepath) |
| HOOK_SYNCHRONIZE | [DrvSynchronize](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvsynchronize) or [DrvSynchronizeSurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvsynchronizesurface) (either or both) |
| HOOK_SYNCHRONIZEACCESS | Obsolete |
| HOOK_TEXTOUT | [DrvTextOut](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvtextout) |
| HOOK_TRANSPARENTBLT | [DrvTransparentBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvtransparentblt) |

## Return value

The return value is **TRUE** if the function is successful. Otherwise, the driver should send the information to the GDI function it is implementing, and return GDI's return value.

## Remarks

**EngAssociateSurface** can be used by printer drivers to implement "rules" or device fonts, or by display drivers to make use of special blt hardware.

If the surface identified by *hsurf* is a standard format bitmap, the driver can specify which output functions to the surface it will handle by setting bits in *flHooks*. Setting bits in *flHooks* causes particular output functions to be sent to the driver instead. This is referred to as hooking. If the driver does not hook a call, GDI will automatically manage the operation when a standard format bitmap is being drawn on.

When the surface is associated, it assumes the default palette and style steps of the [PDEV](https://learn.microsoft.com/windows-hardware/drivers/). A surface must be associated before it is returned by [DrvEnableSurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablesurface).

By default, when a driver supports device bitmaps by implementing [DrvCreateDeviceBitmap](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvcreatedevicebitmap)/[DrvDeleteDeviceBitmap](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvdeletedevicebitmap), GDI does not automatically synchronize drawing calls to the device bitmap and to the primary surface. For example, GDI can call the driver's [DrvBitBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvbitblt) function to draw to a device bitmap, while another thread is drawing to the primary surface by executing the driver's implementation of [DrvTextOut](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvtextout). The driver can even be called to draw to multiple device bitmaps at the same time.

After [DrvEnableSurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablesurface) returns a handle to a primary surface, do not call **EngAssociateSurface** on that handle. Doing so can cause a bug check in certain circumstances. For more information, see [Microsoft Knowledge Base article 330248](https://support.microsoft.com/?kbid&ID=330248).

## See also

[DrvBitBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvbitblt)

[DrvCompletePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvcompletepdev)

[DrvCopyBits](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvcopybits)

[DrvCreateDeviceBitmap](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvcreatedevicebitmap)

[DrvDeleteDeviceBitmap](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvdeletedevicebitmap)

[DrvEnableSurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablesurface)

[DrvFillPath](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvfillpath)

[DrvLineTo](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvlineto)

[DrvStretchBlt](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvstretchblt)

[DrvStrokeAndFillPath](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvstrokeandfillpath)

[DrvStrokePath](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvstrokepath)

[DrvSynchronize](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvsynchronize)

[DrvSynchronizeSurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvsynchronizesurface)

[DrvTextOut](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvtextout)

[EngModifySurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engmodifysurface)