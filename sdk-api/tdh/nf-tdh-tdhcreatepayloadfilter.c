TDHSTATUS TdhCreatePayloadFilter(
  [in]  LPCGUID                   ProviderGuid,
  [in]  PCEVENT_DESCRIPTOR        EventDescriptor,
  [in]  BOOLEAN                   EventMatchANY,
  [in]  ULONG                     PayloadPredicateCount,
  [in]  PPAYLOAD_FILTER_PREDICATE PayloadPredicates,
  [out] PVOID                     *PayloadFilter
);