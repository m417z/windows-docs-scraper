## Description

The *DdMoCompCreate* callback function notifies the driver that a software decoder will start using motion compensation with the specified GUID.

## Parameters

### `unnamedParam1`

Points to a [DD_CREATEMOCOMPDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_createmocompdata) structure that contains the information required to begin using motion compensation.

## Return value

*DdMoCompCreate* returns one of the following callback codes:

## Remarks

*DdMoCompCreate* can be optionally implemented in DirectDraw drivers. It is not required for motion compensation support.

*DdMoCompCreate* also reports the width, height, and format of the output frame. The driver can fail this call if it cannot support motion compensation with these dimensions.

## See also

[DD_CREATEMOCOMPDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_createmocompdata)