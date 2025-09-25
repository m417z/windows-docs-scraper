## Description

The **DdAddAttachedSurface** callback function attaches a surface to another surface.

## Parameters

### `unnamedParam1`

Points to a [DD_ADDATTACHEDSURFACEDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_addattachedsurfacedata) structure that contains information required for the driver to perform the attachment.

## Return value

**DdAddAttachedSurface** returns one of the following callback codes:

## Remarks

**DdAddAttachedSurface** can be optionally implemented in DirectDraw drivers.

The driver should update any internal surface state it keeps to reflect the attachment.

## See also

[DD_ADDATTACHEDSURFACEDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_addattachedsurfacedata)