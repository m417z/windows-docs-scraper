# glFeedbackBuffer function

The **glFeedbackBuffer** function controls feedback mode.

## Parameters

*size*

The maximum number of values that can be written into *buffer*.

*type*

A symbolic constant that describes the information that will be returned for each vertex. The following symbolic constants are accepted: GL\_2D, GL\_3D, GL\_3D\_COLOR, GL\_3D\_COLOR\_TEXTURE, and GL\_4D\_COLOR\_TEXTURE.

*buffer*

Returns the feedback data.

## Return value

This function does not return a value.

## Error codes

The following error codes can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_ENUM** | *type* was not an accepted value.<br> |
| **GL\_INVALID\_ENUM** | *size* was negative.<br> |
| **GL\_INVALID\_OPERATION** | **glFeedbackBuffer** was called while the render mode was GL\_FEEDBACK, or [**glRenderMode**](https://learn.microsoft.com/windows/win32/opengl/glrendermode) was called with argument GL\_FEEDBACK before **glFeedbackBuffer** was called at least once.<br> |
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

The **glFeedbackBuffer** function controls feedback. Feedback, like selection, is an OpenGL mode. The mode is selected by calling [**glRenderMode**](https://learn.microsoft.com/windows/win32/opengl/glrendermode) with GL\_FEEDBACK. When OpenGL is in feedback mode, no pixels are produced by rasterization. Instead, information about primitives that would have been rasterized is fed back to the application using OpenGL.

The **glFeedbackBuffer** function has three arguments:

- *buffer* is a pointer to an array of floating-point values into which feedback information is placed.
- *size* indicates the size of the array.
- *type* is a symbolic constant describing the information that is fed back for each vertex.

You must issue **glFeedbackBuffer** before feedback mode is enabled (by calling **glRenderMode** with argument GL\_FEEDBACK). Setting GL\_FEEDBACK without establishing the feedback buffer, or calling **glFeedbackBuffer** while OpenGL is in feedback mode, is an error.

Take OpenGL out of feedback mode by calling [**glRenderMode**](https://learn.microsoft.com/windows/win32/opengl/glrendermode) with a parameter value other than GL\_FEEDBACK. When you do this while OpenGL is in feedback mode, **glRenderMode** returns the number of entries placed in the feedback array. The returned value never exceeds *size*. If the feedback data required more room than was available in *buffer*, **glRenderMode** returns a negative value.

While in feedback mode, each primitive that would be rasterized generates a block of values that gets copied into the feedback array. If doing so would cause the number of entries to exceed the maximum, **glFeedbackBuffer** partially writes the block so as to fill the array (if there is any room left at all), and sets an overflow flag. Each block begins with a code indicating the primitive type, followed by values that describe the primitive's vertices and associated data. The **glFeedbackBuffer** function also writes entries for bitmaps and pixel rectangles. Feedback occurs after polygon culling and [**glPolygonMode**](https://learn.microsoft.com/windows/win32/opengl/glpolygonmode) interpretation of polygons has taken place, so polygons that are culled are not returned in the feedback buffer. It can also occur after polygons with more than three edges are broken up into triangles, if the OpenGL implementation renders polygons by performing this decomposition.

You can insert a marker into the feedback buffer with [**glPassThrough**](https://learn.microsoft.com/windows/win32/opengl/glpassthrough).

The following is the grammar for the blocks of values written into the feedback buffer. Each primitive is indicated with a unique identifying value followed by some number of vertices. Polygon entries include an integer value indicating how many vertices follow. A vertex is fed back as some number of floating-point values, as determined by *type*. Colors are fed back as four values in RGBA mode and one value in color-index mode.

feedbackList < feedbackItem feedbackList \| feedbackItem

feedbackItem < point \| lineSegment \| polygon \| bitmap \| pixelRectangle \| passThru

point < GL\_POINT\_TOKEN vertex

lineSegment < GL\_LINE\_TOKEN vertex vertex \| GL\_LINE\_RESET\_TOKEN vertex vertex

polygon < GL\_POLYGON\_TOKEN n polySpec

polySpec < polySpec vertex \| vertex vertex vertex

bitmap < GL\_BITMAP\_TOKEN vertex

pixelRectangle < GL\_DRAW\_PIXEL\_TOKEN vertex \| GL\_COPY\_PIXEL\_TOKEN vertex

passThru < GL\_PASS\_THROUGH\_TOKEN value

vertex < 2d \| 3d \| 3dColor \| 3dColorTexture \| 4dColorTexture

2d < value value

3d < value value value

3dColor < value value value color

3dColorTexture < value value value color tex

4dColorTexture < value value value value color tex

color < rgba \| index

rgba < value value value value

index < value

tex < value value value value

The *value* parameter is a floating-point number, and *n* is a floating-point integer giving the number of vertices in the polygon. The following are symbolic floating-point constants: GL\_POINT\_TOKEN, GL\_LINE\_TOKEN, GL\_LINE\_RESET\_TOKEN, GL\_POLYGON\_TOKEN, GL\_BITMAP\_TOKEN, GL\_DRAW\_PIXEL\_TOKEN, GL\_COPY\_PIXEL\_TOKEN, and GL\_PASS\_THROUGH\_TOKEN. GL\_LINE\_RESET\_TOKEN is returned whenever the line stipple pattern is reset. The data returned as a vertex depends on the feedback *type*.

The following table gives the correspondence between *type* and the number of values per vertex; *k* is 1 in color-index mode and 4 in RGBA mode.

| Type | Coordinates | Color | Texture | Total number of values |
|------------------------|--------------------|-------|---------|------------------------|
| GL\_2D | *x*, *y* | | | 2 |
| GL\_3D | *x*, *y*, *z* | | | 3 |
| GL\_3D\_COLOR | *x*, *y*, *z* | *k* | | 3 + *k* |
| GL\_3D\_COLOR\_TEXTURE | *x*, *y*, *z*, | *k* | 4 | 7 + *k* |
| GL\_4D\_COLOR\_TEXTURE | *x*, *y*, *z*, *w* | *k* | 4 | 8 + *k* |

Feedback vertex coordinates are in window coordinates, except *w*, which is in clip coordinates. Feedback colors are lighted, if lighting is enabled. Feedback texture coordinates are generated, if texture coordinate generation is enabled. They are always transformed by the texture matrix.

The **glFeedbackBuffer** function, when used in a display list, is not compiled into the display list but rather is executed immediately.

The following function retrieves information related to **glFeedbackBuffer**:

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_RENDER\_MODE

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Gl.h |
| Library<br> | Opengl32.lib |
| DLL<br> | Opengl32.dll |

## See also

[**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin)

[**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend)

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv)

[**glLineStipple**](https://learn.microsoft.com/windows/win32/opengl/gllinestipple)

[**glPassThrough**](https://learn.microsoft.com/windows/win32/opengl/glpassthrough)

[**glPolygonMode**](https://learn.microsoft.com/windows/win32/opengl/glpolygonmode)

[**glRenderMode**](https://learn.microsoft.com/windows/win32/opengl/glrendermode)

[**glSelectBuffer**](https://learn.microsoft.com/windows/win32/opengl/glselectbuffer)

