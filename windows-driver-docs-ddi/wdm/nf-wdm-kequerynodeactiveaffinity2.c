NTSTATUS KeQueryNodeActiveAffinity2(
  [in]  USHORT          NodeNumber,
  [out] PGROUP_AFFINITY GroupAffinities,
  [in]  USHORT          GroupAffinitiesCount,
  [out] PUSHORT         GroupAffinitiesRequired
);