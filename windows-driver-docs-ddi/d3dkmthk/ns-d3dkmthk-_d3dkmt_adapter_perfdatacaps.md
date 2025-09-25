# D3DKMT_ADAPTER_PERFDATACAPS structure

## Description

The **D3DKMT_ADAPTER_PERFDATACAPS** structure represents data capabilities that are static and queried once per GPU during initialization.

## Members

### `PhysicalAdapterIndex`

The physical adapter index in the LDA (linked display adapter) chain.

### `MaxMemoryBandwidth`

Max memory bandwidth in bytes for 1 second.

### `MaxPCIEBandwidth`

Max PCIE bandwidth in bytes for 1 second.

### `MaxFanRPM`

The max fan rpm of the main fan.

### `TemperatureMax`

The max temperature before damage levels occur in deci Celsius. 1 = 0.1C.

### `TemperatureWarning`

The temperature level where temperature based throttling begins in deci Celsius. 1 = 0.1C.

## See also

[**D3DKMT_QUERYSTATISTICS_PHYSICAL_ADAPTER_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-d3dkmt_querystatistics_physical_adapter_information)