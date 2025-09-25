# XMVectorATan2 function

## Description

Computes the arctangent of *Y*/*X*.

## Parameters

### `Y` [in]

First vector.

### `X` [in]

Second vector.

## Return value

Returns a vector. Each component is the arctangent of the corresponding *Y* component divided by the
corresponding *X* component. Each component is in the range (-PI/2, PI/2).

`XMVectorATan2` returns the following values for the specified special input values.

| Input Value | Return Value |
| --- | --- |
| Y == 0 and X < 0 | Pi with the same sign as Y |
| Y == 0 and X > 0 | 0 with the same sign as Y |
| Y != 0 and X == 0 | Pi / 2 with the same sign as Y |
| X == -Infinity and Y is finite | Pi with the same sign as Y |
| X == +Infinity and Y is finite | 0 with the same sign as Y |
| Y == Infinity and X is finite | Pi / 2 with the same sign as Y |
| Y == Infinity and X == -Infinity | 3Pi / 4 with the same sign as Y |
| Y == Infinity and X == +Infinity | Pi / 4 with the same sign as Y |

## Remarks

This function uses a 17-degree minimax approximation.

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[Transcendental Vector Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-vector-transcendental)

[XMVectorATan](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectoratan)

[XMVectorATan2Est](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectoratan2est)

[XMVectorATanEst](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectoratanest)

[XMVectorTan](https://learn.microsoft.com/windows/desktop/api/directxmath/nf-directxmath-xmvectortan)