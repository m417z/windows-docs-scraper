BOOL GetProcessDefaultCpuSetMasks(
  HANDLE          Process,
  PGROUP_AFFINITY CpuSetMasks,
  USHORT          CpuSetMaskCount,
  PUSHORT         RequiredMaskCount
);