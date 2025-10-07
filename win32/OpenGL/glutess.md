# gluTessCallback function

The **gluTessCallback** function defines a callback for a tessellation object.

## Parameters

*tess*

The tessellation object (created with [**gluNewTess**](https://learn.microsoft.com/windows/win32/opengl/glunewtess)).

*which*

The callback being defined. The following values are valid: GLU\_TESS\_BEGIN, GLU\_TESS\_BEGIN\_DATA, GLU\_TESS\_EDGE\_FLAG, GLU\_TESS\_EDGE\_FLAG\_DATA, GLU\_TESS\_VERTEX, GLU\_TESS\_VERTEX\_DATA, GLU\_TESS\_END, GLU\_TESS\_END\_DATA, GLU\_TESS\_COMBINE, GLU\_TESS\_COMBINE\_DATA, GLU\_TESS\_ERROR, and GLU\_TESS\_ERROR\_DATA.

For more information on these callbacks, see the following Remarks section.

*fn*

The function to be called.

## Return value

This function does not return a value.

## Remarks

Use **gluTessCallback** to specify a callback to be used by a tessellation object. If the specified callback is already defined, then it is replaced. If *fn* is **NULL**, then the existing callback becomes undefined.

The tessellation object uses these callbacks to describe how a polygon that you specify is broken into triangles.

There are two versions of each callback, one with polygon data that you can define and one without. If both versions of a particular callback are specified, the callback with the polygon data you specify will be used. The *polygon\_data* parameter of [**gluTessBeginPolygon**](https://learn.microsoft.com/windows/win32/opengl/glutessbeginpolygon) is a copy of the pointer that was specified when **gluTessBeginPolygon** was called.

The following are valid callbacks:

| Callback | Description |
|----------|-------------|
| GLU_TESS_BEGIN | The GLU_TESS_BEGIN callback is invoked like [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) to indicate the start of a (triangle) primitive. The function takes a single argument of type **GLenum**. If you set the GLU_TESS_BOUNDARY_ONLY property to GL_FALSE, the argument is set to either GL_TRIANGLE_FAN, GL_TRIANGLE_STRIP, or GL_TRIANGLES. If you set the GLU_TESS_BOUNDARY_ONLY property to GL_TRUE, the argument is set to GL_LINE_LOOP. The function prototype for this callback is as follows: **void****begin** (**GLenum***type*);<br> |
| GLU_TESS_BEGIN_DATA | GLU_TESS_BEGIN_DATA is the same as the GLU_TESS_BEGIN callback except that it takes an additional pointer argument. This pointer is identical to the opaque pointer provided when you call [**gluTessBeginPolygon**](https://learn.microsoft.com/windows/win32/opengl/glutessbeginpolygon). The function prototype for this callback is: **void****beginData** (**GLenum***type*, **void** * *polygon_data*);<br> |
| GLU_TESS_EDGE_FLAG | The GLU_TESS_EDGE_FLAG callback is similar to [**glEdgeFlag**](https://learn.microsoft.com/windows/win32/opengl/gledgeflag-functions). The function takes a single Boolean flag that indicates which edges lie on the polygon boundary. If the flag is GL_TRUE, then each vertex that follows begins an edge that lies on the polygon boundary; that is, an edge which separates an interior region from an exterior one. If the flag is GL_FALSE, then each vertex that follows begins an edge that lies in the polygon interior. The GLU_TESS_EDGE_FLAG callback (if defined) is invoked before the first vertex callback is made. Because triangle fans and triangle strips do not support edge flags, the begin callback is not called with GL_TRIANGLE_FAN or GL_TRIANGLE_STRIP if an edge flag callback is provided. Instead, the fans and strips are converted to independent triangles. The function prototype for this callback is:<br>**void****edgeFlag** (**GLboolean***flag*);<br> |
| GLU_TESS_EDGE_FLAG_DATA | The GLU_TESS_EDGE_FLAG_DATA callback is the same as the GLU_TESS_EDGE_FLAG callback except that it takes an additional pointer argument. This pointer is identical to the opaque pointer provided when you call [**gluTessBeginPolygon**](https://learn.microsoft.com/windows/win32/opengl/glutessbeginpolygon). The function prototype for this callback is: **void****edgeFlagData** (**GLboolean***flag*, **void** * *polygon_data*);<br> |
| GLU_TESS_VERTEX | The GLU_TESS_VERTEX callback is invoked between the begin and end callbacks. It is similar to glVertex , and it defines the vertexes of the triangles created by the tessellation process. The function takes a pointer as its only argument. This pointer is identical to the opaque pointer that you provided when you defined the vertex (see [**gluTessVertex**](https://learn.microsoft.com/windows/win32/opengl/glutessvertex)). The function prototype for this callback is: **void****vertex** (**void** * *vertex_data*);<br> |
| GLU_TESS_VERTEX_DATA | The GLU_TESS_VERTEX_DATA is the same as the GLU_TESS_VERTEX callback except that it takes an additional pointer argument. This pointer is identical to the opaque pointer provided when you call [**gluTessBeginPolygon**](https://learn.microsoft.com/windows/win32/opengl/glutessbeginpolygon). The function prototype for this callback is: **void****vertexData** (void * *vertex_data*, **void** * *polygon_data*);<br> |
| GLU_TESS_END | The GLU_TESS_END callback serves the same purpose as [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend). It indicates the end of a primitive, and it takes no arguments. The function prototype for this callback is: **void****end** (**void**);<br> |
| GLU_TESS_END_DATA | The GLU_TESS_END_DATA callback is the same as the GLU_TESS_END callback except that it takes an additional pointer argument. This pointer is identical to the opaque pointer provided when you call [**gluTessBeginPolygon**](https://learn.microsoft.com/windows/win32/opengl/glutessbeginpolygon). The function prototype for this callback is: **void****endData** (**void** * *polygon_data*);<br> |
| GLU_TESS_COMBINE | Call the GLU_TESS_COMBINE callback to create a new vertex when the tessellation detects an intersection, or to merge features. The function takes four arguments: An array of three elements, each of type Gldouble.<br> An array of four pointers.<br> An array of four elements, each of type GLfloat.<br> A pointer to a pointer.<br> The function prototype for this callback is: <br>**void****combine**(**GLdouble***coords*[3], **void** * *vertex_data*[4], **GLfloat***weight*[4], **void** ***outData*);<br> The vertex is defined as a linear combination of up to four existing vertexes, stored in vertex_data. The coefficients of the linear combination are given by weight; these weights always sum to 1.0. All vertex pointers are valid even when some of the weights are zero. The coords parameter gives the location of the new vertex.<br> Allocate another vertex, interpolate parameters using vertex_data and weight, and return the new vertex pointer in outData. This handle is supplied during rendering callbacks. Free the memory sometime after calling [**gluTessEndPolygon**](https://learn.microsoft.com/windows/win32/opengl/glutessendpolygon).<br> For example, if the polygon lies in an arbitrary plane in three-dimensional space, and you associate a color with each vertex, the GLU_TESS_COMBINE callback might look like the following:<br>
```
void myCombine( GLdouble coords[3], VERTEX *d[4],                 GLfloat w[4], VERTEX **dataOut ) {     VERTEX *newVertex = new_vertex();     newVertex->x = coords[0];     newVertex->y = coords[1];     newVertex->z = coords[2];     newVertex->r = w[0]*d[0]->r + w[1]*d[1]->r + w[2]*d[2]->r +                    w[3]*d[3]->r;     newVertex->g = w[0]*d[0]->g + w[1]*d[1]->g + w[2]*d[2]->g +                    w[3]*d[3]->g;     newVertex->b = w[0]*d[0]->b + w[1]*d[1]->b + w[2]*d[2]->b +                    w[3]*d[3]->b;     newVertex->a = w[0]*d[0]->a + w[1]*d[1]->a + w[2]*d[2]->a +                    w[3]*d[3]->a;     *dataOut = newVertex; }
```

When the tessellation detects an intersection, the GLU_TESS_COMBINE or GLU_TESS_COMBINE_DATA callback (see below) must be defined, and must write a non-**NULL** pointer into dataOut. Otherwise the GLU_TESS_NEED_COMBINE_CALLBACK error occurs, and no output is generated. (This is the only error that can occur during tessellation and rendering.)\
 |
| GLU_TESS_COMBINE_DATA | The GLU_TESS_COMBINE_DATA callback is the same as the GLU_TESS_COMBINE callback except that it takes an additional pointer argument. This pointer is identical to the opaque pointer provided when you call [**gluTessBeginPolygon**](https://learn.microsoft.com/windows/win32/opengl/glutessbeginpolygon). The function prototype for this callback is: **void****combineData** (**GLdouble***coords*[3], **void** **vertex_data*[4], **GLfloat***weight*[4], **void** ***outData*, **void** * *polygon_data*);<br> |
| GLU_TESS_ERROR | The GLU_TESS_ERROR callback is called when an error is encountered. The one argument is of type **GLenum**; it indicates the specific error that occurred and is set to one of the following: GLU_TESS_MISSING_BEGIN_POLYGON<br> GLU_TESS_MISSING_END_POLYGON<br> GLU_TESS_MISSING_BEGIN_CONTOUR<br> GLU_TESS_MISSING_END_CONTOUR<br> GLU_TESS_COORD_TOO_LARGE<br> GLU_TESS_NEED_COMBINE_CALLBACK<br> Call gluErrorString to retrieve character strings describing these errors. The function prototype for this callback is as follows:<br>**void****error** (**GLenum***errno*);<br> The GLU library recovers from the first four errors by inserting the missing call or calls. GLU_TESS_COORD_TOO_LARGE indicates that some vertex coordinate exceeded the predefined constant GLU_TESS_MAX_COORD in absolute value, and that the value has been clamped. (Coordinate values must be small enough that two can be multiplied together without overflow.) GLU_TESS_NEED_COMBINE_CALLBACK indicates that the tessellation detected an intersection between two edges in the input data, and the GLU_TESS_COMBINE or GLU_TESS_COMBINE_DATA callback was not provided. No output will be generated.<br> |
| GLU_TESS_ERROR_DATA | The GLU_TESS_ERROR_DATA callback is the same as the GLU_TESS_ERROR callback, except that it takes an additional pointer argument. This pointer is identical to the opaque pointer provided when you call [**gluTessBeginPolygon**](https://learn.microsoft.com/windows/win32/opengl/glutessbeginpolygon). The function prototype for this callback is: **void****errorData** (**GLenum***errno*, **void** * *polygon_data*);<br> |

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Glu.h |
| Library<br> | Glu32.lib |
| DLL<br> | Glu32.dll |

## See also

[**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin)

[**glEdgeFlag**](https://learn.microsoft.com/windows/win32/opengl/gledgeflag-functions)

[**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend)

[**glVertex**](https://learn.microsoft.com/windows/win32/opengl/glvertex-functions)

[**gluDeleteTess**](https://learn.microsoft.com/windows/win32/opengl/gludeletetess)

[**gluErrorString**](https://learn.microsoft.com/windows/win32/opengl/gluerrorstring)

[**gluNewTess**](https://learn.microsoft.com/windows/win32/opengl/glunewtess)

[**gluTessBeginPolygon**](https://learn.microsoft.com/windows/win32/opengl/glutessbeginpolygon)

[**gluTessEndPolygon**](https://learn.microsoft.com/windows/win32/opengl/glutessendpolygon)

[**gluTessVertex**](https://learn.microsoft.com/windows/win32/opengl/glutessvertex)

