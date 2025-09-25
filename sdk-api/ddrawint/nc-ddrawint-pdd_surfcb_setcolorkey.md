## Description

The *DdSetColorKey* callback function sets the color key value for the specified surface.

## Parameters

### `unnamedParam1`

Points to a [DD_SETCOLORKEYDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_setcolorkeydata) structure that contains the information required to set the color key for the specified surface.

## Return value

*DdSetColorKey* returns one of the following callback codes:

## Remarks

*DdSetColorKey* sets the source or destination color key for the specified surface. Typically, this callback is implemented only for drivers that support overlays with color key capabilities.

## See also

[DD_SETCOLORKEYDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_setcolorkeydata)