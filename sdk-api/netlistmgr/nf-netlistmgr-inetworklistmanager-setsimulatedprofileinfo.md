# INetworkListManager::SetSimulatedProfileInfo

## Description

The **SetSimulatedProfileInfo** method applies a specific set of connection profile values to the internet connection profile in support of the simulation of specific metered internet connection conditions.

The simulation only applies in an RDP Child Session and does not affect the primary user session. The simulated internet connection profile is returned via the Windows Runtime API [GetInternetConnectionProfile](https://learn.microsoft.com/uwp/api/windows.networking.connectivity.networkinformation.getinternetconnectionprofile).

## Parameters

### `pSimulatedInfo`

Specific connection profile values to simulate on the current internet connection profile when calling [GetInternetConnectionProfile](https://learn.microsoft.com/uwp/api/windows.networking.connectivity.networkinformation.getinternetconnectionprofile) from an RDP Child Session

## Return value

Returns S_OK on success.

## See also

[Child Sessions (Windows)](https://learn.microsoft.com/windows/desktop/TermServ/child-sessions)

[ClearSimulatedProfileInfo](https://learn.microsoft.com/windows/desktop/api/netlistmgr/nf-netlistmgr-inetworklistmanager-clearsimulatedprofileinfo)

[INetworkListManager](https://learn.microsoft.com/windows/desktop/api/netlistmgr/nn-netlistmgr-inetworklistmanager)

[NLM_SIMULATED_PROFILE_INFO](https://learn.microsoft.com/windows/desktop/api/netlistmgr/ns-netlistmgr-nlm_simulated_profile_info)