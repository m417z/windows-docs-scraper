# EngCreateWnd function

## Description

The **EngCreateWnd** function creates a [WNDOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-wndobj) structure for the window referenced by *hwnd*.

## Parameters

### `pso`

Pointer to a [SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj) structure identifying a device surface.

### `hwnd`

Handle to the window created by an application's call to the Win32 **CreateWindow** or equivalent function.

### `pfn`

######

### `fl`

Is a bitmask that specifies the type of changes GDI should track and report to the driver. This value must be consistent through all [WNDOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-wndobj) requests made by the driver. This parameter can be one or more of the following bitfield values:

| Flag | Meaning |
| --- | --- |
| WO_DRAW_NOTIFY | GDI should provide the driver with WOC_DRAWN notifications. |
| WO_RGN_CLIENT | GDI should track changes in the client region of the window object, and notify the driver when the window's visible client region changes. The region enumerated in the callback function is the new visible client area of the window. |
| WO_RGN_CLIENT_DELTA | GDI should track changes in the delta client region of the window object, and notify the driver when the window's visible region changes. The region enumerated in the callback function is a nonempty delta area that is in the new region but not in the old region. The delta region is valid during the callback only. |
| WO_RGN_DESKTOP_COORD | GDI creates a WNDOBJ structure with desktop coordinates when the system is running multiple monitors.<br><br>GDI ignores this flag and creates a WNDOBJ structure with device coordinates when the system is running a single monitor. |
| WO_RGN_SURFACE | GDI should track changes in the surface region of the window object, and notify the driver when the surface region changes. The surface region is the display surface area excluding all visible client regions of the windows being tracked by the driver. |
| WO_RGN_SURFACE_DELTA | GDI should track changes in the delta surface region of the window object, and notify the driver when the surface region changes. The region enumerated in the callback function is a nonempty delta area that is in the new surface region but not in the old surface region. The delta surface region is valid during the callback only. |
| WO_RGN_UPDATE_ALL | GDI should notify the driver for all windows it tracks when any of its windows' visible regions change. This flag must be used in conjunction with the WO_RGN_CLIENT flag. |
| WO_RGN_WINDOW | GDI should track changes in the entire region of the window object (which includes the client region of the window), and notify the driver when the window's region changes. |
| WO_SPRITE_NOTIFY | GDI should notify the driver for all windows it tracks when any of its windows' visible regions are overlapped or no longer overlapped by sprites. |

### `iPixelFormat`

Specifies the pixel format associated with the window object. The pixel format of a window object is fixed. This parameter can be zero if there is no associated pixel format.

## Return value

The return value is a pointer to a [WNDOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-wndobj) structure if the function is successful. Otherwise, the return value is −1 if the same window is being tracked by the driver, or zero if the driver is not tracking the same window.

## Remarks

Because creating a window object involves locking window resources, **EngCreateWnd** should be called only in the context of the WNDOBJ_SETUP escape in [DrvEscape](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvescape).

**EngCreateWnd** supports window tracking by multiple drivers, where each driver is identified by a unique [WNDOBJCHANGEPROC](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff570601(v=vs.85)) function pointer identified by *pfn*. For example, a live video driver can track changes to live video windows while an OpenGL driver is tracking changes to OpenGL windows.

GDI will call **WNDOBJCHANGEPROC** with the most recent window state if a new [WNDOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-wndobj) is created by *DrvEscape*. GDI will also notify **WNDOBJCHANGEPROC** when a window described by a WNDOBJ structure is destroyed.

The WOC_SPRITE_OVERLAP and WOC_SPRITE_NO_OVERLAP notifications passed to **WNDOBJCHANGEPROC** allow the driver to be synchronously informed when a sprite is on top of its window, and take the appropriate action. The driver receives these notifications even if all sprites have been torn down by the ECS_TEARDOWN flag of [EngControlSprites](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engcontrolsprites).

## See also

[DrvEscape](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvescape)

[WNDOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-wndobj)

[WNDOBJCHANGEPROC](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff570601(v=vs.85))