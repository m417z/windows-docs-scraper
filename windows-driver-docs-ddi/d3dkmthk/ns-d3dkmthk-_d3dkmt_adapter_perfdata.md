# _D3DKMT_ADAPTER_PERFDATA structure

## Description

Contains input arguments for the [D3DKMTQueryAdapterInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtqueryadapterinfo) function. Represents performance data collected per adapter on an interval basis.

## Members

### `PhysicalAdapterIndex`

The physical adapter index in the LDA (linked display adapter) chain.

### `MemoryFrequency`

Clock frequency of the memory, represented in hertz.

### `MaxMemoryFrequency`

Max clock frequency of the memory while not overclocked, represented in hertz.

### `MaxMemoryFrequencyOC`

Max clock frequency of the memory while overclocked, represented in hertz.

### `MemoryBandwidth`

– Amount of total memory transferred in bytes.

### `PCIEBandwidth`

Amount of total memory transferred over the PCIE in bytes.

### `FanRPM`

The current rpm of the main fan.

### `Power`

The current power draw of the adapter in tenths of percentage, 1 = 0.1%.

### `Temperature`

The main temperature sensors reading in decimal Celsius. 1 = 0.1C.

### `PowerStateOverride`

Reports if the GPU is powered on with 1 otherwise it is 0.