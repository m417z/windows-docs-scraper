# DDGETVERSIONNUMBER structure

## Description

The DDGETVERSIONNUMBER structure contains the version number of the kernel-mode video transport component of Microsoft DirectDraw that is supported by the [video miniport driver](https://learn.microsoft.com/windows-hardware/drivers/display/video-miniport-drivers-in-the-windows-2000-display-driver-model)'s [DxApi interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/).

## Members

### `ddRVal`

Specifies the location in which DirectDraw writes the return value of the [DxApi](https://learn.microsoft.com/previous-versions/windows/drivers/display/nf-dxapi-dxapi) function for [DD_DXAPI_GETVERSIONNUMBER](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550637(v=vs.85)) operations. A return code of DD_OK indicates success.

### `dwMajorVersion`

Specifies the major version number (DXAPI_MAJORVERSION defined in *ddkmapi.h*).

### `dwMinorVersion`

Specifies the minor version number (DXAPI_MINORVERSION defined in *ddkmapi.h*).

## See also

[DD_DXAPI_GETVERSIONNUMBER](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550637(v=vs.85))

[DxApi](https://learn.microsoft.com/previous-versions/windows/drivers/display/nf-dxapi-dxapi)