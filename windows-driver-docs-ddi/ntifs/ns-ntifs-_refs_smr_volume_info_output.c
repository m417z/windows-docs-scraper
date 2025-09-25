typedef struct _REFS_SMR_VOLUME_INFO_OUTPUT {
  ULONG                    Version;
  ULONG                    Flags;
  LARGE_INTEGER            SizeOfRandomlyWritableTier;
  LARGE_INTEGER            FreeSpaceInRandomlyWritableTier;
  LARGE_INTEGER            SizeofSMRTier;
  LARGE_INTEGER            FreeSpaceInSMRTier;
  LARGE_INTEGER            UsableFreeSpaceInSMRTier;
  REFS_SMR_VOLUME_GC_STATE VolumeGcState;
  NTSTATUS                 VolumeGcLastStatus;
  ULONG                    CurrentGcBandFillPercentage;
  ULONGLONG                Unused[6];
} REFS_SMR_VOLUME_INFO_OUTPUT, *PREFS_SMR_VOLUME_INFO_OUTPUT;