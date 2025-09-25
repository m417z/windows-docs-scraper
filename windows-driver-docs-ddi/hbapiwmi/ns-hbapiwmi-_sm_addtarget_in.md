# _SM_AddTarget_IN structure

## Description

The SM_AddTarget_IN structure is used to provide input parameters to the SM_AddTarget WMI method.

## Members

### `HbaPortWWN`

The worldwide name (WWN) of the local port whose events the WMI client will receive.

### `DiscoveredPortWWN`

A worldwide name (WWN) that specifies the discovered target whose events the WMI client will receive.

### `DomainPortWWN`

A worldwide name (WWN) that specifies the SAS domain worldwide name of the local port.

### `AllTargets`

The scope of the target events to report. If this member is zero, the WMI client will receive events that are associated with the port that is indicated by DiscoveredPortWWN. If this member is nonzero, the WMI client will receive events that are associated with all currently discovered targets as well as targets that are discovered in the future.