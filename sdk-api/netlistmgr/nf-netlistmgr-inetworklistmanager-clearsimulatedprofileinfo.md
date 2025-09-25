# INetworkListManager::ClearSimulatedProfileInfo

## Description

Clears the connection profile values previously applied to the internet connection profile by [SetSimulatedProfileInfo](https://learn.microsoft.com/windows/desktop/api/netlistmgr/nf-netlistmgr-inetworklistmanager-setsimulatedprofileinfo). The next internet connection query, via [GetInternetConnectionProfile](https://learn.microsoft.com/uwp/api/windows.networking.connectivity.networkinformation.getinternetconnectionprofile), will use system information.

## Return value

Returns S_OK on success.

## See also

[INetworkListManager](https://learn.microsoft.com/windows/desktop/api/netlistmgr/nn-netlistmgr-inetworklistmanager)

[SetSimulatedProfileInfo](https://learn.microsoft.com/windows/desktop/api/netlistmgr/nf-netlistmgr-inetworklistmanager-setsimulatedprofileinfo)