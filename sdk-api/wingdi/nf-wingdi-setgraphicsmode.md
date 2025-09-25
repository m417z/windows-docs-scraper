# SetGraphicsMode function

## Description

The **SetGraphicsMode** function sets the graphics mode for the specified device context.

## Parameters

### `hdc` [in]

A handle to the device context.

### `iMode` [in]

The graphics mode. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **GM_COMPATIBLE** | Sets the graphics mode that is compatible with 16-bit Windows. This is the default mode. If this value is specified, the application can only modify the world-to-device transform by calling functions that set window and viewport extents and origins, but not by using [SetWorldTransform](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setworldtransform) or [ModifyWorldTransform](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-modifyworldtransform); calls to those functions will fail. Examples of functions that set window and viewport extents and origins are [SetViewportExtEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setviewportextex) and [SetWindowExtEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setwindowextex). |
| **GM_ADVANCED** | Sets the advanced graphics mode that allows world transformations. This value must be specified if the application will set or modify the world transformation for the specified device context. In this mode all graphics, including text output, fully conform to the world-to-device transformation specified in the device context. |

## Return value

If the function succeeds, the return value is the old graphics mode.

If the function fails, the return value is zero.

## Remarks

There are three areas in which graphics output differs according to the graphics mode:

1. Text Output: In the GM_COMPATIBLE mode, TrueType (or vector font) text output behaves much the same way as raster font text output with respect to the world-to-device transformations in the DC. The TrueType text is always written from left to right and right side up, even if the rest of the graphics will be flipped on the x or y axis. Only the height of the TrueType (or vector font) text is scaled. The only way to write text that is not horizontal in the GM_COMPATIBLE mode is to specify nonzero escapement and orientation for the logical font selected in this device context.

   In the GM_ADVANCED mode, TrueType (or vector font) text output fully conforms to the world-to-device transformation in the device context. The raster fonts only have very limited transformation capabilities (stretching by some integer factors). Graphics device interface (GDI) tries to produce the best output it can with raster fonts for nontrivial transformations.
2. Rectangle Exclusion: If the default GM_COMPATIBLE graphics mode is set, the system excludes bottom and rightmost edges when it draws rectangles.

   The GM_ADVANCED graphics mode is required if applications want to draw rectangles that are lower-right inclusive.
3. Arc Drawing: If the default GM_COMPATIBLE graphics mode is set, GDI draws arcs using the current arc direction in the device space. With this convention, arcs do not respect page-to-device transforms that require a flip along the x or y axis.

   If the GM_ADVANCED graphics mode is set, GDI always draws arcs in the counterclockwise direction in logical space. This is equivalent to the statement that, in the GM_ADVANCED graphics mode, both arc control points and arcs themselves fully respect the device context's world-to-device transformation.

#### Examples

For an example, see [Using Coordinate Spaces and Transformations](https://learn.microsoft.com/windows/desktop/gdi/using-coordinate-spaces-and-transformations).

## See also

[Coordinate Space and Transformation Functions](https://learn.microsoft.com/windows/desktop/gdi/coordinate-space-and-transformation-functions)

[Coordinate Spaces and Transformations Overview](https://learn.microsoft.com/windows/desktop/gdi/coordinate-spaces-and-transformations)

[CreateDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdca)

[GetArcDirection](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getarcdirection)

[GetDC](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getdc)

[GetGraphicsMode](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getgraphicsmode)

[ModifyWorldTransform](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-modifyworldtransform)

[SetArcDirection](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setarcdirection)

**SetViewportExtEx**

[SetViewportExtent](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setviewportextex)

**SetWindowExtEx**

[SetWindowExtent](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setwindowextex)

[SetWorldTransform](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setworldtransform)