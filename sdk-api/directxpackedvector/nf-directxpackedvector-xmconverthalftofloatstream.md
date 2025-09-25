# XMConvertHalfToFloatStream function

## Description

Converts a stream of half-precision floating-point values to a stream of single-precision floating-point values.

## Parameters

### `pOutputStream` [out]

Address of the first **float** value in the output stream.

### `OutputStride` [in]

Stride in bytes between the **float** values in the output stream.

### `pInputStream` [in]

Address of the first **HALF** value in the input stream.

### `InputStride` [in]

Stride in bytes between the **HALF** values in the input stream.

### `HalfCount` [in]

Number of **HALF** values to convert.

## Return value

Returns the address of the first **float** value in the output stream.

## Remarks

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Conversion Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-reference-functions-conversion)

[XMConvertHalfToFloat](https://learn.microsoft.com/windows/desktop/api/directxpackedvector/nf-directxpackedvector-xmconverthalftofloat)