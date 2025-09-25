# _D3DHAL_DP2SETCLIPPLANE structure

## Description

The D3DHAL_SETCLIPPLANE structure allows user defined clip planes to be used in world space.

## Members

### `dwIndex`

Specifies the index of the clipping plane for which the plane equation coefficients will be set.

### `plane`

Specifies a four-element array of the coefficients A, B, C, and D, in that order, in the general plane equation for the clipping plane.

## Remarks

The general plane equation in standard form is A*x* + B*y* + C*z* + D*w* = 0. A point with homogeneous coordinates (*x*, *y*, *z*, *w*) is visible in the half-space of this plane if A*x* + B*y* + C*z* + D*w* >= 0. Points that exist on or behind the clipping plane are clipped from the scene. That is, points for which Ax + By + Cz + Dw <= 0 are clipped.