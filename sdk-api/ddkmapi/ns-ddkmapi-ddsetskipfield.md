# DDSETSKIPFIELD structure

## Description

The DDSETSKIPFIELD structure contains the start field information.

## Members

### `hDirectDraw`

Specifies the Microsoft DirectDraw handle.

### `hVideoPort`

Specifies the [video port extensions (VPE)](https://learn.microsoft.com/windows-hardware/drivers/) object handle.

### `dwStartField`

Indicates the field that needs to be skipped and is relative to the current field. A value of 0 indicates it should skip the next field, a value of 1 indicates the field after that, and so on.

## See also

[DD_DXAPI_SET_VP_SKIP_FIELD](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff551510(v=vs.85))

[DxApi](https://learn.microsoft.com/previous-versions/windows/drivers/display/nf-dxapi-dxapi)