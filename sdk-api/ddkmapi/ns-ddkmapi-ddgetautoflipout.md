# DDGETAUTOFLIPOUT structure

## Description

The DDGETAUTOFLIPOUT structure contains the handle and polarity information returned from the [DD_DXAPI_GET_CURRENT_VP_AUTOFLIP_SURFACE](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550642(v=vs.85)) and [DD_DXAPI_GET_LAST_VP_AUTOFLIP_SURFACE](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550650(v=vs.85)) function identifiers of the [DxApi](https://learn.microsoft.com/previous-versions/windows/drivers/display/nf-dxapi-dxapi) function.

## Members

### `ddRVal`

Specifies the location in which Microsoft DirectDraw writes the return value of the [DxApi](https://learn.microsoft.com/previous-versions/windows/drivers/display/nf-dxapi-dxapi) function for operations that obtain autoflip surfaces. Contains DD_OK if the hardware video port is in autoflip mode.

### `hVideoSurface`

Handle for the current video surface.

### `hVBISurface`

Handle for the current [VBI](https://learn.microsoft.com/windows-hardware/drivers/) data.

### `bPolarity`

Specifies whether the field is an even or odd field of an interlaced video signal. This member should be set to **TRUE** if the current field is the even field and to **FALSE** if the current field is the odd field.

## See also

[DD_DXAPI_GET_CURRENT_VP_AUTOFLIP_SURFACE](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550642(v=vs.85))

[DD_DXAPI_GET_LAST_VP_AUTOFLIP_SURFACE](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550650(v=vs.85))

[DxApi](https://learn.microsoft.com/previous-versions/windows/drivers/display/nf-dxapi-dxapi)