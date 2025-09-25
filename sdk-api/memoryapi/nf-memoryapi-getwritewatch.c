UINT GetWriteWatch(
  [in]      DWORD     dwFlags,
  [in]      PVOID     lpBaseAddress,
  [in]      SIZE_T    dwRegionSize,
  [out]     PVOID     *lpAddresses,
  [in, out] ULONG_PTR *lpdwCount,
  [out]     LPDWORD   lpdwGranularity
);