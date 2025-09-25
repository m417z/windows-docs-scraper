NTSYSAPI BOOLEAN RtlInsertUnicodePrefix(
  [in]  PUNICODE_PREFIX_TABLE            PrefixTable,
  [in]  __drv_aliasesMem PUNICODE_STRING Prefix,
  [out] PUNICODE_PREFIX_TABLE_ENTRY      PrefixTableEntry
);