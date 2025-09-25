PVOID RxPrefixTableLookupName(
  [in]  IN PRX_PREFIX_TABLE  ThisTable,
  [in]  IN PUNICODE_STRING   CanonicalName,
  [out] OUT PUNICODE_STRING  RemainingName,
        IN PRX_CONNECTION_ID ConnectionId
);