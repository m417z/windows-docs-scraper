# DXGKARG_QUERYDPCAPS structure

## Description

The **DXGKARG_QUERYDPCAPS** structure is a parameter for the [**DXGKDDI_QUERYDPCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_querydpcaps) callback.

## Members

### `NumRootPorts`

Number of DisplayPort (DP) capable connectors on the GPU, including the one for the eDP internal panel.

### `DPVersionMajor`

Value that represents the major version of the DP protocol.

### `DPVersionMinor`

Value that represents the minor version of the DP protocol.

## Remarks

Subsequent transmission calls will refer to the DP connectors with **RootPortIndex** ranging from **0** to **NumRootPorts - 1**.

**DPVersionMajor** and **DPVersionMinor** is the highest version of the DP protocol supported by the driver and GPU DP root ports of major/minor versions. For example, **DPVersionMajor == 1** and **DPVersionMinor == 1** represent DP protocol 1.1, **DPVersionMajor == 1** and **DPVersionMinor == 2** is for 1.2, and so forth.

## See also

[**DXGKDDI_DPAUXIOTRANSMISSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_dpauxiotransmission)

[**DXGKDDI_DPI2CIOTRANSMISSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_dpi2ciotransmission)

[**DXGKDDI_DPSBMTRANSMISSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_dpsbmtransmission)

[**DXGKDDI_QUERYDPCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_querydpcaps)