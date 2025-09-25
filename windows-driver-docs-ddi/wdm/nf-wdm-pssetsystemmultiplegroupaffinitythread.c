NTSTATUS PsSetSystemMultipleGroupAffinityThread(
  [in]      PGROUP_AFFINITY GroupAffinities,
  [in]      USHORT          GroupCount,
  [in, out] PAFFINITY_TOKEN AffinityToken
);