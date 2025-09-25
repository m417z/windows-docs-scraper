BOOL SetThreadGroupAffinity(
  [in]            HANDLE               hThread,
  [in]            const GROUP_AFFINITY *GroupAffinity,
  [out, optional] PGROUP_AFFINITY      PreviousGroupAffinity
);