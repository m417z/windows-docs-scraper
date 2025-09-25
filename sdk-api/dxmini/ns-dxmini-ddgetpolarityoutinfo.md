# DDGETPOLARITYOUTINFO structure

## Description

The DDGETPOLARITYOUTINFO structure contains the polarity information of the [video port extensions (VPE)](https://learn.microsoft.com/windows-hardware/drivers/) object.

## Members

### `bPolarity`

Indicates the polarity (even or odd) of the current field being written by the VPE object. A value of 0x00000001 indicates even, 0x00000000 indicates odd.

## See also

[DxGetPolarity](https://learn.microsoft.com/windows/desktop/api/dxmini/nc-dxmini-pdx_getpolarity)