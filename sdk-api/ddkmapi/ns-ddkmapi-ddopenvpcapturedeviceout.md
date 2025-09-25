# DDOPENVPCAPTUREDEVICEOUT structure

## Description

The DDOPENVPCAPTUREDEVICEOUT structure contains the [video port extensions (VPE)](https://learn.microsoft.com/windows-hardware/drivers/) capture handle.

## Members

### `ddRVal`

Specifies the location in which Microsoft DirectDraw writes the return value of the [DxApi](https://learn.microsoft.com/previous-versions/windows/drivers/display/nf-dxapi-dxapi) function for [DD_DXAPI_OPENVPCAPTUREDEVICE](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff551500(v=vs.85)) operations. A return code of DD_OK indicates success.

### `hCapture`

Handle to the new VPE capture object.

## See also

[DD_DXAPI_OPENVPCAPTUREDEVICE](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff551500(v=vs.85))

[DxApi](https://learn.microsoft.com/previous-versions/windows/drivers/display/nf-dxapi-dxapi)