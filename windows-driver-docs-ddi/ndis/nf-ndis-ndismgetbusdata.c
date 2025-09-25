ULONG NdisMGetBusData(
        NDIS_HANDLE NdisMiniportHandle,
  [in]  ULONG       WhichSpace,
  [in]  ULONG       Offset,
  [out] PVOID       Buffer,
  [in]  ULONG       Length
);