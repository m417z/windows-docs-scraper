# DDGETKERNELCAPSOUT structure

## Description

The DDGETKERNELCAPSOUT structure contains the capabilities of the Microsoft DirectDraw object.

## Members

### `ddRVal`

Specifies the location in which DirectDraw writes the return value of the [DxApi](https://learn.microsoft.com/previous-versions/windows/drivers/display/nf-dxapi-dxapi) function for [DD_DXAPI_GETKERNELCAPS](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550629(v=vs.85)) operations. A return code of DD_OK indicates success.

### `dwCaps`

Can be any combination of the capabilities in the **dwCaps** member of the [DDKERNELCAPS](https://learn.microsoft.com/windows/desktop/api/ddkernel/ns-ddkernel-ddkernelcaps) structure.

### `dwIRQCaps`

Can be a combination of the flags in the **dwIRQCaps** member of DDKERNELCAPS.

## See also

[DD_DXAPI_GETKERNELCAPS](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550629(v=vs.85))

[DxApi](https://learn.microsoft.com/previous-versions/windows/drivers/display/nf-dxapi-dxapi)