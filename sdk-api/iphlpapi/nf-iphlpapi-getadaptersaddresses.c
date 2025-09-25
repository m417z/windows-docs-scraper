IPHLPAPI_DLL_LINKAGE ULONG GetAdaptersAddresses(
  [in]      ULONG                 Family,
  [in]      ULONG                 Flags,
  [in]      PVOID                 Reserved,
  [in, out] PIP_ADAPTER_ADDRESSES AdapterAddresses,
  [in, out] PULONG                SizePointer
);