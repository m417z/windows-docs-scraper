# DXGK_MIPI_DSI_INTERFACE structure

## Description

DXGK_MIPI_DSI_INTERFACE allows the OS to request Display Serial Interface (DSI) operations to be performed on a target using a control interface to the target owned by the graphics adapter.

## Members

### `Size` [in]

The size, in bytes, of this structure.

### `Version` [in]

The version number of the DSI interface. Version number constants are defined in *Dispmprt.h* (for example, DXGK_MIPI_DSI_INTERFACE_VERSION_1).

### `Context` [in]

Pointer to a private context block.

### `InterfaceReference` [out]

Pointer to an interface reference function that is implemented by the display miniport driver.

### `InterfaceDereference` [out]

Pointer to an interface dereference function that is implemented by the display miniport driver.

### `DxgkDdiDsiCaps` [out]

Pointer to a display miniport driver [DsiCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_dsicaps) function to query capabilities for a particular target. `pArgs` is a [DXGI_DSI_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_dsi_caps) structure.

### `DxgkDdiDsiTransmission` [out]

Pointer to a display miniport driver [DsiTransmission](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_dsitransmission) function to perform a DSI transmission. `pArgs` is a [DXGI_DSI_TRANSMISSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_dsi_transmission) structure.

### `DxgkDdiDsiReset` [out]

Pointer to a display miniport driver [DsiReset](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_dsireset) function to perform a DSI reset. `pArgs` is a [DXGI_DSI_RESET](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_dsi_reset) structure.

## Remarks

A kernel-mode component that needs to use the MIPI DSI Display Control interface calls the display miniport driver's [DxgkDdiQueryInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_interface) function to get its DSI-related functional interface.

## See also

[DXGI_DSI_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_dsi_caps)

[DXGI_DSI_RESET](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_dsi_reset)

[DXGI_DSI_TRANSMISSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_dsi_transmission)

[DsiCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_dsicaps)

[DxgkDdiQueryInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_interface)

[DsiReset](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_dsireset)

[DsiTransmission](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_dsitransmission)