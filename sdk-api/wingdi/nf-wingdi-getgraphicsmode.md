# GetGraphicsMode function

## Description

The **GetGraphicsMode** function retrieves the current graphics mode for the specified device context.

## Parameters

### `hdc` [in]

A handle to the device context.

## Return value

If the function succeeds, the return value is the current graphics mode. It can be one of the following values.

| Value | Meaning |
| --- | --- |
| GM_COMPATIBLE | The current graphics mode is the compatible graphics mode, a mode that is compatible with 16-bit Windows. In this graphics mode, an application cannot set or modify the world transformation for the specified device context. The compatible graphics mode is the default graphics mode. |
| GM_ADVANCED | The current graphics mode is the advanced graphics mode, a mode that allows world transformations. In this graphics mode, an application can set or modify the world transformation for the specified device context. |

Otherwise, the return value is zero.

## Remarks

An application can set the graphics mode for a device context by calling the [SetGraphicsMode](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setgraphicsmode) function.

## See also

[Coordinate Space and Transformation Functions](https://learn.microsoft.com/windows/desktop/gdi/coordinate-space-and-transformation-functions)

[Coordinate Spaces and Transformations Overview](https://learn.microsoft.com/windows/desktop/gdi/coordinate-spaces-and-transformations)

[SetGraphicsMode](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setgraphicsmode)