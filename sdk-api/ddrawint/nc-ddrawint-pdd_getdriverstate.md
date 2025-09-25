## Description

The *D3dGetDriverState* function is used by both the Microsoft DirectDraw and Microsoft Direct3D runtimes to obtain information from the driver about its current state.

## Parameters

### `unnamedParam1`

Points to a [DD_GETDRIVERSTATEDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_getdriverstatedata) structure that describes the state of the driver.

## Return value

*D3dGetDriverState* returns one of the following callback codes:

## Remarks

All Direct3D drivers must support *D3dGetDriverState*.

## See also

[DD_GETDRIVERSTATEDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_getdriverstatedata)