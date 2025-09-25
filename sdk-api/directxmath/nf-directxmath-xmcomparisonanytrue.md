# XMComparisonAnyTrue function

## Description

Tests the comparison value to determine if any of the compared components are true.

## Parameters

### `CR` [in]

Comparison value to test. The comparison value is typically retrieved using a recording version of a DirectXMath
function such as [XMVector4EqualR](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvector4equalr). The names of the recording functions
end with an "R".

## Return value

Returns true if any of the compared components are true.

## Remarks

The following code snippet highlights how this function might be used:

```
uint32_t comparisonValue = XMVector4EqualR( V1, V2 );
if( XMComparisonAnyTrue( comparisonValue ) )
{
	DoStuff();
}
```

The `DoStuff` function will be called only if any of the four components of *V1* and *V2* are
equal (any compared components are true).

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Utility Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-utilities)

[XMComparisonAllFalse](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmcomparisonallfalse)

[XMComparisonAllInBounds](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmcomparisonallinbounds)

[XMComparisonAllTrue](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmcomparisonalltrue)

[XMComparisonAnyFalse](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmcomparisonanyfalse)

[XMComparisonAnyOutOfBounds](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmcomparisonanyoutofbounds)

[XMComparisonMixed](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmcomparisonmixed)