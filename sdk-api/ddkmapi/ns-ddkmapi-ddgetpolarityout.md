# DDGETPOLARITYOUT structure

## Description

The DDGETPOLARITYOUT structure contains the requested polarity information.

## Members

### `ddRVal`

Specifies the location in which Microsoft DirectDraw writes the return value of the [DxApi](https://learn.microsoft.com/previous-versions/windows/drivers/display/nf-dxapi-dxapi) function for [DD_DXAPI_GET_POLARITY](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550660(v=vs.85)) operations. A return code of DD_OK indicates success.

### `bPolarity`

Specifies whether the field is an even or odd field of an interlaced video signal. A value of **TRUE** indicates even, **FALSE** indicates odd.

## See also

[DD_DXAPI_GET_POLARITY](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550660(v=vs.85))

[DxApi](https://learn.microsoft.com/previous-versions/windows/drivers/display/nf-dxapi-dxapi)