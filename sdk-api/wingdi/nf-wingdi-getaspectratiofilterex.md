# GetAspectRatioFilterEx function

## Description

The **GetAspectRatioFilterEx** function retrieves the setting for the current aspect-ratio filter.

## Parameters

### `hdc` [in]

Handle to a device context.

### `lpsize` [out]

Pointer to a [SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size) structure that receives the current aspect-ratio filter.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

The aspect ratio is the ratio formed by the width and height of a pixel on a specified device.

The system provides a special filter, the aspect-ratio filter, to select fonts that were designed for a particular device. An application can specify that the system should only retrieve fonts matching the specified aspect ratio by calling the [SetMapperFlags](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setmapperflags) function.

## See also

[Font and Text Functions](https://learn.microsoft.com/windows/desktop/gdi/font-and-text-functions)

[Fonts and Text Overview](https://learn.microsoft.com/windows/desktop/gdi/fonts-and-text)

[SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size)

[SetMapperFlags](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setmapperflags)