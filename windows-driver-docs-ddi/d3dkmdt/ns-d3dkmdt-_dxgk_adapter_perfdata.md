# _DXGK_ADAPTER_PERFDATA structure

## Description

Contains the display adapter performance data.

## Members

### `MemoryFrequency`

Clock frequency of the requested engine, represented in hertz.

### `MaxMemoryFrequency`

Max clock frequency of the memory while not overclocked, represented in hertz.

### `MaxMemoryFrequencyOC`

The max frequency the engine can reach with it’s current overclock in hertz.

### `MemoryBandwidth`

Amount of total memory transferred in bytes.

### `PCIEBandwidth`

Amount of total memory transferred over the PCIE in bytes.

### `FanRPM`

The current rpm of the main fan.

### `Power`

The current power draw of the adapter in tenths of percentage, 1 = 0.1%.

### `Temperature`

The main temperature sensors reading in decimal Celsius. 1 = 0.1C.

### `PowerStateOverride`

Reports if the GPU is powered on with 1 otherwise it is 0. This overrides dxgkrnl’s adapter level view for a better understanding of each physical GPU that are linked together.