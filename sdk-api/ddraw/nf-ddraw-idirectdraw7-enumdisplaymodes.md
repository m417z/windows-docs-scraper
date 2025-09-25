# IDirectDraw7::EnumDisplayModes

## Description

Enumerates all the display modes that the hardware exposes through the DirectDraw object and that are compatible with a provided surface description.

## Parameters

### `unnamedParam1` [in]

This value consists of one or more of the following flags:

#### DDEDM_REFRESHRATES

Enumerates modes with different refresh rates. **IDirectDraw7::EnumDisplayModes** guarantees that a particular mode is enumerated only once. This flag specifies whether the refresh rate is taken into account when determining whether a mode is unique.

#### DDEDM_STANDARDVGAMODES

Enumerates Mode 13 in addition to the 320x200x8 Mode X mode.

### `unnamedParam2` [in]

Address of a [DDSURFACEDESC2](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550340(v=vs.85)) structure to be checked against available modes. If the value of this parameter is NULL, all modes are enumerated.

### `unnamedParam3` [in]

Address of an application-defined structure to be passed to each enumeration member.

### `unnamedParam4` [in]

Address of the [EnumModesCallback2](https://learn.microsoft.com/windows/desktop/api/ddraw/nc-ddraw-lpddenummodescallback2) function that the enumeration procedure calls every time a match is found.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS

## Remarks

**IDirectDraw7::EnumDisplayModes** enumerates the **dwRefreshRate** member of the [DDSURFACEDESC2](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550340(v=vs.85)) structure; the IDirectDraw::EnumDisplayModes method does not have this ability. If you use the [IDirectDraw7::SetDisplayMode](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-idirectdraw7-setdisplaymode) method to set the refresh rate of a new mode, use **IDirectDraw7::EnumDisplayModes** to enumerate the **dwRefreshRate** member.

**IDirectDraw7::EnumDisplayModes** differs from its counterparts in former interfaces in that it accepts the address of an [EnumModesCallback2](https://learn.microsoft.com/windows/desktop/api/ddraw/nc-ddraw-lpddenummodescallback2) function as a parameter, rather than an [EnumModesCallback](https://learn.microsoft.com/windows/desktop/api/ddraw/nc-ddraw-lpddenummodescallback) function.

## See also

[IDirectDraw7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdraw7)