LSA_CRACK_SINGLE_NAME LsaCrackSingleName;

NTSTATUS LsaCrackSingleName(
  [in]           ULONG FormatOffered,
  [in]           BOOLEAN PerformAtGC,
  [in]           PUNICODE_STRING NameInput,
  [in, optional] PUNICODE_STRING Prefix,
  [in]           ULONG RequestedFormat,
  [out]          PUNICODE_STRING CrackedName,
  [out]          PUNICODE_STRING DnsDomainName,
  [out]          PULONG SubStatus
)
{...}