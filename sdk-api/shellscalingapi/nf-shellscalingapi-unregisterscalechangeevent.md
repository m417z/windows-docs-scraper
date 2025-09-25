# UnregisterScaleChangeEvent function

## Description

Unregisters for the scale change event registered through [RegisterScaleChangeEvent](https://learn.microsoft.com/windows/desktop/api/shellscalingapi/nf-shellscalingapi-registerscalechangeevent). This function replaces [RevokeScaleChangeNotifications](https://learn.microsoft.com/windows/desktop/api/shellscalingapi/nf-shellscalingapi-revokescalechangenotifications).

## Parameters

### `dwCookie` [in]

A pointer to the cookie retrieved in the call to [RegisterScaleChangeEvent](https://learn.microsoft.com/windows/desktop/api/shellscalingapi/nf-shellscalingapi-registerscalechangeevent).

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[GetScaleFactorForMonitor](https://learn.microsoft.com/windows/desktop/api/shellscalingapi/nf-shellscalingapi-getscalefactorformonitor)

[RegisterScaleChangeEvent](https://learn.microsoft.com/windows/desktop/api/shellscalingapi/nf-shellscalingapi-registerscalechangeevent)