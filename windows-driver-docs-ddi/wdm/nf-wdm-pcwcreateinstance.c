NTSTATUS PcwCreateInstance(
  [out] PPCW_INSTANCE     *Instance,
  [in]  PPCW_REGISTRATION Registration,
  [in]  PCUNICODE_STRING  Name,
  [in]  ULONG             Count,
  [in]  PPCW_DATA         Data
);