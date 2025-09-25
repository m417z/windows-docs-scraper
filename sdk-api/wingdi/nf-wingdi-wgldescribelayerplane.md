# wglDescribeLayerPlane function

## Description

The **wglDescribeLayerPlane** function obtains information about the layer planes of a given pixel format.

## Parameters

### `unnamedParam1`

Specifies the device context of a window whose layer planes are to be described.

### `unnamedParam2`

Specifies which layer planes of a pixel format are being described.

### `unnamedParam3`

Specifies the overlay or underlay plane. Positive values of *iLayerPlane* identify overlay planes, where 1 is the first overlay plane over the main plane, 2 is the second overlay plane over the first overlay plane, and so on. Negative values identify underlay planes, where 1 is the first underlay plane under the main plane, 2 is the second underlay plane under the first underlay plane, and so on. The number of overlay and underlay planes is given in the **bReserved** member of the [PIXELFORMATDESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-pixelformatdescriptor) structure.

### `unnamedParam4`

Specifies the size, in bytes, of the structure pointed to by *plpd*. The **wglDescribeLayerPlane** function stores layer plane data in a [LAYERPLANEDESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-layerplanedescriptor) structure, and stores no more than *nBytes* of data. Set the value of *nBytes* to the size of **LAYERPLANEDESCRIPTOR**.

### `unnamedParam5`

Points to a **LAYERPLANEDESCRIPTOR** structure. The **wglDescribeLayerPlane** function sets the value of the structure's data members. The function stores the number of bytes of data copied to the structure in the **nSize** member.

## Return value

If the function succeeds, the return value is **TRUE**. In addition, the **wglDescribeLayerPlane** function sets the members of the **LAYERPLANEDESCRIPTOR** structure pointed to by *plpd* according to the specified layer plane (*iLayerPlane* ) of the specified pixel format (*iPixelFormat* ).

If the function fails, the return value is **FALSE**.

## Remarks

The numbering of planes (*iLayerPlane* ) determines their order. Higher-numbered planes overlay lower-numbered planes.

## See also

[DescribePixelFormat](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-describepixelformat)

[LAYERPLANEDESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-layerplanedescriptor)

[OpenGL on Windows](https://learn.microsoft.com/windows/desktop/OpenGL/opengl-on-windows-nt--windows-2000--and-windows-95-98)

[PIXELFORMATDESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-pixelformatdescriptor)

[WGL Functions](https://learn.microsoft.com/windows/desktop/OpenGL/wgl-functions)

[wglCreateLayerContext](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-wglcreatelayercontext)