IPHLPAPI_DLL_LINKAGE _NETIOAPI_SUCCESS_ NETIOAPI_API SetNetworkInformation(
  [in] const NET_IF_NETWORK_GUID *NetworkGuid,
  [in] NET_IF_COMPARTMENT_ID     CompartmentId,
  [in] const WCHAR               *NetworkName
);