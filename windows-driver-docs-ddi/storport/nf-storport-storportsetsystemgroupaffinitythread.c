ULONG StorPortSetSystemGroupAffinityThread(
  [in]           PVOID                HwDeviceExtension,
  [in/optional]  PVOID                ThreadContext,
  [in]           PSTOR_GROUP_AFFINITY Affinity,
  [out/optional] PSTOR_GROUP_AFFINITY PreviousAffinity
);