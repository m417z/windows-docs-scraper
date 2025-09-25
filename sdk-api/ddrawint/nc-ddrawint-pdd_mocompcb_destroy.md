## Description

The **DdMoCompDestroy** callback function notifies the driver that this motion compensation object will no longer be used. The driver now needs to perform any necessary cleanup.

## Parameters

### `unnamedParam1`

Points to a [DD_DESTROYMOCOMPDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_destroymocompdata) structure that contains the information needed to finish motion compensation.

## Return value

**DdMoCompDestroy** returns one of the following callback codes:

## Remarks

**DdMoCompDestroy** can be optionally implemented in DirectDraw drivers. It is not required for motion compensation support.

## See also

[DD_DESTROYMOCOMPDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_destroymocompdata)