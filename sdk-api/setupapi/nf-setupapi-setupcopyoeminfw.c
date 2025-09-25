WINSETUPAPI BOOL SetupCopyOEMInfW(
  [in]            PCWSTR SourceInfFileName,
  [in]            PCWSTR OEMSourceMediaLocation,
  [in]            DWORD  OEMSourceMediaType,
  [in]            DWORD  CopyStyle,
  [out, optional] PWSTR  DestinationInfFileName,
  [in]            DWORD  DestinationInfFileNameSize,
  [out, optional] PDWORD RequiredSize,
  [out, optional] PWSTR  *DestinationInfFileNameComponent
);