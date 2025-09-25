# _AddTarget_IN structure

## Description

The AddPort_IN structure is used by a WMI client to deliver the input parameter data of the [AddTarget](https://learn.microsoft.com/windows-hardware/drivers/storage/addtarget) WMI method to the HBA miniport driver.

## Members

### `HbaPortWWN`

Contains the worldwide name of the local port whose events the WMI client will receive.

### `DiscoveredPortWWN`

Contains a worldwide name that specifies the discovered target whose events the WMI client will receive.

### `AllTargets`

Indicates the scope of the target events to report. If this member is zero, the WMI client will receive events associated with the port that is indicated by *DiscoveredPortWWN*. If this member is nonzero, the WMI client will all events associated with all currently discovered targets as well as targets that are discovered in the future.

## See also

[AddTarget](https://learn.microsoft.com/windows-hardware/drivers/storage/addtarget)