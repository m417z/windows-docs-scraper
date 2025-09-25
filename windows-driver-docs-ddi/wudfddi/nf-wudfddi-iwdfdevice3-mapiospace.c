HRESULT MapIoSpace(
  [in]  PHYSICAL_ADDRESS    PhysicalAddress,
  [in]  SIZE_T              NumberOfBytes,
  [in]  MEMORY_CACHING_TYPE CacheType,
  [out] void                **pPseudoBaseAddress
);