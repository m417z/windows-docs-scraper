# DDCAPBUFFINFO structure

## Description

The DDCAPBUFFINFO structure contains the capture information.

## Members

### `dwFieldNumber`

Indicates the internal field number of the field captured.

### `bPolarity`

Specifies whether the captured field is an even or odd field. A value of 0x00000001 indicates even, 0x00000000 indicates odd.

### `liTimeStamp`

Used by Microsoft DirectDraw and should be ignored by the driver.

### `ddRVal`

Specifies the location in which DirectDraw writes the return value of the [DxApi](https://learn.microsoft.com/previous-versions/windows/drivers/display/nf-dxapi-dxapi) function for the [DD_DXAPI_ADDVPCAPTUREBUFFER](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550599(v=vs.85)) operation. Contains DD_OK if the capture buffer contains valid data.

## See also

[DDADDVPCAPTUREBUFF](https://learn.microsoft.com/windows/desktop/api/ddkmapi/ns-ddkmapi-ddaddvpcapturebuff)

[DD_DXAPI_ADDVPCAPTUREBUFFER](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550599(v=vs.85))

[DxApi](https://learn.microsoft.com/previous-versions/windows/drivers/display/nf-dxapi-dxapi)