NTSTATUS AcxObjectBagRetrieveMultiString(
  ACXOBJECTBAG           ObjectBag,
  PCUNICODE_STRING       ValueName,
  PWDF_OBJECT_ATTRIBUTES StringsAttributes,
  WDFCOLLECTION          Values
);