# DXGKDDI_QUERYDPCAPS callback function

## Description

The **DXGKDDI_QUERYDPCAPS** callback functions queries the DisplayPort (DP) capabilities of the GPU and driver supported.

## Parameters

### `Context`

Context pointer provided when querying the interface.

### `pArgs`

Pointer to a [**DXGKARG_QUERYDPCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgkarg_querydpcaps) structure in which to return the DP capabilities.

## Return value

**DXGKDDI_QUERYDPCAPS** returns STATUS_SUCCESS if it succeeds; otherwise it returns an error code.

## Remarks

The driver should return in **NumRootPorts** the number of DP capable connectors on the GPU, including the one for eDP internal panel. Subsequent transmission calls will refer to the DP connectors with **RootPortIndex** ranging from **0** to **NumRootPorts - 1**.

**DPVersionMajor** and **DPVersionMinor** is the highest version of DP protocol supported by the driver and GPU DP root ports of major/minor versions. For example, **DPVersionMajor == 1** and **DPVersionMinor == 1** is for DP protocol 1.1, and **DPVersionMajor == 1** and **DPVersionMinor == 2** is for DP protocol 1.2.

## See also

[**DXGKARG_QUERYDPCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgkarg_querydpcaps)

[**DXGKDDI_DPAUXIOTRANSMISSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_dpauxiotransmission)

[**DXGKDDI_DPI2CIOTRANSMISSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_dpi2ciotransmission)

[**DXGKDDI_DPSBMTRANSMISSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_dpsbmtransmission)