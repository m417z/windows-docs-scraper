NTSTATUS WdfRegistryQueryMultiString(
  [in]           WDFKEY                 Key,
  [in]           PCUNICODE_STRING       ValueName,
  [in, optional] PWDF_OBJECT_ATTRIBUTES StringsAttributes,
  [in]           WDFCOLLECTION          Collection
);