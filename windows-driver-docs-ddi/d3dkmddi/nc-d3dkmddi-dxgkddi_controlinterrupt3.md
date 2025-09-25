## Description

The *DxgkDdi_ControlInterrupt3* function enables or disables the given interrupt type for the specified VidPnSourceId on the graphics hardware.

## Parameters

### `hAdapter` [in]

A handle to the adapter object for the graphics processing unit (GPU). The driver returned this handle in the *MiniportDeviceContext* parameter from a call to its [*DxgkDdiAddDevice*](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

### `InterruptControl` [in]

A [**DXGKARG_CONTROLINTERRUPT3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_controlinterrupt3) structure that supplies the interrupt type, the VSYNC state, and the VidPnSourceId.

## Return value

*DxgkDdi_ControlInterrupt3* returns one of the following values:

| **Return code** | **Description** |
|:--|:--|
| **STATUS_SUCCESS** | The interrupt type was successfully enabled or disabled on the graphics hardware. |
| **STATUS_NOT_IMPLEMENTED** | [DxgkDdi_ControlInterrupt3](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_controlinterrupt2) does not support enabling or disabling the specified interrupt type. |

## Remarks

VSync control is used in WDDM to toggle VSync ON and OFF to balance between active usage of a VidPn source by a scenario and power savings achieved by turning OFF VSync. In general, the operating system controls the logic of when VSync should remain ON and OFF and notifies the IHV Kernel Mode Driver (KMD) via a DDI call. The KMD executes the request. Before Windows 10, version 2004 (WDDM 2.7), the granularity of VSync control is per adapter; that is, for a given adapter, VSync control applies to every VidPn source of the adapter. For example, consider an adapter that has two VidPn sources connected to two different outputs. If one output has no activity and no consumers for VSync/VBlank on it, then there is only one option: the OS has to keep VSync ON for the inactive output.

For dual screen portable devices, keeping VSync ON for one screen when it is not needed has significant power costs. It requires the display controller/display link to remain active and prevents panels which support self-refresh from going into a low frequency, low power self-refresh mode. In Windows 10, version 2004 and later versions, *DxgkDdiControlInterrupt3* allows for finer granularity VSync control of per VidPn Source of an adapter.

Only one of *DxgkDdiControlInterrupt3* or [*DxgkDdi_ControlInterrupt2*](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_controlinterrupt2) will be used by the OS during the lifetime of an adapter.

WDDM 2.7 drivers that do not implement *DxgkDdi_ControlInterrupt3* are opting out of independent VidPn VSync control, and the OS will only call [*DxgkDdi_ControlInterrupt2*](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_controlinterrupt2). The [**DXGK_DRIVERCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_drivercaps)**->IndependentVidPnVSync** capability must be 0 in drivers that do not support *DxgkDdi_ControlInterrupt3*; otherwise, the OS will fail adapter initialization. If a driver does implement *DxgkDdi_ControlInterrupt3*, then the capability can be set to 0 or 1 to indicate Per-VidPn support.

## See also

[**DXGKARG_CONTROLINTERRUPT2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_controlinterrupt2)

[**DXGK_DRIVERCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_drivercaps)

[**DXGKARG_CONTROLINTERRUPT3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_controlinterrupt3)

[*DxgkDdi_ControlInterrupt2*](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_controlinterrupt2)