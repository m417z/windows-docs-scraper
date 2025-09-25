# DD_SURFACE_LOCAL structure

## Description

The DD_SURFACE_LOCAL structure contains surface-related data that is unique to an individual surface object.

## Members

### `lpGbl`

Points to the [DD_SURFACE_GLOBAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_surface_global) structure containing surface data that is shared globally with multiple surfaces.

### `dwFlags`

Specifies a set of surface flags. This member is a bitwise OR of any of the following values:

| Flag | Meaning |
| --- | --- |
| DDRAWISURF_BACKBUFFER | The surface was originally a back buffer. |
| DDRAWISURF_DRIVERMANAGED | The surface is a driver managed texture used with Microsoft Direct3D. |
| DDRAWISURF_FRONTBUFFER | The surface was originally a front buffer. |
| DDRAWISURF_HASCKEYSRCBLT | The surface has source color key overlay data in the **ddckCKSrcBlt** member. |
| DDRAWISURF_HASOVERLAYDATA | The surface has overlay data. |
| DDRAWISURF_HASPIXELFORMAT | The surface has pixel format data. |
| DDRAWISURF_INVALID | The surface has been invalidated by a mode setting operation. |

### `ddsCaps`

Specifies a [DDSCAPS](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550286(v=vs.85)) structure that describes the capabilities of the surface.

### `dwReserved1`

Reserved for use by the display driver.

### `ddckCKSrcOverlay`

Specifies a DDCOLORKEY structure (defined in the Microsoft DirectDraw SDK documentation) that contains the color key information for source overlay use.

### `ddckCKSrcBlt`

Specifies a DDCOLORKEY structure that describes the color key for source color key overlays.

### `ddckCKDestOverlay`

Specifies a DDCOLORKEY structure that contains the color key information for destination overlay use.

### `ddckCKDestBlt`

Specifies a DDCOLORKEY structure that describes the color key for destination color key overlays.

### `lpSurfMore`

Points to a [DD_SURFACE_MORE](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_surface_more) structure that contains additional local surface data.

### `lpAttachList`

Points to a [DD_ATTACHLIST](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_attachlist) structure that contains the list of surfaces to which this surface attached.

### `lpAttachListFrom`

Points to a DD_ATTACHLIST structure that contains the list of surfaces attached to this surface.

### `rcOverlaySrc`

Reserved for system use and should be ignored by the driver.