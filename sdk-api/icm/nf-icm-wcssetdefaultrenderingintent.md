## Description

Sets the default rendering intent in the specified profile management scope.

## Parameters

### `scope`

The profile management scope for this operation, which can be system-wide or the current user only.

### `dwRenderingIntent`

The rendering intent. It can be set to one of the following values:

INTENT\_PERCEPTUAL

INTENT\_RELATIVE\_COLORIMETRIC

INTENT\_SATURATION

INTENT\_ABSOLUTE\_COLORIMETRIC

DWORD\_MAX

If *dwRenderingIntent* is DWORD\_MAX and *scope* is WCS\_PROFILE\_MANAGEMENT\_SCOPE\_CURRENT\_USER, the default rendering intent for the current user reverts to the system-wide default.

For more information, see [Rendering intents](https://learn.microsoft.com/windows/win32/wcs/rendering-intents).

## Return value

If this function succeeds, the return value is **TRUE**.

If this function fails, the return value is **FALSE**. For extended error information, call **GetLastError**.

## Remarks

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Windows Color System schemas and algorithms](https://learn.microsoft.com/windows/win32/wcs/windows-color-system-schemas-and-algorithms)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)