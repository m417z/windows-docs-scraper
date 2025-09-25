# XMMatrixInverse function

## Description

Computes the inverse of a matrix.

## Parameters

### `pDeterminant` [out, optional]

Address of a vector, each of whose components receives the determinant of *M*. This parameter can be nullptr if the determinant is not desired.

### `M` [in]

Matrix to invert.

## Return value

Returns the matrix inverse of *M*. If there is no inverse (that is, if the determinant is 0),
**XMMatrixInverse** returns an infinite matrix.

## Remarks

**Note** For XNAMATH version 2.04 and earlier, the *pDeterminant* parameter isn't optional. That is, for XNAMATH version 2.04 and earlier, you can't set *pDeterminant* to a nullptr.

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Matrix Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-matrix)