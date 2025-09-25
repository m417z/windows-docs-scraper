# BoundingBox::Contains(const BoundingFrustum &)

## Description

Tests whether the [BoundingBox](https://learn.microsoft.com/windows/win32/api/directxcollision/ns-directxcollision-boundingbox) contains the specified [BoundingFrustum](https://learn.microsoft.com/windows/win32/api/directxcollision/ns-directxcollision-boundingfrustum).

## Parameters

### `fr` [in, ref]

The [BoundingFrustum](https://learn.microsoft.com/windows/win32/api/directxcollision/ns-directxcollision-boundingfrustum) to test against.

## Return value

A [ContainmentType](https://learn.microsoft.com/windows/win32/api/directxcollision/ne-directxcollision-containmenttype) value indicating whether the [BoundingFrustum](https://learn.microsoft.com/windows/win32/api/directxcollision/ns-directxcollision-boundingfrustum) is contained in the [BoundingBox](https://learn.microsoft.com/windows/win32/api/directxcollision/ns-directxcollision-boundingbox).

## Remarks

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[BoundingBox](https://learn.microsoft.com/windows/win32/api/directxcollision/ns-directxcollision-boundingbox)

[Contains](https://msdn.microsoft.com/876c7764-9378-48e5-812c-3646930900c5)

**Reference**