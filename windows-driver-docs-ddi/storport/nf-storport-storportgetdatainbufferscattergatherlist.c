ULONG StorPortGetDataInBufferScatterGatherList(
  [in]  PVOID                     HwDeviceExtension,
  [in]  PSCSI_REQUEST_BLOCK       Srb,
  [out] PSTOR_SCATTER_GATHER_LIST *SgList
);