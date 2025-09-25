ULONG StorPortNvmeIceIoStart(
  PVOID               HwDeviceExtension,
  PSCSI_REQUEST_BLOCK Srb,
  ULONG               LbaCount,
  ULONG               PrpCount,
  PULONGLONG          Prp1,
  PULONGLONG          Prp2,
  PULONGLONG          PrpList
);