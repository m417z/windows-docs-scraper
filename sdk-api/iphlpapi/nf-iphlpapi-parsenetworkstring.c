IPHLPAPI_DLL_LINKAGE DWORD ParseNetworkString(
  [in]            const WCHAR       *NetworkString,
  [in]            DWORD             Types,
  [out, optional] PNET_ADDRESS_INFO AddressInfo,
  [out, optional] USHORT            *PortNumber,
  [out, optional] BYTE              *PrefixLength
);