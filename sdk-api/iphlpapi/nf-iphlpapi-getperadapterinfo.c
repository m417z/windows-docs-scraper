IPHLPAPI_DLL_LINKAGE DWORD GetPerAdapterInfo(
  [in]  ULONG                IfIndex,
  [out] PIP_PER_ADAPTER_INFO pPerAdapterInfo,
  [in]  PULONG               pOutBufLen
);