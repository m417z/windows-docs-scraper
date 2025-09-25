# XMVectorModAngles function

## Description

Computes the per-component angle modulo 2PI.

## Parameters

### `Angles` [in]

Vector of angle components.

## Return value

Returns a vector whose components are the corresponding components of *Angles* modulo 2PI.

## Remarks

The following pseudocode demonstrates the operation of the function:

```
XMVECTOR result;

result.x = Angles.x - XM_2PI * round( Angles.x / XM_2PI );
result.y = Angles.y - XM_2PI * round( Angles.y / XM_2PI );
result.z = Angles.z - XM_2PI * round( Angles.z / XM_2PI );
result.w = Angles.w - XM_2PI * round( Angles.w / XM_2PI );

return result;
```

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[Vector Arithmetic Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector-arithmetic)