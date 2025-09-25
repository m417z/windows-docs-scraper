# DXGKDDI_CONTROLINTERRUPT2 callback function

## Description

The **DxgkDdi_ControlInterrupt2** function enables or disables the given interrupt type on the graphics hardware.

## Parameters

### `hAdapter` [in]

A handle to the adapter object for the graphics processing unit (GPU). The driver returned this handle in the *MiniportDeviceContext* parameter from a call to its [**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

### `InterruptControl` [in]

A [**DXGKARG_CONTROLINTERRUPT2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_controlinterrupt2) structure that supplies the interrupt type, as well as the VSYNC state.

## Return value

*DxgkDdi_ControlInterrupt2* returns one of the following values:

| **Return code** | **Description** |
|:--|:--|
| **STATUS_SUCCESS** | The interrupt type was successfully enabled or disabled on the graphics hardware. |
| **STATUS_NOT_IMPLEMENTED** | *DxgkDdi_ControlInterrupt2* does not support enabling or disabling the specified interrupt type. |

## Remarks

Only one of **DxgkDdiControlInterrupt2** or [**DxgkDdi_ControlInterrupt3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_controlinterrupt3) will be used by the OS during the lifetime of an adapter.

WDDM 2.7 drivers that do not implement [**DxgkDdi_ControlInterrupt3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_controlinterrupt3) are opting out of independent VidPn VSync control, and the OS will only call **DxgkDdi_ControlInterrupt2**. The [**DXGK_DRIVERCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_drivercaps)**->IndependentVidPnVSync** capability must be 0 in drivers that do not support **DxgkDdi_ControlInterrupt3**; otherwise, the OS will fail adapter initialization. If driver does implement **DxgkDdi_ControlInterrupt3**, then the capability can be set to 0 or 1 to indicate Per-VidPn support.

## See also

[**DXGK_DRIVERCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_drivercaps)

[**DXGKARG_CONTROLINTERRUPT2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_controlinterrupt2)

[**DXGKARG_CONTROLINTERRUPT3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_controlinterrupt3)

[**DxgkDdi_ControlInterrupt3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_controlinterrupt3)

[**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)