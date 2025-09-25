# _ReportDiscoveredTargets_OUT structure

## Description

The ReportDiscoveredTargets_OUT structure holds the output data for the [ReportDiscoveredTargets](https://learn.microsoft.com/windows-hardware/drivers/storage/reportdiscoveredtargets) method.

## Members

### `Status`

On output, the status of the **ReportDiscoveredTargets** operation. For a list of status qualifiers, see [ISCSI_STATUS_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-status-qualifiers).

### `TargetCount`

On output, the number of targets that are discovered.

### `Targets`

On output, an array of [ISCSI_DiscoveredTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsifnd/ns-iscsifnd-_iscsi_discoveredtarget) structures, which provide information that is related to discovered targets.

## Remarks

You must implement this method.

## See also

[ISCSI_DiscoveredTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsifnd/ns-iscsifnd-_iscsi_discoveredtarget)

[ISCSI_STATUS_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-status-qualifiers)

[ReportDiscoveredTargets](https://learn.microsoft.com/windows-hardware/drivers/storage/reportdiscoveredtargets)

[ReportDiscoveredTargets2_OUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsifnd/ns-iscsifnd-_reportdiscoveredtargets2_out)