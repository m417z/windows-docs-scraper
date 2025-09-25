# _D3DHAL_DP2ADDDIRTYRECT structure

## Description

 DirectX 8.1 and later versions only.

D3DHAL_DP2ADDDIRTYRECT is used to specify that a portion of a 2D resource--a 2D texture or cube texture--was dirtied in system memory. Therefore, this 2D texture must be reloaded into video memory before being used.

## Members

### `dwSurface`

Specifies the handle to the managed 2D resource that contains a dirtied 2D texture.

### `rDirtyArea`

Specifies the 2D texture that was marked as dirtied. This is a [RECTL](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rectl) structure.

## Remarks

D3DHAL_DP2ADDDIRTYRECT, along with the DP2OP_ADDDIRTYRECT token, is used only for driver managed resources and surfaces. D3DHAL_DP2ADDDIRTYRECT is never sent unless the driver indicates that it manages resources. To indicate that it manages resources, the driver must set the DDCAPS2_CANMANAGERESOURCE bit, in addition to the DDCAPS2_CANMANAGETEXTURE bit, in the **dwCaps2** member of a DDCORECAPS structure. The driver specifies this [DDCORECAPS](https://learn.microsoft.com/windows/win32/api/ddrawi/ns-ddrawi-ddcorecaps) structure in the **ddCaps** member of a [DD_HALINFO](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_halinfo) structure when the driver's [DrvGetDirectDrawInfo](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvgetdirectdrawinfo) function is called to initialize the DirectDraw component of the driver.

## See also

[D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command)

[D3DHAL_DP2OPERATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ne-d3dhal-_d3dhal_dp2operation)

[DDCORECAPS](https://learn.microsoft.com/windows/win32/api/ddrawi/ns-ddrawi-ddcorecaps)

[DD_HALINFO](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_halinfo)

[DrvGetDirectDrawInfo](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvgetdirectdrawinfo)