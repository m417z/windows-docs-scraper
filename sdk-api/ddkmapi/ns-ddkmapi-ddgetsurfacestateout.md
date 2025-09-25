# DDGETSURFACESTATEOUT structure

## Description

The DDGETSURFACESTATEOUT structure contains the capabilities and status of the specified surface.

## Members

### `ddRVal`

Specifies the location in which Microsoft DirectDraw writes the return value of the [DxApi](https://learn.microsoft.com/previous-versions/windows/drivers/display/nf-dxapi-dxapi) function for [DD_DXAPI_GET_SURFACE_STATE](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550673(v=vs.85)) operations. A return code of DD_OK indicates success.

### `dwStateCaps`

Contains the DirectDrawSurface's capabilities of the device. One or more of the following:

| Flag | Meaning |
| --- | --- |
| DDSTATE_BOB | The device is capable of performing bob mode. |
| DDSTATE_WEAVE | The device is capable of performing weave mode. |

### `dwStateStatus`

Contains the status of the selected DirectDrawSurface. One or more of the following:

| Flag | Meaning |
| --- | --- |
| DDSTATE_BOB | Bob mode is being used on this surface. |
| DDSTATE_EXPLICITLY_SET | This state is due to a previous [DD_DXAPI_SET_SURFACE_STATE](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff551504(v=vs.85)) call. |
| DDSTATE_SKIPEVENFIELDS | Stop bob or weave mode and skip every other field instead. |
| DDSTATE_SOFTWARE_AUTOFLIP | Software (as opposed to hardware) autoflipping is being used. |
| DDSTATE_WEAVE | Weave mode is being used on this surface. |

## See also

[DD_DXAPI_GET_SURFACE_STATE](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550673(v=vs.85))

[DxApi](https://learn.microsoft.com/previous-versions/windows/drivers/display/nf-dxapi-dxapi)