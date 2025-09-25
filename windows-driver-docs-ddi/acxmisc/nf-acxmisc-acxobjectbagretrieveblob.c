NTSTATUS AcxObjectBagRetrieveBlob(
  ACXOBJECTBAG           ObjectBag,
  PCUNICODE_STRING       ValueName,
  PWDF_OBJECT_ATTRIBUTES ValueAttributes,
  WDFMEMORY              *Value
);