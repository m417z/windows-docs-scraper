NTSYSAPI PVOID RtlEnumerateGenericTableLikeADirectory(
  [in]           PRTL_AVL_TABLE          Table,
  [in, optional] PRTL_AVL_MATCH_FUNCTION MatchFunction,
  [in, optional] PVOID                   MatchData,
  [in]           ULONG                   NextFlag,
  [in, out]      PVOID                   *RestartKey,
  [in, out]      PULONG                  DeleteCount,
  [in]           PVOID                   Buffer
);