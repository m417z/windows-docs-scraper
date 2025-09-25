# BoundingOrientedBox::CreateFromPoints

## Description

Creates a [BoundingOrientedBox](https://learn.microsoft.com/windows/win32/api/directxcollision/ns-directxcollision-boundingorientedbox) from a collection of points.

## Parameters

### `Out` [out, ref]

The new [BoundingOrientedBox](https://learn.microsoft.com/windows/win32/api/directxcollision/ns-directxcollision-boundingorientedbox) containing the specified points.

### `Count` [in]

The number of points in the buffer in *pPoints*.

### `pPoints`

A buffer containing points to create the [BoundingOrientedBox](https://learn.microsoft.com/windows/win32/api/directxcollision/ns-directxcollision-boundingorientedbox) from.

### `Stride` [in]

The stride of the buffer.

## Remarks

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[BoundingOrientedBox](https://learn.microsoft.com/windows/win32/api/directxcollision/ns-directxcollision-boundingorientedbox)

[Methods](https://msdn.microsoft.com/98aa4c21-2dac-4e7a-95ef-ca87fb5e5082)

**Reference**