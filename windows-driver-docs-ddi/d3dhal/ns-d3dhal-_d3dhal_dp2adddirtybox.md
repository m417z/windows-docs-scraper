# _D3DHAL_DP2ADDDIRTYBOX structure

## Description

 DirectX 8.1 and later versions only.

D3DHAL_DP2ADDDIRTYBOX is used to specify that a portion of a 3D resource--a volume texture--was dirtied in system memory. Therefore, this volume must be reloaded into video memory before being used.

## Members

### `dwSurface`

Specifies the handle to the managed 3D resource that contains a dirtied volume texture.

### `DirtyBox`

Specifies the volume texture that was marked as dirtied. This is a D3DBOX structure, which is described in the Microsoft Windows SDK documentation.

## Remarks

D3DHAL_DP2ADDDIRTYBOX, along with the DP2OP_ADDDIRTYBOX token, is used only for driver managed resources. D3DHAL_DP2ADDDIRTYBOX is never sent unless the driver indicates that it manages resources. To indicate that it manages resources, the driver must set the DDCAPS2_CANMANAGERESOURCE bit, in addition to the DDCAPS2_CANMANAGETEXTURE bit, in the **dwCaps2** member of a DDCORECAPS structure. The driver specifies this [DDCORECAPS](https://learn.microsoft.com/windows/win32/api/ddrawi/ns-ddrawi-ddcorecaps) structure in the **ddCaps** member of a [DD_HALINFO](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_halinfo) structure when the driver's [DrvGetDirectDrawInfo](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvgetdirectdrawinfo) function is called to initialize the DirectDraw component of the driver.

## See also

[D3DHAL_DP2COMMAND](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2command)

[D3DHAL_DP2OPERATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ne-d3dhal-_d3dhal_dp2operation)

[DDCORECAPS](https://learn.microsoft.com/windows/win32/api/ddrawi/ns-ddrawi-ddcorecaps)

[DD_HALINFO](https://learn.microsoft.com/windows/win32/api/ddrawint/ns-ddrawint-dd_halinfo)

[DrvGetDirectDrawInfo](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvgetdirectdrawinfo)