# DDOPENDIRECTDRAWIN structure

## Description

The DDOPENDIRECTDRAWIN structure contains the Microsoft DirectDraw object information.

## Members

### `dwDirectDrawHandle`

Contains the DirectDraw handle that was passed down from user mode.

### `pfnDirectDrawClose`

Points to a [pfnDirectDrawClose](https://learn.microsoft.com/windows/desktop/api/ddkmapi/nc-ddkmapi-lpdd_notifycallback) callback function that is called if the DirectDraw object goes away.

### `pContext`

Contains a value that is passed if the [pfnDirectDrawClose](https://learn.microsoft.com/windows/desktop/api/ddkmapi/nc-ddkmapi-lpdd_notifycallback) callback is ever called.

## See also

[DD_DXAPI_OPENDIRECTDRAW](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550702(v=vs.85))

[DxApi](https://learn.microsoft.com/previous-versions/windows/drivers/display/nf-dxapi-dxapi)