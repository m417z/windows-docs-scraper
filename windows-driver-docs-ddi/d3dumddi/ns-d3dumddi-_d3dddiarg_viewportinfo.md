# _D3DDDIARG_VIEWPORTINFO structure

## Description

The D3DDDIARG_VIEWPORTINFO structure describes the location and size of a view-clipping rectangle.

## Members

### `X` [in]

The x coordinate, in screen coordinates, for the upper-left corner of the view-clipping rectangle.

### `Y` [in]

The y coordinate, in screen coordinates, for the upper-left corner of the view-clipping rectangle.

### `Width` [in]

The width, in screen coordinates, of the view-clipping rectangle where the application is rendering.

### `Height` [in]

The height, in screen coordinates, of the view-clipping rectangle where the application is rendering.

## Remarks

The user-mode display driver's [SetViewport](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setviewport) function should update the viewport portion of its internal rendering context with the location and size values that are specified in the D3DDDIARG_VIEWPORTINFO structure. The driver can use this information to perform guard band clipping.

## See also

[SetViewport](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setviewport)