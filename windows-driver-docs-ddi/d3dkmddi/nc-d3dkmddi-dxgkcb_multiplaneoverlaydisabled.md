# DXGKCB_MULTIPLANEOVERLAYDISABLED callback function

## Description

A kernel-mode display miniport driver calls **DXGKCB_MULTIPLANEOVERLAYDISABLED** to indicate that the current multiplane overlay (MPO) configuration is no longer supported on the specified *VidPnSourceId*.

## Parameters

### `hAdapter` [in]

Handle to the adapter on which the current MPO hardware configuration is no longer supported.

### `VidPnSourceId` [in]

The *VidPnSourceId* on which the current MPO hardware configuration is no longer supported.

## Remarks

**DXGKCB_MULTIPLANEOVERLAYDISABLED** notifies the Desktop Windows Manager (DWM) that the current MPO configuration is no longer supported, allowing the DWM to fall back to composition.

This request is processed asynchronously and can be delayed by several frames. It is recommended to call this function only in exceptional cases such as the following scenarios:

* A display change or hot plug event on one output makes it no longer possible to continue supporting an MPO configuration that is committed to a different monitor. In this case, the driver can disable the overlay planes on the monitor. The user will see a visible artifact but it should be corrected eventually by the DWM.

* MPO should be disabled due to thermal issues. In this case, the driver does not need to immediately disable MPO, but can wait until the DWM receives the notification and requires MPO support (which the KMD should indicate is not supported due to the thermal issue). At that time, the DWM will disable MPO and start composing.

 For typical cases, drivers should instead prevent incompatible multiplane overlay configurations by responding correctly to [DxgkDdiCheckMultiplaneOverlaySupport3](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_checkmultiplaneoverlaysupport3).

*DXGKCB_XXX* functions are implemented by *Dxgkrnl*. To use this callback function, call **DxgkCbMultiPlaneOverlayDisabled** via the [**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface).

## See also

[DxgkDdiCheckMultiplaneOverlaySupport3](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_checkmultiplaneoverlaysupport3)

[**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface)