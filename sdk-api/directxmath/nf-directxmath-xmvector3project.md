# XMVector3Project function

## Description

Project a 3D vector from object space into screen space.

## Parameters

### `V` [in]

3D vector in object space that will be projected into screen space.

### `ViewportX` [in]

Pixel coordinate of the upper-left corner of the viewport. Unless you want to render to a subset of the surface, this parameter can be set to 0.

### `ViewportY` [in]

Pixel coordinate of the upper-left corner of the viewport on the render-target surface. Unless you want to render to a subset of the surface, this parameter can be set to 0.

### `ViewportWidth` [in]

Width dimension of the clip volume, in pixels. Unless you are rendering only to a subset of the surface, this parameter should be set to the width dimension of the render-target surface.

### `ViewportHeight` [in]

Height dimension of the clip volume, in pixels. Unless you are rendering only to a subset of the surface, this parameter should be set to the height dimension of the render-target surface.

### `ViewportMinZ` [in]

Together with *ViewportMaxZ*, value describing the range of depth values into which a scene is to be rendered, the minimum and maximum values of the clip volume. Most applications set this value to 0.0f. Clipping is performed after applying the projection matrix.

### `ViewportMaxZ` [in]

Together with *MinZ*, value describing the range of depth values into which a scene is to be rendered, the minimum and maximum values of the clip volume. Most applications set this value to 1.0f. Clipping is performed after applying the projection matrix.

### `Projection` [in]

Projection matrix.

### `View` [in]

View matrix.

### `World` [in]

World matrix.

## Return value

Returns a vector in screen space.

## Remarks

The *ViewportX*, *ViewportY*, *ViewportWidth*, and *ViewportHeight* parameters describe the position and dimensions of the viewport on the render-target surface. Usually, applications render to the entire target surface; when rendering on a 640*480 surface, these parameters should be 0, 0, 640, and 480, respectively. The *ViewportMinZ* and *ViewportMaxZ* are typically set to 0.0f and 1.0f but can be set to other values to achieve specific effects.

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library 3D Vector Transformation Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector3-transformation)

[XMVector3ProjectStream](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvector3projectstream)