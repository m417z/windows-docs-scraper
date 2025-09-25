# _ReportDiscoveredTargets2_OUT structure

## Description

The ReportDiscoveredTargets2_OUT structure holds the output data for the [ReportDiscoveredTargets2](https://learn.microsoft.com/windows-hardware/drivers/storage/reportdiscoveredtargets2) method.

## Members

### `Status`

On output, the status of the **ReportDiscoveredTargets** operation. For a list of status qualifiers, see [ISCSI_STATUS_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-status-qualifiers).

### `TargetCount`

On output, the number of targets that are discovered.

### `Targets`

On output, an array of [ISCSI_DiscoveredTarget2](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsifnd/ns-iscsifnd-_iscsi_discoveredtarget2) structures, which provide information that is related to discovered targets.

## Remarks

You must implement this method.

## See also

[ISCSI_DiscoveredTarget2](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsifnd/ns-iscsifnd-_iscsi_discoveredtarget2)

[ISCSI_STATUS_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-status-qualifiers)

[ReportDiscoveredTargets2](https://learn.microsoft.com/windows-hardware/drivers/storage/reportdiscoveredtargets2)