# DXGK_ADAPTER_PERFDATACAPS structure

## Description

The **DXGK_ADAPTER_PERFDATACAPS** structure describes the performance data capabilities of the adapter.

## Members

### `MaxMemoryBandwidth`

The maximum memory bandwidth in bytes for 1 second.

### `MaxPCIEBandwidth`

The maximum PCIE bandwidth in bytes for 1 second.

### `MaxFanRPM`

The maximum fan revolutions per minute of the main fan.

### `TemperatureMax`

The maximum temperature before damage levels occur in deci-Celsius (a value of 1 = 0.1C).

### `TemperatureWarning`

The temperature level where temperature based throttling begins in deci-Celsius (a value of 1 = 0.1C).

## Remarks

KMD's [**DxgkDdiQueryAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo) function should fill in the **DXGK_ADAPTER_PERFDATACAPS** structure in response to a [**DXGK_QUERYADAPTERINFOTYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_queryadapterinfotype) query of type **DXGKQAITYPE_ADAPTERPERFDATA_CAPS**.

## See also

[**DXGK_QUERYADAPTERINFOTYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_queryadapterinfotype)

[**DxgkDdiQueryAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo)