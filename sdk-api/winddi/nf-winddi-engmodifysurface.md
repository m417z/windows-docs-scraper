# EngModifySurface function

## Description

The **EngModifySurface** function notifies GDI about the attributes of a surface that was created by the driver.

## Parameters

### `hsurf`

Handle to the surface to be modified. This parameter is the surface handle returned by [EngCreateDeviceBitmap](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreatedevicebitmap) or [EngCreateDeviceSurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcreatedevicesurface), or from the **hsurf** member of the [SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj) structure.

### `hdev`

Handle to the device with which the surface is to be associated. This is the handle that GDI passed to [DrvCompletePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvcompletepdev).

### `flHooks`

Is a set of flags that control the functions the driver can hook whenever GDI drawing occurs on the specified surface. This can be a bitwise OR of any of the HOOK_*Xxx* values listed on the [EngAssociateSurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engassociatesurface) reference page.

### `flSurface`

Is a set of flags that describe the surface's attributes. Currently, the driver should set this to MS_NOTSYSTEMMEMORY when the surface is located in video memory.

### `dhsurf`

Identifies the surface to the driver. The driver can set this to anything; GDI sets the **dhsurf** member of the resulting surface's [SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj) structure to this value if the function is successful.

### `pvScan0`

Pointer to the virtual address of the start of the bitmap.

### `lDelta`

Is the virtual address stride of the bitmap; that is, the number of bytes between the beginning of one bitmap row and the next.

### `pvReserved`

Is reserved and must always be set to **NULL**.

## Return value

**EngModifySurface** returns **TRUE** upon success; otherwise it returns **FALSE**.

## Remarks

**EngModifySurface** allows the driver to modify a [device-managed surface](https://learn.microsoft.com/windows-hardware/drivers/) and inform GDI of this surface's attributes. This allows drivers to convert the destination surface from being opaque to nonopaque, thus allowing GDI to draw on the surface.

The DIB engine uses *pvScan0* and *lDelta* to draw directly to the surface. When these parameters are **NULL**, the surface is opaque to GDI, and GDI will revert to calling [DrvCopyBits](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvcopybits) for drawing operations not hooked by the driver.

After [DrvEnableSurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablesurface) returns a handle to a primary surface, do not call **EngModifySurface** on that handle. Doing so can cause a bug check in certain circumstances. For more information, see [Microsoft Knowledge Base article 330248](https://support.microsoft.com/?kbid&ID=330248).

## See also

[DrvCopyBits](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvcopybits)

[EngAssociateSurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engassociatesurface)