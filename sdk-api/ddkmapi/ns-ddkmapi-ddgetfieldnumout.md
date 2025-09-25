# DDGETFIELDNUMOUT structure

## Description

The DDGETFIELDNUMOUT structure contains the hardware video port's field number.

## Members

### `ddRVal`

Specifies the location in which Microsoft DirectDraw writes the return value of the [DxApi](https://learn.microsoft.com/previous-versions/windows/drivers/display/nf-dxapi-dxapi) function for [DD_DXAPI_GET_VP_FIELD_NUMBER](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550686(v=vs.85)) operations. A return code of DD_OK indicates success.

### `dwFieldNum`

Specifies the hardware video port's field number.

## See also

[DD_DXAPI_GET_VP_FIELD_NUMBER](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550686(v=vs.85))

[DxApi](https://learn.microsoft.com/previous-versions/windows/drivers/display/nf-dxapi-dxapi)