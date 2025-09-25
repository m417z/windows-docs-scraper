# NLM_SIMULATED_PROFILE_INFO structure

## Description

Used to specify values that are used by [SetSimulatedProfileInfo](https://learn.microsoft.com/windows/desktop/api/netlistmgr/nf-netlistmgr-inetworklistmanager-setsimulatedprofileinfo) to override current internet connection profile values in an RDP Child Session to support the simulation of specific metered internet connection conditions.

## Members

### `ProfileName`

Name for the simulated profile.

### `cost`

The network cost. Possible values are defined by [NLM_CONNECTION_COST](https://learn.microsoft.com/windows/desktop/api/netlistmgr/ne-netlistmgr-nlm_connection_cost).

### `UsageInMegabytes`

The data usage.

### `DataLimitInMegabytes`

The data limit of the plan.

## See also

[Child Sessions (Windows)](https://learn.microsoft.com/windows/desktop/TermServ/child-sessions)

[ClearSimulatedProfileInfo](https://learn.microsoft.com/windows/desktop/api/netlistmgr/nf-netlistmgr-inetworklistmanager-clearsimulatedprofileinfo)

[SetSimulatedProfileInfo](https://learn.microsoft.com/windows/desktop/api/netlistmgr/nf-netlistmgr-inetworklistmanager-setsimulatedprofileinfo)