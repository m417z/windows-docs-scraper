# _D3DDDIARG_SETCLIPPLANE structure

## Description

The D3DDDIARG_SETCLIPPLANE structure describes a clip plane.

## Members

### `Index` [in]

The index of the clipping plane for which the plane equation coefficients are set.

### `Plane` [in]

A four-element array of the coefficients A, B, C, and D, in that order, in the general plane equation for the clipping plane.

## Remarks

The general plane equation in standard form is A*x* + B*y* + C*z* + D*w* = 0. A point with homogeneous coordinates (*x*, *y*, *z*, *w*) is visible in the half-space of this plane if A*x* + B*y* + C*z* + D*w* >= 0. Points that exist on or behind the clipping plane are clipped from the scene. That is, points for which A*x* + B*y* + C*z* + D*w* < 0 are clipped.

## See also

[SetClipPlane](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setclipplane)