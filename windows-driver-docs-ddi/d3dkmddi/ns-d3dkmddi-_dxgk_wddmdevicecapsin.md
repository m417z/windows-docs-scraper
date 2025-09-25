# _DXGK_WDDMDEVICECAPSIN structure

## Description

Contains the WDDM version that is supported by the driver after the call to [DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device), and before the call to [DxgkDdiStartDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device).

## Members

### `DxgkrnlInterfaceVersion`

Indicates the version of the functional interface implemented by the display port driver. This value is the same value as the **Version member** of the [DXGKRNL_INTERFACE structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface) that was passed to [DxgkDdiStartDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device).

See the [IS_OFFICIAL_DDI_INTERFACE_VERSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/nf-d3dukmdt-is_official_ddi_interface_version) macro for a list of available values.

## Remarks

## See also