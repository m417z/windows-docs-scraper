# GetLogColorSpaceA function

## Description

The **GetLogColorSpace** function retrieves the [color space](https://learn.microsoft.com/windows/win32/wcs/c#color-space) definition identified by a specified handle.

## Parameters

### `hColorSpace`

Specifies the handle to a color space.

### `lpBuffer`

Points to a buffer to receive the [LOGCOLORSPACE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logcolorspacea) structure.

### `nSize`

Specifies the maximum size of the buffer.

## Return value

If this function succeeds, the return value is TRUE.

If this function fails, the return value is **FALSE**.

## Remarks

**Windows 95/98/Me:** **GetLogColorSpaceW** is supported by the Microsoft Layer for Unicode. To use this, you must add certain files to your application, as outlined in [Microsoft Layer for Unicode on Windows 95/98/Me Systems](https://msdn.microsoft.com/library?url=/library/mslu/winprog/microsoft_layer_for_unicode_on_windows_95_98_me_systems.asp).

> [!NOTE]
> The wingdi.h header defines GetLogColorSpace as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)