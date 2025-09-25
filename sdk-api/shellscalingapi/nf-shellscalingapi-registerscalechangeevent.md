# RegisterScaleChangeEvent function

## Description

Registers for an event that is triggered when the scale has possibly changed. This function replaces [RegisterScaleChangeNotifications](https://learn.microsoft.com/windows/desktop/api/shellscalingapi/nf-shellscalingapi-registerscalechangenotifications).

## Parameters

### `hEvent` [in]

Handle of the event to register for scale change notifications.

### `pdwCookie` [out]

When this function returns successfully, this value receives the address of a pointer to a cookie that can be used later to unregister for the scale change notifications through [UnregisterScaleChangeEvent](https://learn.microsoft.com/windows/desktop/api/shellscalingapi/nf-shellscalingapi-unregisterscalechangeevent).

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The event is raised whenever something that can affect scale changes, but just because the scale can be affected doesn't mean that it has been. Callers can cache the scale factor to verify that the monitor's scale actually has changed. The event handle will be duplicated, so callers can close their handle at any time.

## See also

[GetScaleFactorForMonitor](https://learn.microsoft.com/windows/desktop/api/shellscalingapi/nf-shellscalingapi-getscalefactorformonitor)

[UnregisterScaleChangeEvent](https://learn.microsoft.com/windows/desktop/api/shellscalingapi/nf-shellscalingapi-unregisterscalechangeevent)