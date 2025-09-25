# _PC_EXIT_LATENCY enumeration

## Description

This topic discusses the PC_EXIT_LATENCY enum, and describes its members. The latency times map to specific maximum times in which the device must be able to exit its sleep state and enter the fully functional state (D0).

## Constants

### `PcExitLatencyInstant`

Indicates a 0-millisecond latency. This means "Do not power down" and it will only be sent when a device is in the D0 state.

### `PcExitLatencyFast`

Indicates a 35-millisecond resume latency.

### `PcExitLatencyResponsive`

Indicates a 300-millisecond resume latency.