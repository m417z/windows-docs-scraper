TDHSTATUS TdhEnumerateProviderFilters(
  [in]            LPGUID                Guid,
  [in]            ULONG                 TdhContextCount,
  [in, optional]  PTDH_CONTEXT          TdhContext,
  [in]            ULONG                 *FilterCount,
  [out, optional] PPROVIDER_FILTER_INFO *Buffer,
  [in, out]       ULONG                 *BufferSize
);