IPHLPAPI_DLL_LINKAGE _NETIOAPI_SUCCESS_ NETIOAPI_API GetNetworkInformation(
  [in]  const NET_IF_NETWORK_GUID *NetworkGuid,
  [out] PNET_IF_COMPARTMENT_ID    CompartmentId,
  [out] PULONG                    SiteId,
  [out] PWCHAR                    NetworkName,
  [in]  ULONG                     Length
);