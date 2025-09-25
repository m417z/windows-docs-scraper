# DXGK_CONNECTION_STATUS enumeration

## Description

Enumeration indicating the connection status values which can be reported.

## Constants

### `ConnectionStatusUninitialized`

Indicates that a variable of type DXGK_CONNECTION_STATUS has not yet been assigned a meaningful value.

### `TargetStatusDisconnected`

Indicates that a target has been disconnected. This implies that any other targets or monitors which are connected via this target have also been removed. The implied removals do not need to be reported to the OS separately as the OS will comprehend that they have also been removed. For joined targets, even though each constituent target must be reported, the disconnect is identified by the target which has gone away so only one report is required.

### `TargetStatusConnected`

Indicates that a new target has been detected. The new target is downstream, a child, of the original target. The new target Id must be unique.

### `TargetStatusJoined`

Indicates that a new target has been detected and that multiple targets are being joined together to form this new target. Each target being joined together must be indicated to the OS with a DXGK_CONNECTION_CHANGE and all target join indications for a new target must be indicated within a single batch.

### `MonitorStatusDisconnected`

Indicates that the monitor has been disconnected.

### `MonitorStatusUnknown`

Indicates that the driver cannot detect if a monitor is connected to the target and that the driver can support sending a valid timing to the target. This is only valid for analog targets.

### `MonitorStatusConnected`

Indicates that a monitor has been detected.

### `LinkConfigurationStarted`

Indicates that link configuration is occurring on the specified target.

If the target was enabled, then scan-out of pixels has stopped and any pending v-blank interrupts should be assumed to be lost as if the monitor had been disconnected.

If the target was not enabled, then there is no impact on this target. Any targets daisy-chained downstream from the specified target need to be notified to the OS as in configuration separately. Although the OS comprehends daisy-chaining, configuration is link generic so the OS does not attempt to infer the link configuration status of downstream devices.

### `LinkConfigurationFailed`

Indicates that link configuration has failed so the OS will need to retry SetTimingsFromVidPn after re-enumerating co-functional timings in order to find out the timings available based on the now completed configuration.

### `LinkConfigurationSucceeded`

Indicates that link configuration has completed successfully and that the requested display timing is active.

If the target was previously enabled, then scan-out of pixels has resumed. The OS will respond by turning v-blank interrupts back on and resuming flips as needed.

## Remarks

Other than the uninitialized state, the values fall into three categories: target changes, monitor changes and link configuration changes. Target changes represent the addition and removal of targets; monitor changes report the connection status of monitors which are attached to targets and link configuration changes report the status of the link to a monitor.