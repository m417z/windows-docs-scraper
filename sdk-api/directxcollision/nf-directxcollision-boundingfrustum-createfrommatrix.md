# BoundingFrustum::CreateFromMatrix

## Description

Creates a [BoundingFrustum](https://learn.microsoft.com/windows/win32/api/directxcollision/ns-directxcollision-boundingfrustum) from the specified perspective projection matrix.

## Parameters

### `Out` [out, ref]

The new [BoundingFrustum](https://learn.microsoft.com/windows/win32/api/directxcollision/ns-directxcollision-boundingfrustum).

### `Projection` [in]

The projection matrix to create the [BoundingFrustum](https://learn.microsoft.com/windows/win32/api/directxcollision/ns-directxcollision-boundingfrustum) from.

### `rhcoords` [in]

If set to false (the default), this indicates the projection matrix is in left-handed coordinates. Set it to true if using right-handed coordinates.

> This parameter was added in DirectXMath 3.16.

## Return value

This method does not return a value.

## Remarks

This method is not suitable for use with orthographic projection matricies.

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[BoundingFrustum](https://learn.microsoft.com/windows/win32/api/directxcollision/ns-directxcollision-boundingfrustum)

[Methods](https://msdn.microsoft.com/85A76263-92C4-4AF1-BFDE-C68A30CD5583)

**Reference**