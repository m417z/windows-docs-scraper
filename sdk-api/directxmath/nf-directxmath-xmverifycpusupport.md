# XMVerifyCPUSupport function

## Description

Indicates if the DirectXMath Library supports the current platform.

## Return value

Returns true if the DirectXMath Library supports a given platform; false if it does not.

## Remarks

This is a run-time check of processor support and should be called at startup of the program before any DirectXMath
functions or types are used.

On Windows, this function is implemented using
[IsProcessorFeaturePresent](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-isprocessorfeaturepresent).

Therefore, when executed on windows, `XMVerifyCPUSupport` shares platform support requirements of
`IsProcessorFeaturePresent`.

**Note** To avoid a hard dependency on windows.h, if *IsProcessorFeaturePresent* is not defined this function always returns
`false`. Be sure to include "windows.h" before "directxmath.h" in any module where you are calling this function.

### Platform Requirements

Microsoft Visual Studio 2010 or Microsoft Visual Studio 2012 with the Windows SDK for Windows 8. Supported for Win32 desktop apps, Windows Store apps, and Windows Phone 8 apps.

## See also

[DirectXMath Library Utility Functions](https://learn.microsoft.com/windows/desktop/dxmath/ovw-xnamath-utilities)