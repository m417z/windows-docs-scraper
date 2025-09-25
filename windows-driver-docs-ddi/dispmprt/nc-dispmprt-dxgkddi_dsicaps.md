# DXGKDDI_DSICAPS callback function

## Description

The *DxgkddiDsiCaps* callback function queries the Display Serial Interface (DSI) capabilities for a particular target.

## Parameters

### `Context` [in]

As retrieved from the driver's MIPI interface (DXGK_MIPIDSI_interface ,_ DXGK queries the driver for this context.

### `TargetId` [in]

Target identifier of the monitor.

### `pArgs` [out]

Pointer to a [DXGI_DSI_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_dsi_caps) structure.

## Return value

*DxgkddiDsiCaps* returns STATUS_SUCCESS if it succeeds; otherwise it returns one of the error codes defined in *Ntstatus.h*.

## Remarks

An OEM panel driver should initialize by sending [IOCTL_MIPI_DSI_QUERY_CAPS]() which provides information to allow the OEM panel driver to verify driver support, and provides the raw level 1 DDB data from the display to allow one panel driver to support multiple devices and to confirm that there is no mismatch. The OS graphics kernel calls DxgkddiDsiCaps when it receives this IOCTL. The capabilities are returned in a DXGK_DSI_CAPS structure.

The graphics driver fills in the [DXGI_DSI_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_dsi_caps) fields, using cached information if available since the data should be static. Since the OS needs the`TargetMaximumReturnPacketSize` field value for packet validation, it can request the capabilities from the graphics driver before receiving a request from the panel driver.

The OEM panel driver is responsible for validating DSI capability and compatibility with the panel, since neither the graphics driver nor the OS has sufficient information to do so, particularly for any manufacturer defined or undefined elements.

## See also

[DXGI_DSI_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_dsi_caps)

[IOCTL_MIPI_DSI_QUERY_CAPS]()