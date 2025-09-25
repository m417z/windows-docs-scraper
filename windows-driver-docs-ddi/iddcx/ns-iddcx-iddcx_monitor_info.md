# IDDCX_MONITOR_INFO structure

## Description

Gives information about the current monitor and its connection type.

## Members

### `Size`

 Total size of the structure

### `MonitorType`

The monitor connector type of the monitor

### `ConnectorIndex`

 This is a zero-based unique identifier for this connector. It should be unique for this adapter and the value should not change for this connector across system reboot or driver upgrade.

**Note** The value has to be between 0 and the [IDDCX_ADAPTER_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_adapter_caps) value MaxMonitorsSupported minus 1.

### `MonitorDescription`

 Pointer to the monitor description for the monitor. If the monitor does not have any description data, this should be set to NULL

### `MonitorContainerId`

 Container Id of the monitor being connected. If any device is also inside the monitor (eg audio, touch etc), then those devices should all have the same container id.