WINSETUPAPI BOOL SetupCopyOEMInfA(
  [in]            PCSTR  SourceInfFileName,
  [in]            PCSTR  OEMSourceMediaLocation,
  [in]            DWORD  OEMSourceMediaType,
  [in]            DWORD  CopyStyle,
  [out, optional] PSTR   DestinationInfFileName,
  [in]            DWORD  DestinationInfFileNameSize,
  [out, optional] PDWORD RequiredSize,
  [out, optional] PSTR   *DestinationInfFileNameComponent
);