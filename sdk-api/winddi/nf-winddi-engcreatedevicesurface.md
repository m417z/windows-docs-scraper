# EngCreateDeviceSurface function

## Description

The **EngCreateDeviceSurface** function creates and returns a handle for a device surface that the driver will manage.

## Parameters

### `dhsurf` [in]

Device handle to the surface to be managed by the device. This handle is passed to the driver when a [SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj) structure is passed for input or output.

### `sizl` [in]

Specifies a SIZEL structure that contains the width and height of the surface to be created. The **cx** and **cy** members of this structure contain respectively, the surface's width and height, in pixels. A SIZEL structure is identical to a [SIZE](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-size) structure.

### `iFormatCompat`

Specifies the compatible engine format of the device surface being created. This is used by GDI if a temporary buffer is needed to simulate a complicated drawing call.

## Return value

The return value is a handle that identifies the surface if the function is successful. Otherwise, it is zero, and an error code is logged.

## Remarks

The storage space for the surface can optionally be provided by the driver. The surface should be associated by using [EngAssociateSurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engassociatesurface). The surface should be deleted when it is no longer needed by using [EngDeleteSurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engdeletesurface).

## See also

[EngAssociateSurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engassociatesurface)

[EngDeleteSurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engdeletesurface)

[SURFOBJ](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-surfobj)