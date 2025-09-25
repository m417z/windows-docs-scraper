# _D3DKMT_NODE_PERFDATA structure

## Description

Represents performance data collected per engine from an adapter on an interval basis.

## Members

### `NodeOrdinal` [in]

Node ordinal of the requested engine.

### `PhysicalAdapterIndex` [in]

The physical adapter index in the LDA (linked display adapter) chain.

### `Frequency` [out]

Clock frequency of the requested engine, represented in hertz.

### `MaxFrequency` [out]

The max frequency the engine can normally reach in hertz while not overclocked.

### `MaxFrequencyOC` [out]

The max frequency the engine can reach with it's current overclock in hertz.

### `Voltage` [out]

Voltage of the requested engine, represented in milli volts.

### `VoltageMax` [out]

The max voltage of the engine in milli volts while not overclocked.

### `VoltageMaxOC` [out]

The max voltage of the engine while overclocked in milli volts.

### `MaxTransitionLatency` [out]

The max transition latency to change the frequency, in 100 nanoseconds.

### `Reserved`

Reserved